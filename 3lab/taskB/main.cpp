#include <iostream>
#include <fstream>

using namespace std;

void heapify(long *heap, int amount, int index) {
    int largest = index;
    int l = 2 * index + 1;
    int r = 2 * index + 2;
    // если левый больше корня
    if (l < amount && heap[l] > heap[largest])
        largest = l;
    // если правый больше корня
    if (r < amount && heap[r] > heap[largest])
        largest = r;
    // если самый большой в итоге не корень
    if (largest != index) {
        swap(heap[index], heap[largest]);
        heapify(heap, amount, largest);
    }
}

void heapSort(long *heap, int amount) {
    // строим пирамиду
    for (int i = amount / 2 - 1; i >= 0; i--) heapify(heap, amount, i);
    for (int i = amount - 1; i >= 0; i--) {
        swap(heap[0], heap[i]);//текущий коренб отправляем в конец
        heapify(heap, i, 0);
    }
}

int main() {
    ifstream in("sort.in");
    ofstream out("sort.out");
    int amount;
    in >> amount;
    long *levels = new long[amount];
    for (int i = 0; i < amount; ++i) {
        in >> levels[i];
    }
    heapSort(levels, amount);
    for (int i = 0; i < amount; ++i) {
        out << levels[i] << " ";
    }

}
