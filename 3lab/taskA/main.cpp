#include <iostream>
#include <fstream>

using namespace std;
int main() {
    ifstream in("isheap.in");
    ofstream out("isheap.out");

    int amount;
    in >> amount;
    long levels[amount+1];
    for(int i = 1; i <amount+1; ++i){
       in >> levels[i];
    }

    int check = 1;

    for(int i = 1; i <amount/2; ++i) {
        if ((2 * i > amount) || (levels[i] > levels[2 * i])) {
            check = 0;
            break;
        }
        if (((2 * i) + 1 > amount) || (levels[i] > levels[(2 * i) + 1])){
        check = 0;
            break;
        }
    }
    if(check == 0) out << "NO"; else out << "YES";
}
