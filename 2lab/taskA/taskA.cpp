#include <iostream>
#include <fstream>

using namespace std;

void merge(int array[], int firstIndex, int m, int lastIndex) {
    int x,y,z;
    int sub1 = m - firstIndex + 1;
    int sub2 = lastIndex - m;
    int first[sub1];
    int second[sub2];
    for (x = 0; x < sub1; x++)
        first[x] = array[firstIndex + x];
    for (y = 0; y < sub2; y++)
        second[y] = array[m + 1 + y];

    x = 0;
    y = 0;
    z = firstIndex;
    while (x < sub1 && y < sub2) {
        if (first[x] <= second[y]) {
            array[z] = first[x];
            x++;
        } else {
            array[z] = second[y];
            y++;
        }
        z++;
    }
    while (x < sub1) {
        array[z] = first[x];
        x++;
        z++;
    }
    while (y < sub2) {
        array[z] = second[y];
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
