#include <iostream>
#include <vector>

class my_d_tree {
    std::vector<int> tree; 
    int tree_size;
    int d;

public:
    my_d_tree(std::vector<int> array, int d) : tree(array), d(d) {
        tree_size = array.size();
        build_d_tree();
        print();
        heapsort();
    }

    void build_d_tree() {
        for (int i = tree_size/d - 1; i >= 0; i--) {
            d_treeify(i);
        }
    }

    void d_treeify(int i) {
        int largest = i;
        for (int j = 1; j <= d; j++) {
            int child = d*i + j;
            if (child < tree_size && tree[child] > tree[largest]) {
                largest = child;
            }
        }
        if (largest != i) {
            std::swap(tree[i], tree[largest]);
            d_treeify(largest);
        }
    }

    void heapsort() {
        int n = tree_size;
        for (int i = n-1; i >= 1; i--) {
            std::swap(tree[0], tree[i]);
            tree_size -= 1;
            d_treeify(0);
        }
    }

    void print() {
        for (int& i : tree) {
            std::cout << i << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    std::vector<int> array = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
    my_d_tree d_tree(array, 3);
    d_tree.print();
    return 0;
}