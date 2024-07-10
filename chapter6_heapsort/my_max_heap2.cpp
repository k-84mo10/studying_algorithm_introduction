#include <iostream>
#include <vector>

class my_maxheap2 {
    std::vector<int> heap;
    int heap_size;

public:
    my_maxheap2(std::vector<int> array) : heap(array) {
        heap_size = array.size();
        build_maxheap();
        heapsort();
    }

    void build_maxheap() {
        for (int i = heap_size/2-1; i >= 0; i--) {
            maxheapify(i);
        }
    }

    void maxheapify(int i) {
        int l = left(i);
        int r = right(i);
        int largest = i;
        if (l < heap_size && heap[l] > heap[largest]) largest = l;
        if (r < heap_size && heap[r] > heap[largest]) largest = r;
        if (largest != i) {
            std::swap(heap[i], heap[largest]);
            maxheapify(largest);
        }
    }

    int left(int i) {
        return 2*i+1;
    }

    int right(int i) {
        return 2*i+2;
    }

    int parent(int i) {
        return (i-1)/2;
    }

    void heapsort() {
        int n = heap_size;
        for (int i = n-1; i >= 1; i--) {
            std::swap(heap[0], heap[i]);
            heap_size -= 1;
            maxheapify(0);
        }
    }

    void print() {
        for (int& i : heap) {
            std::cout << i << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    std::vector<int> array = {4, 10, 2, 8, 16, 3, 7, 9, 14, 1};
    my_maxheap2 heap(array);
    heap.print();
}