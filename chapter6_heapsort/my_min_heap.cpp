#include <iostream>
#include <vector>

class minHeap {
    std::vector<int> heap;

public:
    minHeap(std::vector<int>& array) : heap(array) {
        build_minheap();
    }

    void build_minheap() {
        int heap_size = heap.size();
        for (int i = heap_size/2-1; i >= 0; i--) {
            minheapify(i);
        }
    }

    int left(int i) {
        return i*2+1; 
    }

    int right(int i) {
        return i*2+2;
    }

    int parent(int i) {
        return (i-1)/2;
    }

    void minheapify(int i) {
        int heap_size = heap.size();
        int l = left(i);
        int r = right(i);
        int smallest = i;
        if (l < heap_size && heap[l] < heap[smallest]) smallest = l;
        if (r < heap_size && heap[r] < heap[smallest]) smallest = r;
        if (smallest != i) {
            std::swap(heap[i], heap[smallest]);
            minheapify(smallest);
        }
    }

    void heapsort() {
        std::vector<int> sorted;
        while(heap.size() != 0) {
            sorted.push_back(heap[0]);
            std::swap(heap[0], heap[heap.size()-1]);
            heap.pop_back();
            minheapify(0);
        }
        heap = sorted;
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
    minHeap heap(array);
    heap.heapsort();
    heap.print();
}