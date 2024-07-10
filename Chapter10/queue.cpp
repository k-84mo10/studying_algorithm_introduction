#include <iostream>
#include <vector>

class Queue {
    int Qsize;
    int Qtail;
    int Qhead;
    int elementNum;
    std::vector<int> Q;

public:
    Queue(int size) : Qsize(size), Q(Qsize), Qtail(0), Qhead(0), elementNum(0) {}

    void enqueue(int x) {
        if (elementNum == Qsize) {
            perror("overflow");
            return;
        } else {
            Q[Qtail] = x;
            elementNum += 1;
            Qtail = (Qtail == Qsize-1) ? 0 : Qtail+1;
        }
    }

    int dequeue() {
        if (elementNum == 0) {
            perror("underflow");
            return -1;
        } else {
            int x = Q[Qhead];
            elementNum -= 1;
            Qhead = (Qhead == Qsize-1) ? 0 : Qhead+1;
            return x;
        }
    }
};

int main() {
    Queue q(10);
    for (int i = 0; i < 11; i++) {
        q.enqueue(i);
    }
    for (int i = 0; i < 11; i++) {
        std::cout << q.dequeue() << " ";
    }
    std::cout << std::endl;
    return 0;
}