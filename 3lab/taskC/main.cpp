#include <iostream>
#include <fstream>

using namespace std;

void radixSort(string *array, int amount, int length, int iteration) {
    length--;
    for (int i = 0; i < iteration; ++i) {
        for (int j = 1; j < amount; ++j) {
            int flag = j - 1;
            while (flag >= 0 && array[flag][length] > array[flag + 1][length]) {
                swap(array[flag], array[flag + 1]);
                flag--;
            }
        }
        length--;
        if (length < 0) break;
    }
}

int main() {
    ifstream in("radixsort.in");
    ofstream out("radixsort.out");

    int amount, length, iteration;
    in >> amount >> length >> iteration;
    auto *array = new string[amount];
    for (int i = 0; i < amount; ++i)
        in >> array[i];
    radixSort(array, amount, length, iteration);
    for (int i = 0; i < amount; ++i)
        out << array[i] << "\n";
}