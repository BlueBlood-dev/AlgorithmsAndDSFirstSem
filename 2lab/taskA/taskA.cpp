#include <iostream>
#include <fstream>

using namespace std;

void merge(int array[], int firstIndex, int m, int lastIndex) {
    int x,y,z;
    int firstHalfIndex = m - firstIndex + 1;
    int secondHalfIndex = lastIndex - m;
    int firstHalf[firstHalfIndex];
    int secondHalf[secondHalfIndex];
    for (x = 0; x < firstHalfIndex; x++)
        firstHalf[x] = array[firstIndex + x];
    for (y = 0; y < secondHalfIndex; y++)
        secondHalf[y] = array[m + 1 + y];

    x = 0;
    y = 0;
    z = firstIndex;

    while (x < firstHalfIndex && y < secondHalfIndex) {
        if (firstHalf[x] <= secondHalf[y]) {
            array[z] = firstHalf[x];
            x++;
        } else {
            array[z] = secondHalf[y];
            y++;
        }
        z++;
    }
    while (x < firstHalfIndex) {
        array[z] = firstHalf[x];
        x++;
        z++;
    }
    while (y < secondHalfIndex) {
        array[z] = secondHalf[y];
        y++;
        z++;
    }
}

void mergeSort(int array[], int firstIndex, int lastIndex) {
    if (firstIndex < lastIndex) {
        int middleIndex = firstIndex + (lastIndex - firstIndex) / 2;
        mergeSort(array, firstIndex, middleIndex);
        mergeSort(array, middleIndex + 1, lastIndex);
        merge(array, firstIndex, middleIndex, lastIndex);
    }
}

int main() {
    int amount;
    ifstream fileIn("sort.in");
    ofstream fileOut("sort.out");
    fileIn >> amount;
    int *arr = new int[amount];
    for (int i = 0; i < amount; i++) {
        fileIn >> arr[i];
    }
    mergeSort(arr, 0, amount - 1);
    for (int i = 0; i < amount; i++) {
        fileOut << arr[i] << " ";
    }
    fileIn.close();
    fileOut.close();
    return 0;
}
