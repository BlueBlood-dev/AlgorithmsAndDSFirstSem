#include <iostream>
#include <fstream>

using namespace std;

void merge(int a[], int Firstindex, int m, int Lastindex); //merges the sub-arrays which are created while division

void mergeSort(int a[], int Firstindex, int Lastindex) {
    if (Firstindex < Lastindex) {
        int m = Firstindex + (Lastindex - Firstindex) / 2;
        mergeSort(a, Firstindex, m);
        mergeSort(a, m + 1, Lastindex);
        merge(a, Firstindex, m, Lastindex);
    }
}

void merge(int a[], int Firstindex, int m, int Lastindex) {
    int x;
    int y;
    int z;
    int sub1 = m - Firstindex + 1;
    int sub2 = Lastindex - m;
    int First[sub1];  //temp array
    int Second[sub2];
    for (x = 0; x < sub1; x++) // copying data to temp arrays
        First[x] = a[Firstindex + x];
    for (y = 0; y < sub2; y++)
        Second[y] = a[m + 1 + y];
    x = 0;
    y = 0;
    z = Firstindex;
    while (x < sub1 && y < sub2) {
        if (First[x] <= Second[y]) {
            a[z] = First[x];
            x++;
        } else {
            a[z] = Second[y];
            y++;
        }
        z++;
    }
    while (x < sub1) {
        a[z] = First[x];
        x++;
        z++;
    }
    while (y < sub2) {
        a[z] = Second[y];
        y++;
        z++;
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
    // algo itself
    mergeSort(arr, 0, amount - 1);
    for (int i = 0; i < amount; i++) {
        fileOut << arr[i] << " ";
    }
    fileIn.close();
    fileOut.close();
    return 0;
}
