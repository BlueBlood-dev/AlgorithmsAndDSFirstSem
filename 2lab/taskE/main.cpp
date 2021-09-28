#include <iostream>
#include <fstream>
using namespace std;


int main() {
    int amount, k;
    ifstream in("kth.in");
    ofstream out("kth.out");
    in >> amount >> k;
    int array[amount];
    for(int i =0 ; i < amount; ++i)
        in >> array[i];




}
