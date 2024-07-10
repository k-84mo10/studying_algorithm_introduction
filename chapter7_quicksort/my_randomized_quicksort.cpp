#include <iostream>
#include <vector>
#include <random>

class MyRandomizedQuicksort {
    std::vector<int> array;

public:
    MyRandomizedQuicksort (std::vector<int>& array): array(array) {
        randomized_quicksort(0, array.size()-1);
        print();
    }

    void randomized_quicksort (int p, int r) {
        if (p < r) {
            int q = randomized_partition(p, r);
            randomized_quicksort(p, q-1);
            randomized_quicksort(q+1, r);   
        }
    }

    int getRandomNumber (int p, int r) {
        static std::mt19937 gen(std::random_device{}());
        std::uniform_int_distribution<> distrib(p, r);
        return distrib(gen);
    }

    int partition (int p, int r) {
        int pivot = array[r];
        int i = p - 1;
        for (int j = p; j < r; j++) {
            if (array[j] <= pivot) {
                i++;
                std::swap(array[i], array[j]);
            }
        }
        i++;
        std::swap(array[i], array[r]);
        return i;
    }

    int randomized_partition (int p, int r) {
        int i = getRandomNumber(p, r);
        std::swap(array[i], array[r]);
        return partition(p, r);
    }

    void print () {
        for (int& i : array) {
            std::cout << i << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    std::vector<int> arr = {2, 8, 7, 1, 3, 5, 6, 4};
    MyRandomizedQuicksort myQuickSort(arr);
    return 0;
}