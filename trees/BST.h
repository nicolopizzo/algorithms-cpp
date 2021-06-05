#ifndef BST_H
#define BST_H

template <class T>
struct BSTNode {
    T value;
    BSTNode<T>* left;
    BSTNode<T>* right;

    BSTNode(T v) {
        value = v;
        left = nullptr;
        right = nullptr;
    }
};

template <class T>
class BST {
    BSTNode<T>* root;

    public:
        BST();
        BST(T*, int);
        void insert(T value);
        bool search(T value);
        void remove(T value);

        void preorder();
        void postorder();
        void inorder();

        bool isEmpty();

        ~BST();

    private:
        void insert(BSTNode<T>*& n, T value);
        bool search(BSTNode<T>* n, T value);
        void remove(BSTNode<T>*& n, T value);

        void preorder(BSTNode<T>* n);
        void postorder(BSTNode<T>* n);
        void inorder(BSTNode<T>* n);

        BSTNode<T>*& min(BSTNode<T>*& n);
        BSTNode<T>*& max(BSTNode<T>*& n);

        void deleteNode(BSTNode<T>*& n);
};

#include "BST.cpp"

#endif