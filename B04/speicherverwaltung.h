#include <stdio.h>

#ifndef SPEICHERVERWALTUNG_H
#define SPEICHERVERWALTUNG_H


#define MEM_POOL_SIZE 4096
#define MAGIC_INT 0xacdcacdc


typedef struct memblock {
    size_t size;            // Für User nutzbare Länge des Blocks [Bytes]
    struct memblock *next;  // Zeiger auf Anfang des nächsten freien Blocks (oder NULL)
    unsigned short id;      // Fortlaufende und eindeutige Nummer des Blockes
} memblock;

extern memblock* freemem;
extern char mempool[MEM_POOL_SIZE];


int cm_init(void);
void *cm_malloc(size_t size);
void cm_free(void *ptr);

#endif   /* SPEICHERVERWALTUNG_H */