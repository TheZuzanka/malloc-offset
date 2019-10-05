// Created by Susanka on 04/10/2019.

#include "header.h"

int memory_check(void *ptr) {
    //adresa zaciatku + celkova velkost + kde zacina prvy, tie su rezerovane
    //celkova velkost = memory[0]
    //konecna adresa memory[last]

    void* starting_adress = (memory + 2* sizeof(int));
    int total_size = *((int*)(memory));
    void* last_adress = (memory + total_size* sizeof(char));


    if ((ptr > starting_adress) && (ptr <=  last_adress) && !is_free(ptr)) {
        return 1;
        //zaporne cislo = zabrate (najvyssi bit 1) --> bolo alokovane & nebolo uvolnene
    } else {
        return 0;
        //kladne cislo = volne (najvyssi bit 0) --> uz bolo uvolnene/ ani nebolo alokovane
    }
}