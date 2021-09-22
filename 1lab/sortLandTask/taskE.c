#include <stdio.h>

int main() {
    int amount;
    FILE *fileIn = fopen("sortland.in", "r");
    FILE *fileOut = fopen("sortland.out", "w");

    fscanf(fileIn, "%d", &amount);
    float array[amount], arraySearch[amount];
    for (int i = 0; i < amount; i++) {
        float villager;
        fscanf(fileIn, "%f", &villager);
        array[i] = villager;
        arraySearch[i] = villager;
    }


    for (int i = 0; i < amount - 1; i++) {
        for (int j = 0; j < amount - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                float temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
    int indexOfPoor, indexOfMiddle, indexOfRich;
    float poor = array[0];
    float middle = array[(amount + 1) / 2 - 1];
    float rich = array[amount - 1];
    for (int i = 0; i < amount; i++) {
        if (arraySearch[i] == poor)indexOfPoor = i;
        if (arraySearch[i] == middle) indexOfMiddle = i;
        if (arraySearch[i] == rich) indexOfRich = i;
    }

    fprintf(fileOut, "%d %d %d", ++indexOfPoor, ++indexOfMiddle, ++indexOfRich);
    fclose(fileIn);
    fclose(fileOut);
}
