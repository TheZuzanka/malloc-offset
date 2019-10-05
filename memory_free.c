// Created by Susanka on 05/10/2019.

#include "header.h"

int memory_free(void *valid_ptr) {

    void* to_header = (valid_ptr - sizeof(int));
    if( memory_check(to_header) == 1){
        return 1;
    }

    int size =  abs( *(int*)(to_header)  );
    *((int*)(to_header)) = size - sizeof(int);                //pridam pointer na dalsi blok, musim ubrat z pamate na data


    int test = size - sizeof(int);
    for(int i = 0; i < size - sizeof(int); i++){
        *(int*)(to_header + sizeof(int) + i) = 0;
    }
    return 0;
}

void merge_blocks(void *me) {
    void *next, *previous;
    void *aktual = me, *first = me;

    //prejdem cely zoznam volnych blokov a zistitm ci susedi s nejakym volnym

    do {
        int aktual_size = *(int*)(aktual);
        void* requeted_adress = (aktual + sizeof(int) + aktual_size * sizeof(char));
        //if( requeted_adress ==  )

        aktual = (void *) *(int*)(aktual + sizeof(int));
    } while (aktual != first);
}