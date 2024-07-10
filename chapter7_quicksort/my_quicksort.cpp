#include <iostream>
#include <vector>

class MyQuickSort {
    std::vector<int> arr;

public:
    MyQuickSort(std::vector<int>& arr) : arr(arr) {
        quicksort(0, arr.size() - 1);
        print();
    }

    void quicksort(int p, int r) {
        if (p < r) {
            int q = partition(p, r);
            quicksort(p, q - 1);
            quicksort(q + 1, r);
        }
    } 

    int partition(int p, int r) {
        int x = arr[r];
        int i = p - 1;
        for (int j = p; j < r; j++) {
            if (arr[j] <= x) {
                i++;
                std::swap(arr[i], arr[j]);
            }
        }
        std::swap(arr[i + 1], arr[r]);
        return i + 1;
    }

    void print() {
        for (int i = 0; i < arr.size(); i++) {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    std::vector<int> arr = {2, 8, 7, 1, 3, 5, 6, 4};
    MyQuickSort myQuickSort(arr);
    return 0;
}