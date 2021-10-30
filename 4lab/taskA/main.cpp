#include <iostream>
#include <fstream>

using namespace std;

struct Node {
    long long value;
    Node *next;

    explicit Node(long long val) : value(val), next(nullptr) {}
};

struct list {
    Node *first;
    Node *last;

    list() : first(nullptr), last(nullptr) {}

    bool isEmpty() const {
        return first == nullptr;
    }

    void pushToTail(int value) {
        Node *pointer = new Node(value);
        if (isEmpty()) {
            first = pointer;
            last = pointer;
            return;
        }
        last->next = pointer;
        last = pointer;
    }

    long long removeFirst() {
        long long value;
        if (isEmpty())
            return -1;
        Node *pointer = first;
        value = pointer->value;
        first = pointer->next;
        delete pointer;
        return value;
    }

    long long popFromTail() {
        long long value;
        Node *pointer = first;
        if (first == last) {
            value = removeFirst();
            return value;
        }
        while (pointer->next != last)
            pointer = pointer->next;
        pointer->next = nullptr;
        value = last->value;
        delete last;
        last = pointer;
        return value;
    }

};

int main() {
    list stack;
    ifstream in("stack.in");
    ofstream out("stack.out");

    long long value, amount, temp;
    char symbol;
    in >> amount;

    for (int i = 0; i < amount; ++i) {
        in >> symbol;
        if (symbol == '-') {
            temp = stack.popFromTail();
            out << temp;
            if (i != amount - 1)
                out << '\n';
            continue;
        }
        in >> value;
        if (symbol == '+')
            stack.pushToTail(value);

    }
}
