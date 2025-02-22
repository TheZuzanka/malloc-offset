#include "main.h"

#define MAX_MEMORY 100

int main() {
    void* pole = malloc(MAX_MEMORY * sizeof(char));
    char* nines, *eights, *fives, *fours;
    unsigned int size1 = 10, size2 = 30, size3 = 28, size4 = 3;

    memset(pole, 0, MAX_MEMORY * sizeof(char));
    printf("Pamat na zaciatku:\n");
    print_arr(pole, MAX_MEMORY);

    memory_init(pole, MAX_MEMORY);
    printf("Pamat po memory_init:\n");
    print_arr(pole, MAX_MEMORY);

    nines = alloc_with_chcek(size1);
    for(int i = 0; i < size1; i++){
        nines[i] = 9;
    }
    printf("Pamat po alokaci prveho pola:\n");
    print_arr(pole, MAX_MEMORY);

    eights = alloc_with_chcek(size2);
    for(int i = 0; i < size2; i++){
        eights[i] = 8;
    }
    printf("Pamat po alokaci druheho pola:\n");
    print_arr(pole, MAX_MEMORY);

    fives = alloc_with_chcek(size3);
    for(int i = 0; i < size3; i++){
        fives[i] = 5;
    }
    printf("Pamat po alokaci tretieho pola:\n");
    print_arr(pole, MAX_MEMORY);

    fours = alloc_with_chcek(size4);
    for(int i = 0; i < size4; i++){
        fours[i] = 4;
    }
    printf("Pamat po alokaci stvrteho pola:\n");
    print_arr(pole, MAX_MEMORY);

    return 0;
}

void print_arr(char *array, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
        if (i % 4 == 3) {
            printf("|");
        }
    }
    printf("\n\n\n\n");
}

char *alloc_with_chcek(unsigned int size) {
    char *arr;
    if ((arr = memory_alloc(size)) == NULL) {
        printf("nedostatok pamate\n");
        exit(-1);
    }
    return arr;
}