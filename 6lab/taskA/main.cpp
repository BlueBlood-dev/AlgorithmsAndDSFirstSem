#include <fstream>

using namespace std;

int countTheHeight(int tree[][2], int first) {
    int left = 0;
    int right = 0;
    if (tree[first][1] != -1)
        right = countTheHeight(tree, tree[first][1]);
    if (tree[first][0] != -1)
        left = countTheHeight(tree, tree[first][0]);
    return max(left + 1, right + 1);
}
int main() {
    ifstream in("height.in");
    ofstream out("height.out");
    int left, right, value;
    int amount;
    in >> amount;
    int tree[amount][2];
    for (int i = 0; i < amount; ++i) {
        in >> value >> left >> right;
        tree[i][0] = left - 1;
        tree[i][1] = right - 1;
    }
    if (amount == 0) out << "0"; else out << countTheHeight(tree, 0);
}
