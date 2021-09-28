#include <iostream>
#include <fstream>

using namespace std;

int main() {
    int amount;
    ifstream in("antiqs.in");
    ofstream out("antiqs.out");
    in >> amount;
    int array[amount];
    for (int i = 0; i< amount; ++i)
        array[i] = i+1;
    for(int i = 0; i < amount; ++i)
        swap(array[i],array[i/2]);
    for(int i = 0; i < amount; ++i)
        out << array[i] << " ";

}
