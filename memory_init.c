// Created by Susanka on 04/10/2019.

#include "header.h"

void memory_init(void *ptr, unsigned int size) {

    memory = ptr;

    //na nulte miesto napisem celkovu velkost pamate, na prve offsssset od zaciatku k prvemu prazdnemu
    //|100||||||
    *(unsigned int*)memory = size;
    *((int*)(memory + sizeof(int))) = (int)(memory + 2 * sizeof(int));

    //vytvorim jeden velky blok volnej pamate, pointer na dalsi nastavim na 0
    *((int*)(memory + 2* sizeof(int))) = (int)(memory + 2* sizeof(int));

    //nastavim velkost zvysnej pamate celkova-velkost "hlaviciek"
    int free_size = size - 4 * sizeof(int);
    *((int*)(memory + 3*sizeof(int))) = free_size;
}


