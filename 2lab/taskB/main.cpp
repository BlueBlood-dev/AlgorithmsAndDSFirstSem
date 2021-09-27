#include <iostream>
#include <fstream>

using namespace std;

void merge(string array[],string s[], int firstIndex, int m, int lastIndex) {
    int x, y, z;
    int firstHalfIndex = m - firstIndex + 1;
    int secondHalfIndex = lastIndex - m;
    string firstHalf[firstHalfIndex];
    string secondHalf[secondHalfIndex];
    string firstHalf_surname[firstHalfIndex];
    string secondHalf_surname[secondHalfIndex];
    for (x = 0; x < firstHalfIndex; x++) {
        firstHalf[x] = array[firstIndex + x];
        firstHalf_surname[x] = s[firstIndex + x];
    }

    for (y = 0; y < secondHalfIndex; y++) {
        secondHalf[y] = array[m + 1 + y];
        secondHalf_surname[y] = s[m+1+y];
    }

    x = 0;
    y = 0;
    z = firstIndex;

    while (x < firstHalfIndex && y < secondHalfIndex) {
        if (firstHalf[x] <= secondHalf[y]) {
            array[z] = firstHalf[x];
            s[z] = firstHalf_surname[x];
            x++;
        } else {
            array[z] = secondHalf[y];
            s[z] = secondHalf_surname[y];
            y++;
        }
        z++;
    }
    while (x < firstHalfIndex) {
        array[z] = firstHalf[x];
        s[z] = firstHalf_surname[x];
        x++;
        z++;
    }
    while (y < secondHalfIndex) {
        array[z] = secondHalf[y];
        s[z] = secondHalf_surname[y];
        y++;
        z++;
    }
}

void mergeSort(string array[], string s[],int firstIndex, int lastIndex) {
    if (firstIndex < lastIndex) {
        int middleIndex = firstIndex + (lastIndex - firstIndex) / 2;
        mergeSort(array,s, firstIndex, middleIndex);
        mergeSort(array,s, middleIndex + 1, lastIndex);
        merge(array,s, firstIndex, middleIndex, lastIndex);
    }
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
    mergeSort(country,cash_surname, 0, amount - 1);
    fileOut << "=== " << country[0] << " ===\n";
    fileOut << cash_surname[0] << "\n";
    for (int i = 1; i < amount; i++) {
        if (country[i] != country[i - 1])
            fileOut << "=== " << country[i] << " ===\n";
        fileOut << cash_surname[i] << "\n";

        }

    fileIn.close();
    fileOut.close();
}




