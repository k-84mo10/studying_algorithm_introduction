#include <iostream>

struct Node
{
    int data;
    Node *parent;
    Node *left;
    Node *right;
    Node(int data) : data(data), left(nullptr), right(nullptr) {}
};

class BinaryTree
{
    Node *root;

public:
    BinaryTree() : root(nullptr) {}

    void inorder_tree_walk(Node *x)
    {
        if (x != nullptr)
        {
            inorder_tree_walk(x->left);
            std::cout << x->data << " ";
            inorder_tree_walk(x->right);
            if (x == maximum())
            {
                std::cout << std::endl;
            }
        }
    }

    void inorder_tree_walk()
    {
        inorder_tree_walk(root);
    }

    Node *search(Node *x, int k)
    {
        while (x != nullptr && k != x->data)
        {
            if (k < x->data)
            {
                x = x->left;
            }
            else
            {
                x = x->right;
            }
        }
        return x;
    }

    Node *search(int k)
    {
        return search(root, k);
    }

    Node *minimum(Node *x)
    {
        while (x->left != nullptr)
        {
            x = x->left;
        }
        return x;
    }

    Node *minimum()
    {
        return minimum(root);
    }

    Node *maximum(Node *x)
    {
        while (x->right != nullptr)
        {
            x = x->right;
        }
        return x;
    }

    Node *maximum()
    {
        return maximum(root);
    }

    Node *successor(Node *x)
    {
        if (x->right != nullptr)
        {
            return x->right;
        }
        Node *y = x->parent;
        while (y != nullptr && x == y->right)
        {
            x = y;
            y = y->parent;
        }
        return y;
    }

    void insert(int k)
    {
        Node *z = new Node(k);
        Node *y = nullptr;
        Node *x = root;
        while (x != nullptr)
        {
            y = x;
            if (z->data < x->data)
            {
                x = x->left;
            }
            else
            {
                x = x->right;
            }
        }
        z->parent = y;
        if (y == nullptr)
        {
            root = z;
        }
        else if (z->data < y->data)
        {
            y->left = z;
        }
        else
        {
            y->right = z;
        }
    }

    void transplant(Node *u, Node *v)
    {
        if (u->parent == nullptr)
        {
            root = v;
        }
        else if (u == u->parent->left)
        {
            u->parent->left = v;
        }
        else
        {
            u->parent->right = v;
        }
        if (v != nullptr)
        {
            v->parent = u->parent;
        }
    }

    void remove(Node *z)
    {
        if (z->left == nullptr)
        {
            transplant(z, z->right);
        }
        else if (z->right == nullptr)
        {
            transplant(z, z->left);
        }
        else
        {
            Node *y = minimum(z->right);
            if (y->parent != z)
            {
                transplant(y, y->right);
                y->right = z->right;
                y->right->parent = y;
            }
            transplant(z, y);
            y->left = z->left;
            y->left->parent = y;
        }
    }
};

int main()
{
    BinaryTree tree;
    tree.insert(5);
    tree.insert(3);
    tree.insert(7);
    tree.insert(2);
    tree.insert(4);
    tree.insert(6);
    tree.insert(8);
    tree.inorder_tree_walk();
    tree.remove(tree.search(3));
    tree.inorder_tree_walk();
    tree.insert(40);
    tree.inorder_tree_walk();
    return 0;
}