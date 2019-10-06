// Created by Susanka on 05/10/2019.

#include "header.h"

int memory_free(void *valid_ptr) {

    void *to_header = (valid_ptr - sizeof(int));
    if (memory_check(to_header) == 0) {
        return 1;
    }

    int size = abs(*(int *) (to_header));
    *((int *) (to_header)) = size;                //pridam pointer na dalsi blok, musim ubrat z pamate na data
    //aktualne je size velkost pre data ssize-sizeof(int) ale ak si niek vypýta tuto pamat, pointer uz nebude treba


    for (int i = sizeof(int); i <= size - sizeof(int); i++) {
        *(int *) (to_header + sizeof(int) + i) = 0;
    }

    find_my_place(to_header);
    return 0;
}

void find_my_place(void *me) {
    void *first = (void *) *(int *) (memory + sizeof(int));
    void *aktual = me;

    do {
        void *m = (void *) *(int *) (memory + sizeof(int));   //adresa kam ukazuje memory[1]
        void *m2 = (void *) *(int *) (m + sizeof(int));       //adresa first->next
        if (m == m2) {
            if (me < first) {
                *(int *) (me + sizeof(int)) = (int) first;    //aktual->next = first
                *(int *) (memory + sizeof(int)) = (int) me;    //som prvy
                *(int *) (first + sizeof(int)) = (int) me;     //first->next = me
                return;
            } else {
                *(int *) (first + sizeof(int)) = (int) me;     //first->next = me
                *(int *) (me + sizeof(int)) = (int) first;
            }
        };

        if (me > aktual && me < (void *) *(int *) (aktual + sizeof(int))) {

            //me->next = aktual->next
            *(int *) (me + sizeof(int)) = *(int *) (aktual + sizeof(int));
            //aktual->next = me
            *(int *) (aktual + sizeof(int)) = (int) me;

            break;
        } else {
            aktual = (void *) *(int *) (aktual + sizeof(int));
        }

    } while (aktual != first);

}

//TODO toto bude sranda - spajanie blokov
void merge_blocks(void *me) {
    void *next, *previous;
    void *aktual = me, *first = me;

    //prejdem cely zoznam volnych blokov a zistitm ci susedi s nejakym volnym

    do {
        int aktual_size = *(int *) (aktual);
        void *requeted_adress = (aktual + sizeof(int) + aktual_size * sizeof(char));
        //if( requeted_adress ==  )

        aktual = (void *) *(int *) (aktual + sizeof(int));
    } while (aktual != first);
}