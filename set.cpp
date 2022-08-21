#include <bits/stdc++.h>
using namespace std;

int max(int a, int b)
{
    return (a > b) ? a : b;
}

struct treeNode
{

    int data;

    int height;

    treeNode *left = nullptr, *right = nullptr;

    treeNode(int x)
    {
        data = x;
        height = 1;
    }
};

class avltree
{
public:
    treeNode *root = NULL;

    int height(treeNode *node)
    {
        if (node == NULL)
            return 0;
        else
            return node->height;
    }

    int balance_factor(treeNode *node)
    {
        if (node == NULL)
            return 0;
        else
            return height(node->left) - height(node->right);
    }

    treeNode *left_rotate(treeNode *node)
    {
        treeNode *child = node->right;
        treeNode *child_leftchild = child->left;

        child->left = node;
        node->right = child_leftchild;

        child->height = 1 + max(height(child->left), height(child->right));

        node->height = 1 + max(height(node->left), height(node->right));
        return child;
    }

    treeNode *right_rotate(treeNode *node)
    {
        treeNode *child = node->left;
        treeNode *child_rightchild = child->right;

        child->right = node;
        node->left = child_rightchild;

        child->height = 1 + max(height(child->left), height(child->right));

        node->height = 1 + max(height(node->left), height(node->right));
        return child;
    }

    void insert(int x, treeNode *node)
    {

        if (x == node->data)

            return;
        if (x < node->data)
        {
            if (node->left == NULL)
                node->left = new treeNode(x);
            else
                insert(x, node->left);
        }
        else
        {
            if (node->right == NULL)
                node->right = new treeNode(x);
            else
                insert(x, node->right);
        }

        node->height = 1 + max(height(node->left), height(node->right));

        int bf = balance_factor(node);

        if (bf > 1 && x < node->left->data)
            right_rotate(node);
        if (bf > 1 && x > node->left->data)
        {
            node->left = left_rotate(node->left);
            right_rotate(node);
        }

        if (bf < -1 && x < node->right->data)
        {
            node->right = right_rotate(node->right);
            left_rotate(node);
        }
        if (bf < -1 && x > node->right->data)
            left_rotate(node);
    }

    void insert(int x)
    {
        if (root == NULL)
            root = new treeNode(x);
        else
            insert(x, root);
    }

    bool search(int x, treeNode *node)
    {
        if (node == nullptr)
            return 0;
        if (x < node->data)
            return search(x, node->left);
        else if (x > node->data)
            return search(x, node->right);
        else
            return 1;
    }

    bool search(int x)
    {
        return search(x, root);
    }
};
int main()
{
    avltree x;
    int n = 1e5;
    srand(time(0));
    vector<int> v;

    for (int i = 0; i < n; i++)
    {
        v.push_back(rand());
    }
    for (int i = 0; i < n; i++)
    {
        x.insert(v[i]);
    }
    for (int i = 0; i < n; i++)
    {
        x.search(i);
    }
}