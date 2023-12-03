#include "stdio.h"


#ifndef QUEUE_H
#define QUEUE_H


typedef struct{
    size_t size, count, head;
    void **elems;
    void (*free_callback)(void *p);
}ring_buffer;

ring_buffer *init_buffer(const size_t n, void (*f)(void *p));
void write_buffer(ring_buffer *cb, void *data);
void *read_buffer(ring_buffer *cb);
void free_callback(void*);
int free_buffer(ring_buffer *cb);

# endif