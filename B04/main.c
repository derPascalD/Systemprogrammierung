#include "stdio.h"
#include "stdlib.h"
#include "speicherverwaltung.h"

#ifdef MALLOCSPLIT
#define SPLIT 1
#else
#define SPLIT 0
#endif

memblock *freemem = NULL;
char mempool[MEM_POOL_SIZE];

int cm_init(void){

    // keine globale Variable
    static int check = 0;

    if(check){
        return 0;
    }

    freemem = (memblock *) mempool;
    freemem->id = 0;
    freemem->size = sizeof(mempool) - sizeof (memblock); // Länge des Blocks
    freemem->next = NULL;

    if(freemem == NULL){
        return  -1;
    }

    check = 1;
    return 1;
}

void *cm_malloc(size_t size){

    // fortlaufende Nummer
    static int number = 0;

    if(size == 0 || freemem == NULL){
        void *ptr = NULL;
        return ptr;
    }


    memblock *previous = NULL;
    memblock *freememClone = freemem;

    while(freememClone->size < size){

        if(freememClone->next == NULL){
            return NULL;
        }
        previous = freememClone;
        freememClone = freememClone->next;
    }

    if((size + 2 * sizeof(memblock) + 32) < freememClone->size && SPLIT){

        number++;
        memblock *newBlock;
        newBlock = (memblock *) ((char *) ((freememClone) + 1) + size);
        newBlock->id = number;
        newBlock->size = freememClone->size - size - sizeof (memblock);
        newBlock->next = freememClone->next;

        freememClone->size = size;
        freememClone->next = newBlock;
    }

    if(freememClone == freemem){
        freemem = freememClone->next;
        freememClone->next = (memblock *) MAGIC_INT;
    }else{
        previous->next = freememClone->next;
        freememClone->next = (memblock *) MAGIC_INT;
    }

    return (freememClone)+1;
}

void cm_free(void *ptr){

    if(ptr == NULL || ((memblock*) ptr -1)->next != MAGIC_INT ){
        printf("-----------------------------");
        return;
    }else{
        // 40
        ((memblock*) ptr -1)->next = freemem; // 4008
        freemem = ((memblock*) ptr -1);
    }
}

void print(){

    memblock * freememClone = freemem;

    while(freememClone != NULL){
        printf("id: %d \n",freememClone->id);
        freememClone = freememClone->next;
    }
}


int main(){

    cm_init();

    print();

    int *i = cm_malloc(sizeof(int));


    if(i != NULL){
        printf("GENOMMEN\n");
    }

    cm_free(i);

    print();

    double *f = cm_malloc(sizeof(double ));

    if(f == NULL){
        printf("Korrekt, da i den kompletten Speicher sich genommen hat");
    } else{
        printf("ICH HABS MIR JETZT GENOMMEN\n");
    }
    print();
    cm_free(f);
    print();

    // gcc -o Speicher main.c -DMALLOCSPLIT

    return 0;
}

