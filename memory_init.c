// Created by Susanka on 04/10/2019.

#include "header.h"

void memory_init(void *ptr, unsigned int size) {

    memory = ptr;

    //memory[0] = celkova velkost pamate, memory[1] = adresa prveho volneho bloku
    //|100||||||
    *(unsigned int *) memory = size;
    *((int *) (memory + sizeof(int))) = (int) (memory + 2 * sizeof(int));

    //vytvorim jeden velky blok volnej pamate, pointer na dalsi nastavim na 0
    *((int *) (memory + 3 * sizeof(int))) = (int) (memory + 2 * sizeof(int));

    //nastavim velkost zvysnej pamate celkova-velkost "hlaviciek"
    int free_size = size - 4 * sizeof(int);
    *((int *) (memory + 2 * sizeof(int))) = free_size;
}


