#include <iostream>
#include <vector>

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class listnode_queue {
    ListNode* head;
    ListNode* tail;

public:
    listnode_queue() : head(nullptr), tail(nullptr) {} 

    void enqueue(int val) {
        ListNode* newOne = new ListNode(val);
        if (head == nullptr || tail == nullptr) {
            head = tail = newOne;
            return;
        }
        tail->next = newOne;
        tail = newOne;
    }

    int dequeue() {
        if (head == nullptr) {
            std::cout << "queue has no element." << std::endl;
            return -1;
        }
        int ans = head->val;
        ListNode* tmp = head;
        head = head->next;
        delete tmp;
        return ans;
    }
};

int main() {
    listnode_queue l;
    for (int i = 0; i < 10; i++) {
        l.enqueue(i);
    }
    for (int i = 0; i < 11; i++) {
        std::cout << l.dequeue() << std::endl;
    }
    l.enqueue(100);
    std::cout << l.dequeue() << std::endl;
    return 0;
}