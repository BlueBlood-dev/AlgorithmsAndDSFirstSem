#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

 void binSearchLeft(int array[], int amount, int value, int *firstFound, int *lastFound) {
    ofstream out("binsearch.out");
    int left = 0;
    int right = amount - 1;
    int flag = false;
    int counter = 0;
    int i = 0;
    int middle;
    while (left <= right && !flag) {
        middle = (right - left) / 2;
        i++;
        if (value == array[middle]) {
            *firstFound = middle;
            flag = true;
            while (array[middle] == array[middle + 1] && middle + 1 < amount) {
                counter++;
                middle++;
            }
            *lastFound = *firstFound + counter;
        }
        if (array[middle] > value) { right = middle - 1; } else { left = middle + 1; }
        if (i > log(amount)) break;
    }

}

int main() {
    ifstream in("binsearch.in");
    ofstream out("binsearch.out");
    int amount, amountOfRequests;
    in >> amount;
    int *numbers = new int[amount];
    for (int i = 0; i < amount; ++i)
        in >> numbers[i];
    in >> amountOfRequests;
    int request;
    int firstFound = -1;
    int lastFound = -1;
    for (int i = 0; i < amountOfRequests; ++i) {
        in >> request;
        binSearchLeft(numbers, amount, request, &firstFound, &lastFound);
        if (firstFound != -1 && lastFound != -1) {
            out << ++firstFound << " " << ++lastFound << "\n";
        } else if (firstFound != -1 && lastFound == -1) {
            out << ++firstFound << " " << lastFound << "\n";
        } else { out << firstFound << " " << lastFound << "\n"; }
        firstFound =-1; lastFound=-1;
    }
    return 0;
}
