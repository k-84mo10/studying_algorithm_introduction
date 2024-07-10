#include <iostream>
#include <vector>

class solution {
public:
    void insertion_sort(std::vector<int>& array) {
        int array_size = array.size();
        for (int i = array_size; i >= 0; i--) {
            int key = array[i];
            int j = i + 1;
            while (j < array_size && array[j] < key) {
                array[j - 1] = array[j];
                j = j + 1;
            }
            array[j - 1] = key;
            print_array(array);
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