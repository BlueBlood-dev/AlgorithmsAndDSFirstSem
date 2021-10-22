#include <iostream>
#include <fstream>

using namespace std;

struct Node {
    char value;
    Node *next;

    explicit Node(char val) : value(val), next(nullptr) {} // конструктор
};

struct list {
    Node *first;
    Node *last;

    list() : first(nullptr), last(nullptr) {}

    bool isEmpty() const {
        return first == nullptr;
    }

    void pushToTail(char value) {
        Node *pointer = new Node(value);
        if (isEmpty()) {
            first = pointer;
            last = pointer;
            return;
        }
        last->next = pointer;
        last = pointer;
    }

    char removeFirst() {
        char value;
        if (isEmpty())
            return 'e';
        Node *pointer = first;
        value = pointer->value;
        first = pointer->next;
        delete pointer;
        return value;
    }

    char popFromTail() {
        char value;
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
    ifstream in("brackets.in");
    ofstream out("brackets.out");
    string brackets;
    while (!in.eof()) {
        in >> brackets;
        for (char bracket:brackets) {
            if (bracket == '(' || bracket == '[') {
                stack.pushToTail(bracket);
            } else {
                if (bracket == ')' && !stack.isEmpty() && stack.last->value == '('){
                    stack.popFromTail();
                } else if (bracket == ']' && !stack.isEmpty() && stack.last->value == '[') {
                    stack.popFromTail();
                } else {
                    stack.pushToTail(bracket);
                    break;
                }
            }
        }
        if (stack.isEmpty()) {
            out << "YES" << endl;
        } else {
            out << "NO" << endl;
            while (!stack.isEmpty())
                stack.popFromTail();
        }

    }
}