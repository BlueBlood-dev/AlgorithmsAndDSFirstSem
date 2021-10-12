#include <iostream>
#include <fstream>

using namespace std;

int binSearchRight(int array[], int amount, int value){
    int left = -1; int right = amount;
    int middle;
    while (left < right - 1){
        middle = (left + right)/2;
        if(array[middle] <= value){
            left = middle;
        } else {
            right = middle;
        }
    }
    if(array[right-1] == value)
        return right;
    else
        return  -1;
}

 int binSearchLeft(int array[], int amount, int value) {
     int left = -1; int right = amount;
     int middle;
     while (left < right - 1){
         middle = (left + right)/2;
         if(array[middle] < value){
             left = middle;
         } else {
             right = middle;
         }
     }
     if(array[right] == value)
        return right;
     else
         return -1;
 }
 
int main() {
    ifstream in("binsearch.in");
    ofstream out("binsearch.out");
    int amount, amountOfRequests;
    in >> amount;
    int *numbers = new int[amount];
    for (int i = 0; i < amount; i++)
        in >> numbers[i];
    in >> amountOfRequests;
    int request;
    for (int i = 0; i < amountOfRequests; i++) {
        in >> request;
         int tmp = binSearchLeft(numbers, amount, request);
         tmp = tmp == -1? tmp:tmp+1;
       out << tmp  << " " << binSearchRight(numbers,amount,request) << "\n";
    }
    return 0;
}
