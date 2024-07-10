#include <iostream>
#include <vector>

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class listnode_stack {
    ListNode* head;

public:
    listnode_stack() {} 

    void push(int val) {
        ListNode* newOne = new ListNode(val, head);
        head = newOne;
    }

    int pop() {
        if (head == nullptr) {
            std::cout << "stack has no element." << std::endl;
            return -1;
        }
        int ans = head->val;
        head = head->next;
        return ans;
    }
};

int main() {
    listnode_stack l;
    for (int i = 0; i < 10; i++) {
        l.push(i);
    }
    for (int i = 0; i < 11; i++) {
        std::cout << l.pop() << std::endl;
    }
    return 0;
}