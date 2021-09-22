#include <stdio.h>

int main() {
    int amount;
    FILE *inFile = fopen("smallsort.in", "r");
    FILE *outFile = fopen("smallsort.out", "w");

    fscanf(inFile, "%d", &amount);
    long long int arrayToSort[amount];

    for (int i = 0; i < amount; i++) {
        long long int variable;
        fscanf(inFile, "%lld", &variable);
        arrayToSort[i] = variable;
    }
    for (int i = 0; i<amount-1; i++){
        for(int j = 0; j<amount-i-1; j++){
            if(arrayToSort[j]>arrayToSort[j+1]){
                long long int temp = arrayToSort[j];
                arrayToSort[j] = arrayToSort[j+1];
                arrayToSort[j+1] = temp;
            }
        }
    }

    for (int i = 0; i < amount; i++)
        fprintf(outFile, "%lld ", arrayToSort[i]);

    fclose(inFile);
    fclose(outFile);
}