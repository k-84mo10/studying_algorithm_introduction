#include <iostream>
#include <vector>
#include <random>

class MyQuickSort {
    std::vector<int> array;

public:
    MyQuickSort(std::vector<int>& arr) : array(arr) {
        //quicksort(0, array.size()-1);
        //print();
    }

    void quicksort (int p, int r) {
        if (p < r) {
            int q = randomized_partition(p, r);
            // print();
            quicksort(p, q-1);
            quicksort(q+1, r);
        }
    }

    int getRandomNumber (int p, int r) {
        static std::mt19937 gen(std::random_device{}());
        std::uniform_int_distribution<> distrib(p, r);
        return distrib(gen);
    }

    int randomized_partition(int p, int r) {
        int i = getRandomNumber(p, r);
        std::swap(array[i], array[r]);
        return partition(p, r);
    }

    int partition(int p, int r) {
        int pivot = array[r];
        int i = p - 1;
        for (int j = p; j < r; j++) {
            if (array[j] < pivot) {
                i++;
                std::swap(array[i], array[j]);
            }
        }
        i++;
        std::swap(array[i], array[r]);
        return i;
    }

    void print() {
        for (int& i : array) {
            std::cout << i << " ";
        }
        std::cout << std::endl;
    }

    // int randomized_Select(int p, int r, int i) {
    //     if (p == r) return array[p];

    //     int q = randomized_partition(p, r);
    //     int k = q - p + 1;
    //     if (i == k) {
    //         return array[q];
    //     } else if (i < k) {
    //         return randomized_Select(p, q-1, i); 
    //     } else {
    //         return randomized_Select(q+1, r, i-k);
    //     }
    // }

    int randomized_Select(int p, int r, int i) {
        while (p != r) {
            int q = randomized_partition(p, r);
            int k = q - p + 1;
            if (i == k) {
                return array[q];
            } else if (i < k) {
                r = q - 1;
            } else {
                p = q + 1;
                i = i - k;
            }
        }
        return array[p];
    }
};

int main() {
    std::vector<int> arr = {2, 8, 7, 1, 3, 5, 6, 4};
    MyQuickSort myQuickSort(arr);
    std::cout << myQuickSort.randomized_Select(0, arr.size()-1, 5) << std::endl;
    myQuickSort.print();
    return 0;
}