#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

ring_buffer *init_buffer(const size_t n, void (*f)(void *p)) {
    ring_buffer *rb = (ring_buffer *) malloc(sizeof(ring_buffer));
    if (rb == NULL) {
        printf("FEHLER");
        exit(0);
    }

    rb->size = n;

    rb->count = 0;
    rb->head = 0;
    rb->elems = (void *) malloc(n * sizeof(void *));
    rb->free_callback = f;
    return rb;
}

void free_callback(void *p) {
    free(p);
    p = NULL;
}

void *read_buffer(ring_buffer *cb) {
    if (cb->count == 0) {
        return NULL;
    }

    void *firstelement = cb->elems[cb->head];
    cb->head++;
    cb->count--;
    return firstelement;
}

void write_buffer(ring_buffer *cb, void *data) {
    if (cb->count < cb->size) {
        cb->elems[(cb->count + cb->head) % cb->size] = data;
        cb->count++;
    } else {
        cb->free_callback(cb->elems[cb->head]);
        cb->elems[cb->head] = data;
        cb->head++;

    }
}

int free_buffer(ring_buffer *cb) {
    for (int i = 0; i < cb->count; i++) {
        //TODO
    }

    free(cb);
    return 1;
}

int main() {
    void (*fc)(void *p);

    int *ptr1 = (int *) malloc(sizeof(int));
    int *ptr2 = (int *) malloc(sizeof(int));
    int *ptr3 = (int *) malloc(sizeof(int));
    int *ptr4 = (int *) malloc(sizeof(int));
    int *ptr5 = (int *) malloc(sizeof(int));
    int *ptr6 = (int *) malloc(sizeof(int));
    *ptr1 = 1;
    *ptr2 = 2;
    *ptr3 = 3;
    *ptr4 = 4;
    *ptr5 = 5;
    *ptr6 = 6;

    fc = free_callback;
    ring_buffer *ringB = init_buffer(4, fc);

    write_buffer(ringB, ptr1);

    write_buffer(ringB, ptr2);
    write_buffer(ringB, ptr3);
    write_buffer(ringB, ptr4);
    read_buffer(ringB);

    return  0;
}