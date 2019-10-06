// Created by Susanka on 04/10/2019.

#include "header.h"

short is_free_haedar(void *p_memblock) {
    int size = *((int *) (p_memblock + sizeof(int)));
    if (size >= 0) {
        return 1;
    } else
        return 0;
}

int get_size_from_header(void *memblock) {
    int size = abs(*(int *)(memblock));
    return size;
}

void *find_my_previous(void *me) {
    void *aktual = me, *previous;

    do {
        previous = aktual;
        aktual = (void *) *(int *) (aktual + sizeof(int));

    } while (aktual != me);


    return previous;
}