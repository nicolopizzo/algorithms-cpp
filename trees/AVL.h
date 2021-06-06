#ifndef AVL_H
#define AVL_H

#define MAX(x, y) (x < y ? y : x)

template <class T>
struct AVLNode {
    T key;
    int h;
    AVLNode<T>* left;
    AVLNode<T>* right;

    AVLNode<T>(T k) {
        key = k;
        h = 0;
        left = nullptr;
        right = nullptr;
    }

    AVLNode<T>() {}
};

template <class T>
class AVL {
    AVLNode<T>* root;

    public:
        AVL();

        void insert(T key);
        AVLNode<T>* search(T key);
        void remove(T key);

        void preorder();
        void inorder();
        void postorder();

    private:
        void insert(AVLNode<T>*& n, T key);
        AVLNode<T>* search(AVLNode<T>* n, T key);
        void remove(AVLNode<T>*& n, T key);

        void rotateSx(AVLNode<T>*& n);
        void rotateDx(AVLNode<T>*& n);

        int balance(AVLNode<T>* n);
        void updateHeight(AVLNode<T>*& n);

        void preorder(AVLNode<T>* n);
        void inorder(AVLNode<T>* n);
        void postorder(AVLNode<T>* n);
};

#include "AVL.cpp"

#endif