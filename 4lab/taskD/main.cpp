#include <fstream>
#include <iostream>
#include <vector>

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

    void print() {
        if (isEmpty()) return;
        Node *p = first;
        while (p) {
            cout << p->value << " ";
            p = p->next;
        }
        cout << endl;
    }

};


int main() {
    list stack;
    int a, b;
    int result;
    char value;
    string s;
    vector<char> commands;
    ifstream in("postfix.in");
    ofstream out("postfix.out");
    while (!in.eof()) {
        in >> value;
        commands.push_back(value);
    }
    commands.pop_back();
    for (char element: commands) {
        if (element != '-' && element != '+' && element != '*') {
            stack.pushToTail(element - '0');
        } else {
            if (element == '+') {
                b = stack.popFromTail();
                a = stack.popFromTail();
                result = a + b;
                stack.pushToTail(result);
                continue;
            }
            if (element == '-') {
                b = stack.popFromTail();
                a = stack.popFromTail();
                result = a - b;
                stack.pushToTail(result);
                continue;
            }
            if (element == '*') {
                a = stack.popFromTail();
                b = stack.popFromTail();
                result = a * b;
                stack.pushToTail(result);
                continue;
            }
        }
    }
    out << stack.popFromTail();
}

