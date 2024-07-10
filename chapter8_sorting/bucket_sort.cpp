#include <iostream>
#include <vector>

class BucketSort {
    std::vector<int> arr;

public:
    void insertion_sort(std::vector<int>& array) {
        for (int i = 1; i < array.size(); i++) {
            int key = array[i];
            int j = i - 1;
            while (j >= 0 && array[j] > key) {
                array[j + 1] = array[j];
                j = j - 1;
            }
            array[j + 1] = key;
        }
    }

    void bucket_sort() {
        std::vector<std::vector<float>> arr_b(arr.size());
        int n = arr.size();
        for (int i = 0; i < n; i++) {
            arr_b[int(n*arr[i])].push_back(arr[i]);
        }
    }
};