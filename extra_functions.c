// Created by Susanka on 04/10/2019.

#include "header.h"

int* move_to_block_size(void* p_data){
        return (int*)(p_data - sizeof(int));
}

short is_free(void* p_memblock){
    //vraciam pointer na HEADER NIE NA DATA!
    int size = *(move_to_block_size(p_memblock));
    if( size >= 0){
        return 1;
    }else
        return 0;
}

short is_free_haedar(void* p_memblock){
    int size = *((int*)(p_memblock + sizeof(int)));
    if( size >= 0){
        return 1;
    }else
        return 0;
}

int get_size_from_header(void* memblock){
    int *size = (int*)(memblock + sizeof(int));
    return *(size);
}

void* find_my_previous(void* me){
    void* aktual = me, *previous;

    do {
        //int to_next = ;
        previous = aktual;
        aktual = (int ) (aktual);

    } while (aktual != me);



    return previous;
}