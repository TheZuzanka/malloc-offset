// Created by Susanka on 04/10/2019.

#ifndef DSA_1_PROJEKT_OFFSET_HEADER_H
#define DSA_1_PROJEKT_OFFSET_HEADER_H

#endif //DSA_1_PROJEKT_OFFSET_HEADER_H

#include <stdio.h>
#include <limits.h>
#include <math.h>

void* memory;

//cyklicky linked list nepotrebuje referenciu na predchadzajuceho
typedef struct header{
    int size;
    struct header* next;
}HEADER;

typedef struct initial_block{
    HEADER* first_blok;
    void* end;
}INITIAL_BLOCK;



//from memory_alloc.c
void *memory_alloc(unsigned int size);
void *find_free_block(void *memory_list, unsigned int size);
void cut_memory(void *header, unsigned int requested_size);

//from memory_free.c
int memory_free(void *valid_ptr);

//from memory_check.c
int memory_check(void *ptr);

//from memory_init.c
void memory_init(void *ptr, unsigned int size);

//from extra_functions
short is_free(void* p_memblock);
short is_free_haedar(void* p_memblock);
int get_size_from_header(void* memblock);
void* find_my_previous(void* me);
