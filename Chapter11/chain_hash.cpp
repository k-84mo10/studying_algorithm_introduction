#include <iostream>
#include <vector>

class ChainHash
{
private:
    struct Node
    {
        int key;
        Node *next;
    };
    std::vector<Node *> table;
    int size;
    int surplus_hash(int key) const
    {
        return key % table.size();
    }

public:
    ChainHash(int size) : size(size)
    {
        table.resize(size);
        for (int i = 0; i < size; i++)
        {
            table[i] = nullptr;
        }
    }

    void insert(int key)
    {
        int hash = surplus_hash(key);
        if (table[hash] != nullptr)
        {
            std::cout << "collision " << table[hash]->key << std::endl;
        }
        Node *node = new Node{key, table[hash]};
        table[hash] = node;
    }

    bool find(int key) const
    {
        int hash = surplus_hash(key);
        Node *node = table[hash];
        while (node != nullptr)
        {
            if (node->key == key)
            {
                return true;
            }
            node = node->next;
        }
        return false;
    }

    void erase(int key)
    {
        int hash = surplus_hash(key);
        Node *node = table[hash];
        Node *prev = nullptr;
        while (node != nullptr)
        {
            if (node->key == key)
            {
                if (prev == nullptr)
                {
                    table[hash] = node->next;
                }
                else
                {
                    prev->next = node->next;
                }
                delete node;
                return;
            }
            prev = node;
            node = node->next;
        }
    }
};

int main()
{
    ChainHash chain_hash(100);
    for (int i = 0; i < 100; i++)
    {
        int j = rand() % 1000;
        std::cout << "insert: " << j << std::endl;
        chain_hash.insert(j);
    }
}