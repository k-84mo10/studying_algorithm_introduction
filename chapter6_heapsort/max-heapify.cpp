#include <iostream>
#include <vector>
#include <algorithm>

class max_heap {
    std::vector<int> arr;

public:
    max_heap(std::vector<int>& arr) : arr(arr) {
        build_max_heap();
    }

    void build_max_heap() {
        for (int i = arr.size() / 2; i >= 0; i--) {
            max_heapify(i);
        }
    }

    void max_heapify(int i) {
        int l = left(i);
        int r = right(i);
        int largest = i;
        if (l < arr.size() && arr[l] > arr[i]) {
            largest = l;
        }
        if (r < arr.size() && arr[r] > arr[largest]) {
            largest = r;
        }
        if (largest != i) {
            std::swap(arr[i], arr[largest]);
            max_heapify(largest);
        }
    }

    int parent(int i) {
        return (i - 1) / 2;
    }

    int left(int i) {
        return 2 * i + 1;
    }

    int right(int i) {
        return 2 * i + 2;
    }
};

int main() {
    std::vector<int> arr = {27, 17, 3, 16, 13, 10, 1, 5, 7, 12, 4, 8, 9, 0};
    max_heap heap(arr);
    for (int i = 0; i < arr.size(); i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}