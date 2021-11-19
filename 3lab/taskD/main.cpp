#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

vector<pair<int, int>> heap;

void siftUp(int index) {
    while (heap[index].first < heap[(index - 1) / 2].first && index !=0) {
        swap(heap[index], heap[(index - 1) / 2]);
        index = (index - 1) / 2;
    }
}

void siftDown(int index) {
    int left, right, j;
    while (2 * index + 1 < heap.size()) {
        left = 2 * index + 1;
        right = 2 * index + 2;
        j = left;
        if (right < heap.size() && heap[right].first < heap[left].first) {
            j = right;
        }
        if (heap[index].first <= heap[j].first) {
            break;
        }
        swap(heap[index], heap[j]);
        index = j;
    }
}


int extractMin() {
    int min = heap[0].first;
    heap[0] = heap[heap.size() - 1];
    heap.pop_back();
    siftDown(0);
    return min;
}


void decrease(int index, int value) {
    for (int i = 0; i < heap.size(); ++i) {
        if (heap[i].second == index) {
            heap[i].first = value;
            siftUp(i);
            break;
        }
    }
}


void push(int value, int counter) {
    heap.push_back(make_pair(value, counter));
    siftUp(heap.size() - 1);
}

int main() {
    ifstream in("priorityqueue.in");
    ofstream out("priorityqueue.out");
    string command;
    int counter = 1;
    int value, index, temp;
    while (in >> command) {
        if (command == "push") {
            in >> value;
            push(value, counter);
        }
        else if (command == "extract-min"){
            if (heap.empty())
                out << "*" << "\n";
            else
                out << extractMin() << "\n";
        }
        else if (command == "decrease-key"){
            in >> index >> temp;
            decrease(index, temp);
        }
        counter++;
    }
}