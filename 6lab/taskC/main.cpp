#include <fstream>

using namespace std;

struct Node {
    int value;
    Node *left;
    Node *right;
};

int search(Node *x, int value) {
    if (x == nullptr) return 0;
    if (x->value == value) return 1;
    if (value < x->value) return search(x->left, value); else return search(x->right, value);
}

void *insert(Node *&x, int value) {
    if (x == nullptr) {
        x = new Node;
        x->value = value;
        x->left = nullptr;
        x->right = nullptr;
    } else if (x->value > value) insert(x->left, value);
    else if (x->value < value) insert(x->right, value);
}

Node *next(Node *&x, int value) {
    Node *current = x;
    Node *answer = nullptr;
    while (current != nullptr) {
        if (current->value > value) {
            answer = current;
            current = current->left;
        } else current = current->right;
    }
    return answer;
}

Node *previous(Node *&x, int value) {
    Node *current = x;
    Node *answer = nullptr;
    while (current != nullptr)
        if (current->value < value) {
            answer = current;
            current = current->right;
        } else current = current->left;
    return answer;
}

Node *Min(Node *&x) {
    if (x->left == nullptr)
        return x;
    return Min(x->left);
}

Node *del(Node *&x, int value) {
    if (x == nullptr)
        return x;
    if (value < x->value)
        x->left = del(x->left, value);
    else if (value > x->value)
        x->right = del(x->right, value);
    else if (x->left != nullptr && x->right != nullptr) {
        x->value = Min(x->right)->value;
        x->right = del(x->right, x->value);
    } else if (x->left != nullptr) x = x->left; else x = x->right;
    return x;
}

int main() {
    ifstream in("bstsimple.in");
    ofstream out("bstsimple.out");
    string action;
    Node *tree = nullptr;
    while (in >> action) {
        int value;
        in >> value;
        if (action == "insert") insert(tree, value);
        if (action == "exists") {
            if (search(tree, value)) out << "true\n"; else out << "false\n";
        }
        if (action == "next") {
            Node *tmp = next(tree, value);
            if (tmp == nullptr) out << "none\n"; else out << tmp->value << "\n";
        }
        if (action == "prev") {
            Node *tmp = previous(tree, value);
            if (tmp == nullptr) out << "none\n"; else out << tmp->value << "\n";
        }
        if (action == "delete") del(tree, value);
    }
}