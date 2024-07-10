#include <iostream>
#include <vector>
#include <algorithm>

class my_max_heap{
    std::vector<int> myHeap;

public:
    my_max_heap(std::vector<int>& array) : myHeap(array) {
        build_max_heap();
    }

    void build_max_heap() {
        for (int i = myHeap.size()/2 - 1; i >= 0; i--) {
            max_heapify(i);
        }
    }

    void max_heapify(int i) {
        int l = left(i);
        int r = right(i);
        int largest = i;
        if (l < myHeap.size() && myHeap[l] > myHeap[largest]) {
            largest = l;
        }
        if (r < myHeap.size() && myHeap[r] > myHeap[largest]) {
            largest = r;
        }
        if (largest != i) {
            std::swap(myHeap[i], myHeap[largest]);
            max_heapify(largest); // largestの位置にあるノードの数は減っているので、再帰的に確かめる必要がある
        }
    }

    void heapsoat() {
        std::vector<int> sorted = myHeap;
        for (int i = myHeap.size() - 1; i >= 0; i--) {
            std::swap(myHeap[0], myHeap[i]);
            sorted[i] = myHeap[i];
            myHeap.pop_back();
            max_heapify(0);
        }
        myHeap = sorted;
    }

    void print() {
        for (int i = 0; i < myHeap.size(); i++) {
            std::cout << myHeap[i] << " ";
        }
        std::cout << std::endl;
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
};

int main() {
    std::vector<int> array = {4, 10, 2, 8, 16, 3, 7, 9, 14, 1};
    my_max_heap heap(array);
    heap.heapsoat();
    heap.print();
}