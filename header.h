// Created by Susanka on 04/10/2019.

#ifndef DSA_1_PROJEKT_OFFSET_HEADER_H
#define DSA_1_PROJEKT_OFFSET_HEADER_H

#endif //DSA_1_PROJEKT_OFFSET_HEADER_H

#include <stdio.h>
#include <limits.h>
#include <math.h>

void *memory;

//from memory_alloc.c
void *memory_alloc(unsigned int size);

void *find_free_block(void *memory_list, unsigned int size);

void cut_memory(void *header, unsigned int requested_size);

//from memory_free.c
int memory_free(void *valid_ptr);

void find_my_place(void *me);

void merge_blocks(void *me);

//from memory_check.c
int memory_check(void *ptr);

//from memory_init.c
void memory_init(void *ptr, unsigned int size);

//from extra_functions
short is_free_haedar(void *p_memblock);

int get_size_from_header(void *memblock);

void *find_my_previous(void *me);
