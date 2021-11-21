#include <fstream>
#include <vector>

using namespace std;

struct Node{
    long long value;
    int left;
    int right;
};

vector<Node> tree;
bool checkIfTree = true;

void checkTheTree(int value, long long minForNode, long long maxForNode){
    if(tree[value].value <= minForNode || tree[value].value>= maxForNode) {
        checkIfTree = false;
        return;
    }

    if(tree[value].left != 0)
        checkTheTree(tree[value].left,minForNode, tree[value].value);
    if(tree[value].right != 0)
        checkTheTree(tree[value].right, tree[value].value, maxForNode);
}

int main() {
    ifstream in("check.in");
    ofstream out("check.out");
    int amount;
    in >> amount;
    if(amount == 0){
        out  << "YES";
    } else {
        tree.resize(amount+1);
        for (int i = 1; i <=amount; ++i) {
            in >> tree[i].value >> tree[i].left >> tree[i].right;
        }
        checkTheTree(1, -1000000000, 1000000000);
        if (checkIfTree) out << "YES"; else out << "NO";
    }
}
