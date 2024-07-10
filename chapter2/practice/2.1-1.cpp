#include <iostream>
#include <vector>

class solution {
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

    void print_array(std::vector<int>& array) {
        for (auto& i: array) {
            std::cout << i << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    std::vector<int> array = {31, 41, 59, 26, 41, 58};
    solution sol;
    sol.insertion_sort(array);
    sol.print_array(array);
    return 0;
}