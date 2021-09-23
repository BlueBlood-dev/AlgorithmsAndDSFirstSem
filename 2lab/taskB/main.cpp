#include <iostream>
#include <fstream>

using namespace std;

int findIfInArray(string temp[], int size, string basicString) {
    for(int i = 0;  i < size; i ++)
        if(temp[i] == basicString)
            return 1;
    return 0;
}

int main() {
   ifstream fileIn("race.in");
   ofstream fileOut("race.out");

   int amount;
   fileIn >> amount;

   string country[amount];
   string surname[amount];

   for(int i =0; i < amount; i++){
        fileIn >> country[i] >> surname[i];
   }

   for(int i = 0; i < amount; i ++){
       for(int j = 0 ; j < amount; j++){
           if(country[i]<country[j]){
               swap(country[j],country[i]);
               swap(surname[j],surname[i]);
           }
       }
   }
string tempArray[amount];
   for(int i =0; i < amount; i++){
       if(findIfInArray(tempArray, amount, country[i])){
           fileOut << surname[i]<< "\n";
       } else{
           fileOut <<"=== " <<country[i]<<" ===\n";
           tempArray[i] = country[i];
           fileOut << surname[i] << "\n";
       }
   }

   fileIn.close();
   fileOut.close();
}
