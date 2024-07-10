#include <iostream>

struct Node
{
    int data;
    Node *parent;
    Node *left;
    Node *right;
    Node(int data) : data(data), parent(nullptr), left(nullptr), right(nullptr) {}
};

class MyBinaryTree
{
    Node *root;

public:
    explicit MyBinaryTree() : root(nullptr) {}

    void insert(int insert_data)
    {
        Node *insert_Node = new Node(insert_data);

        if (root == nullptr)
        {
            root = insert_Node;
            return;
        }

        Node *insert_location = root;
        Node *insert_location_parent = nullptr;

        while (insert_location != nullptr)
        {
            insert_location_parent = insert_location;
            if (insert_location->data > insert_data)
            {
                insert_location = insert_location->left;
            }
            else
            {
                insert_location = insert_location->right;
            }
        }

        insert_Node->parent = insert_location_parent;
        if (insert_location_parent->data > insert_data)
        {
            insert_location_parent->left = insert_Node;
        }
        else
        {
            insert_location_parent->right = insert_Node;
        }
    }

    void transplant(Node *transplantee, Node *transplanter)
    {
        if (transplantee->parent == nullptr)
        {
            transplanter == root;
        }
        else if (transplantee->parent->left == transplantee)
        {
            transplantee->parent->left = transplanter;
        }
        else
        {
            transplantee->parent->right = transplanter;
        }

        if (transplanter->parent)
        {
            transplanter->parent = transplantee->parent;
        }
    }

    void remove(Node *remove_node)
    {
        if (remove_node == nullptr)
            return;

        if (remove_node->left == nullptr)
        {
            transplant(remove_node, remove_node->right);
        }
        else if (remove_node->right == nullptr)
        {
            transplant(remove_node, remove_node->left);
        }
        else
        {
            Node *remove_node_succeser = minimumSearch(remove_node->right);
            if (remove_node_succeser->parent != remove_node)
            {
                transplant(remove_node_succeser, remove_node_succeser->right);
                remove_node_succeser->right = remove_node->right;
                remove_node_succeser->right->parent = remove_node_succeser;
            }
            transplant(remove_node, remove_node_succeser);
            remove_node_succeser->left = remove_node->left;
            remove_node_succeser->left->parent = remove_node_succeser;
        }
    }

    Node *minimumSearch(Node *search_node)
    {
        while (search_node->left != nullptr)
        {
            search_node = search_node->left;
        }
        return search_node;
    }

    Node *minimumSearch()
    {
        return minimumSearch(root);
    }

    Node *treeSearch(int search_data)
    {
        Node *search_node = root;
        while (search_node != nullptr)
        {
            if (search_node->data == search_data)
            {
                break;
            }
            else if (search_node->data > search_data)
            {
                search_node = search_node->left;
            }
            else
            {
                search_node = search_node->right;
            }
        }
        return search_node;
    }

    void inorderTreeWalk(Node *current_node)
    {
        if (current_node->left != nullptr)
        {
            inorderTreeWalk(current_node->left);
        }
        std::cout << current_node->data << " ";
        if (current_node->right != nullptr)
        {
            inorderTreeWalk(current_node->right);
        }
    }

    void inorderTreeWalk()
    {
        inorderTreeWalk(root);
        std::cout << std::endl;
    }
};

int main()
{
    MyBinaryTree tree;
    tree.insert(5);
    tree.insert(3);
    tree.insert(7);
    tree.insert(2);
    tree.insert(4);
    tree.insert(6);
    tree.insert(8);
    tree.inorderTreeWalk();
    tree.remove(tree.treeSearch(3));
    tree.inorderTreeWalk();
    tree.insert(40);
    tree.inorderTreeWalk();
    return 0;
}