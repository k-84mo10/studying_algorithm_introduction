#include <iostream>
#include <vector>

class Stack {
    const int Ssize;
    int Stop;
    std::vector<int> S;

public:
    Stack(int size) : Ssize(size+1), Stop(0), S(Ssize)  {}

    bool static_empty() {
        return (Stop == 0) ? true : false;
    }

    void push(int x) {
        if (Stop >= Ssize-1) {
            perror("overflow");
            return ;
        }
        Stop += 1;
        S[Stop] = x;
    }

    int pop() {
        if (static_empty()) {
            perror("underflow");
            return -1;
        }
        Stop -= 1;
        return S[Stop+1];
    }
};

int main() {
    Stack s(10);
    for (int i = 0; i < 10; i++) {
        s.push(i);
    }
    for (int i = 0; i < 10; i++) {
        std::cout << s.pop() << " ";
    }    
    std::cout << std::endl;
    s.pop();
}