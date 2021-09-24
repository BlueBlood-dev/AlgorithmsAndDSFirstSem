#include <iostream>
#include <fstream>

using namespace std;

void merge(string array[], int firstIndex, int m, int lastIndex) {
    int x, y, z;
    int firstHalfIndex = m - firstIndex + 1;
    int secondHalfIndex = lastIndex - m;
    string firstHalf[firstHalfIndex];
    string secondHalf[secondHalfIndex];
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

void mergeSort(string array[], int firstIndex, int lastIndex) {
    if (firstIndex < lastIndex) {
        int middleIndex = firstIndex + (lastIndex - firstIndex) / 2;
        mergeSort(array, firstIndex, middleIndex);
        mergeSort(array, middleIndex + 1, lastIndex);
        merge(array, firstIndex, middleIndex, lastIndex);
    }
}


int findIfInArray(string temp[], int size, string basicString) {
    for (int i = 0; i < size; i++)
        if (temp[i] == basicString)
            return i;
    return -1;
}

int main() {
    ifstream fileIn("race.in");
    ofstream fileOut("race.out");

    long int amount;
    fileIn >> amount;

    string country[amount], cash_country[amount];
    string cash_surname[amount];
    for (int i = 0; i < amount; i++) {
        fileIn >> country[i] >> cash_surname[i];
        cash_country[i] = country[i];
    }
    mergeSort(country, 0, amount - 1);
    string tempArray[amount];
    for (int i = 0; i < amount; i++) {
        if (findIfInArray(tempArray, amount, country[i]) == -1) {
            fileOut << "=== " << country[i] << " ===\n";
            tempArray[i] = country[i];
            for (int j = 0; j < amount; j++) {
                if (cash_country[j] == country[i]) {
                    fileOut << cash_surname[j] << '\n';
                }
            }
        }
    }

    fileIn.close();
    fileOut.close();
}
