// Created by Susanka on 04/10/2019.

#include "header.h"

void *memory_alloc(unsigned int size) {
    void *first_free_block = (void*)*((int*)(memory + sizeof(int)));

    //printf("next = %d\n", *((int *) (memory + (offset_to_next * sizeof(int)))));
    return find_free_block(first_free_block, size);
}

void *find_free_block(void *memory_list, unsigned int size) {
    void *aktual = memory_list, *first = memory_list;
    void *best_adress = NULL;
    int best_size = INT_MAX;

    int aktual_size;

    do {
        aktual_size = *((int *) (aktual + sizeof(int)));
        //printf("aktual->size = %d\n", aktual_size);
        if (is_free_haedar(aktual) && (aktual_size) >= size) {
            //printf("aktual->size = %d\n", aktual_size);

            if (aktual_size < best_size) {
                best_size = aktual_size;
                best_adress = aktual;
            }

        }
        aktual = (int*)(aktual);
        //printf("%d\n", *((int*)(memory + offset_to_next)));

    } while (aktual != first);

    //ak sa nenasiel ziadny blok, vrati sa povodna hdnota NULL ak hej, vrati sa best fit
    if (best_adress != NULL) {
        cut_memory(best_adress, size);

        //vraciam pointer priamo na data NIE NA HEADER!
        return best_adress + 2 * sizeof(int);
    } else {
        return NULL;
    }
}

void cut_memory(void *header, unsigned int requested_size) {

    int size_of_header = (2 * sizeof(int));                                   //"dalsi" + "size bloku"
    int free_memory = get_size_from_header(header) - requested_size - size_of_header;  //kolko ostane cistej pamate po useknuti
    void* new_block, *previous;

    previous = find_my_previous(header);
    //printf("previous size = %d\n", *((int*)(previous)));


    if(free_memory < 1){

        //nezmestia sa mi sem uz ziadne data, detekujem "zabrate" a neusekavam blok, lebo by ssa do neho potom nic nezmestilo
        //TODO * -1 cez bitovy posun
        *((int*)(header + sizeof(int))) *= -1;

        //new_block = header;
        *((int*)(previous)) = (int) header;
    } else{
        *((int*)(header + sizeof(int))) = requested_size * (-1);
        int my_size = *((int*)(header + sizeof(int)));
        //skratim blok a nastavim na alokovany

        new_block = header + 2* sizeof(int) + (requested_size * sizeof(char));

        //TODO predchadzajuci = co mi ukazuje na heaader?

        *((int*)(previous)) = (int)new_block;                //previous->next = new

        int to_header = *((int*)(header));
        *((int*)(new_block)) =  to_header;                  //new->next = header->next
        *((int*)(new_block + sizeof(int))) = free_memory;

        *(  (int*)(memory + sizeof(int))  ) = (int)new_block;
    }

}