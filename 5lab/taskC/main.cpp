#include <fstream>
#include <vector>

using namespace std;
struct linkedMapNode {
    string key;
    string value;
    linkedMapNode *next = nullptr;
    linkedMapNode *previous = nullptr;
};

vector <vector<linkedMapNode>> linkedMap(100003);

int getHash(const string& value) {
    int tmp = 0;
    for (char i : value){
        tmp += (53 * tmp + i);
        tmp %= 100003;
    }
    return tmp;
}

int main()
{
    ifstream in("linkedmap.in");
    ofstream out("linkedmap.out");
    string command;
    string key, value;
    linkedMapNode *prev = nullptr;
    while (in >> command){
        if (command == "put"){
            in >> key >> value;
            int hash = getHash(key) % 100003;
            bool exists = false;
            for (auto & i : linkedMap[hash]) {
                if (i.key == key) {
                    exists = true;
                    i.value = value;
                }
            }
            if (!exists) {
                if (linkedMap[hash].empty())
                    linkedMap[hash].reserve(10);
                linkedMapNode x;
                x.key = key;
                x.value = value;
                x.next = nullptr;
                x.previous = prev;
                linkedMap[hash].push_back(x);
                if(prev != nullptr)
                    prev->next = &linkedMap[hash][linkedMap[hash].size() - 1];
                prev = &linkedMap[hash][linkedMap[hash].size() - 1];

            }
        }
        else if (command == "delete") {
            in >> key;
            int hash = getHash(key) % 100003;
            for (auto & i : linkedMap[hash]){
                if (i.key == key){
                    if (i.next == nullptr)
                        prev = i.previous;
                    else
                        i.next->previous = i.previous;
                    if (i.previous != nullptr)
                        i.previous->next = i.next;
                    i.value = "";
                    i.next = nullptr;
                    i.previous = nullptr;
                    i.key = "";
                    break;
                }
            }
        }
        else if (command == "get") {
            in >> key;
            int hash = getHash(key);
            bool exists = false;
            for (auto & i : linkedMap[hash]){
                if (i.key == key){
                    out << i.value << "\n";
                    exists = true;
                }
            }
            if (!exists)
                out << "none\n";
        }
        else if (command == "prev") {
            in >> key;
            int hash = getHash(key) % 100003;
            bool exists = false;
            for (auto & i : linkedMap[hash]) {
                if (i.key == key) {
                    if (i.previous != nullptr) {
                        out << i.previous->value << "\n";
                        exists = true;
                    }
                }
            }
            if (!exists)
                out << "none\n";
        }
        else if (command == "next") {
            in >> key;
            int hash = getHash(key) % 100003;
            bool exists = false;
            for (auto & i : linkedMap[hash]) {
                if (i.key == key) {
                    if (i.next != nullptr) {
                        out << i.next->value << "\n";
                        exists = true;
                    }
                }
            }
            if (!exists)
                out << "none\n";
        }
    }
    return 0;
}