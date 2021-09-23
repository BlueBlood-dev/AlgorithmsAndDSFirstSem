#include <iostream>
#include <fstream>

using namespace std;

int main() {
   ifstream fileIn("race.in");
   ofstream fileOut("race.out");
   int amount;
   fileIn >> amount;
   int size = amount * 2;
   string array[size];
   for(int i =0; i < size; i++){
        fileIn >> array[i];
   }
   


    for(int i =0; i < size; i++){
        fileOut << array[i] << " ";
    }

   fileIn.close();
   fileOut.close();
}
