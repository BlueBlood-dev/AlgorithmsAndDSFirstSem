#include <fstream>
#include <vector>
#include <iostream>

using namespace std;

int main() {
    ifstream in("set.in");
    ofstream out("set.out");
    vector<vector<int>> hashes(1001);
    string command;
    int number;
    int indexFound;
    bool exists;
    while (in >> command) {
        in >> number;
        exists = false;
        int temp = number % 1001;
        if (temp < 0) temp *= (-1);
        for (int i = 0; i < hashes[temp].size(); ++i) {
            if (hashes[temp][i] == number) {
                exists = true;
                indexFound = i;
                break;
            }
        }
        if (!exists && command == "insert")
            hashes[temp].push_back(number);
        if (exists && command == "delete")
            hashes[temp].erase(hashes[temp].begin() + indexFound);
        if (command == "exists") {
            if (exists)
                out << "true\n";
            else
                out << "false\n";
        }
    }
}

