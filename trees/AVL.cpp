#include "AVL.h"
#include <iostream>

using std::cout;
using std::endl;

template <class T>
AVL<T>::AVL() {
    root = nullptr;
}

template <class T>
void AVL<T>::insert(T key) {
    insert(root, key);
}

template <class T>
void AVL<T>::insert(AVLNode<T>*& n, T key) {
    if (n == nullptr) {
        n = new AVLNode<T>(key);
        return;
    }

    if (key > n->key) {
        if (!n->left) {
            n->h++;
        }

        insert(n->right, key);
    } else {
        if (!n->right) {
            n->h++;
        }

        insert(n->left, key);
    }

    int b = balance(n);
    if (b > 1) {
        if(key > n->left->key) {
            rotateSx(n->left);
        }

        rotateDx(n);
    } else if (b < -1) {
        if (key < n->right->key) {
            rotateDx(n->right);
        }

        rotateSx(n);
    }
}

template <class T>
void AVL<T>::rotateDx(AVLNode<T>*& n) {
    AVLNode<T>* tmp = n->left;
    AVLNode<T>* right = tmp->right;

    n->left = right;

    tmp->right = n;
    n = tmp;

    // update the heights
    updateHeight(n->right);
    updateHeight(n);
}

template <class T>
void AVL<T>::rotateSx(AVLNode<T>*& n) {
    AVLNode<T>* tmp = n->right;
    AVLNode<T>* left = tmp->left;

    n->right = left;

    tmp->left = n;
    n = tmp;

    // update the heights
    updateHeight(n->left);
    updateHeight(n);
}

template <class T>
int AVL<T>::balance(AVLNode<T>* n) {
    if (!n->right && !n->left) {
        return 0;
    } else if (!n->right) {
        return n->h;
    } else if (!n->left) {
        return -n->h;
    }

    return n->left->h - n->right->h;
}

template <class T>
AVLNode<T>* AVL<T>::search(T key) {
    return search(root, key);
}

template <class T>
AVLNode<T>* AVL<T>::search(AVLNode<T>* n, T key) {
    if (!n) {
        return nullptr;
    }

    if (key > n->key) {
        return search(n->right, key);
    } else if (key < n->key) {
        return search(n->left, key);
    }

    return n;
}

template <class T>
void AVL<T>::preorder() {
    preorder(root);
}

template <class T>
void AVL<T>::preorder(AVLNode<T>* n) {
    if (!n) {
        return;
    }

    cout << n->key << " ";
    preorder(n->left);
    preorder(n->right);
}

template <class T>
void AVL<T>::inorder() {
    inorder(root);
}

template <class T>
void AVL<T>::inorder(AVLNode<T>* n) {
    if (!n) {
        return;
    }

    inorder(n->left);
    cout << n->key << " ";
    inorder(n->right);
}

template <class T>
void AVL<T>::postorder() {
    postorder(root);
}

template <class T>
void AVL<T>::postorder(AVLNode<T>* n) {
    if (!n) {
        return;
    }

    postorder(n->left);
    postorder(n->right);
    cout << n->key << " ";
}

template <class T>
void AVL<T>::updateHeight(AVLNode<T>*& n) {
    if (!n->left && !n->right) {
        n->h = 0;
    } else if (!n->left)  {
        n->h = n->right->h + 1;
    } else if (!n->right) {
        n->h = n->left->h + 1;
    } else {
        n->h = MAX(n->left->h, n->right->h) + 1;
    }
}