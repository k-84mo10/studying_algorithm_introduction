#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

class RadixSort {
    std::vector<int> arr;
    std::vector<int> past_array;
    int digit = 0;
    int max_digit;

public:
    RadixSort(std::vector<int> array) : arr(array) {
        max_digit = getMaxDigit();
        for (int i = 0; i < max_digit-1; i++) {
            countingSort();
            digit++;
        }
        print();
    }

    int getDigit(int num) {
        num = num / pow(10, digit);
        return num % 10;
    }

    int getMaxDigit() {
        int maxDigit = 0;
        for (int i: arr) {
            int digit = 0;
            while (i != 0) {
                i = i / 10;
                digit++;
            }
            if (maxDigit < digit) maxDigit = digit;
        }
        return maxDigit;
    }

    void countingSort() {
        std::vector<int> arr_b(arr.size());
        std::vector<int> arr_c(10, 0);

        for (int j = 0; j < arr.size(); j++) {
            arr_c[getDigit(arr[j])] += 1;
        }

        for (int i = 1; i < 10; i++) {
            arr_c[i] += arr_c[i-1];
        }

        for (int j = arr.size()-1; j >= 0; j--) {
            arr_b[arr_c[getDigit(arr[j])]-1] = arr[j];
            arr_c[getDigit(arr[j])] -= 1;
        }

        for (int i = 0; i < arr.size(); i++) {
            arr[i] = arr_b[i];
        }
    }

    void print() {
        for (int& i: arr) {
            std::cout << i << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    std::vector<int> arr = {329, 1500, 4, 457, 657, 839, 436, 720, 355, 17000, 1};
    RadixSort sort(arr);
    return 0;
}