#include "BST.h"
#include <iostream>

template <class T>
BST<T>::BST() {
    root = nullptr;
}

template <class T>
BST<T>::BST(T* arr, int n) {
    root = nullptr;

    for (int i = 0; i < n; i++) {
        insert(arr[i]);
    }
}

template <class T>
void BST<T>::insert(T value) {
    insert(root, value);
}

template <class T>
void BST<T>::insert(BSTNode<T>*& n, T value) {
    if (n == nullptr) {
        n = new BSTNode<T>(value);
        return;
    }

    if (value > n->value) {
        insert(n->right, value);
    } else {
        insert(n->left, value);
    }
}

template <class T>
bool BST<T>::search(T value) {
    return search(root, value);
}

template <class T>
bool BST<T>::search(BSTNode<T>* n, T value) {
    if (n == nullptr) {
        return false;
    }

    if (value > n->value) {
        return search(n->right, value);
    } else if (value < n->value) {
        return search(n->left, value);
    }

    return true;
}

template <class T>
BSTNode<T>*& BST<T>::min(BSTNode<T>*& n) {
    if (n->left == nullptr) {
        return n;
    }

    return min(n->left);
}

template <class T>
BSTNode<T>*& BST<T>::max(BSTNode<T>*& n) {
    if (n->right == nullptr) {
        return n;
    }

    return max(n->right);
}

template <class T>
void BST<T>::remove(T value) {
    remove(root, value);
}

template <class T>
void BST<T>::remove(BSTNode<T>*& n, T value) {
    if (n == nullptr) {
        return;
    }

    if (value > n->value) {
        remove(n->right, value);
    } else if (value < n->value) {
        remove(n->left, value);

    // Key found
    } else {
        if (n->left && n->right) {
            // Search for maxmimum in left subtree
            BSTNode<T>*& m = max(n->left);

            // Copy key in n
            n->value = m->value;

            // Delete maximum in left subtree
            remove(m, m->value);
        } else if (n->left) {
            n = n->left;
        } else if (n->right) {
            n = n->right;
        } else {
            n = nullptr;
        }
    }
}

template <class T>
void BST<T>::preorder() {
    preorder(root);

    std::cout << std::endl;
}

template <class T>
void BST<T>::preorder(BSTNode<T>* n) {
    if (n == nullptr) {
        return;
    }

    std::cout << n->value << " ";
    preorder(n->left);
    preorder(n->right);
}

template <class T>
void BST<T>::postorder() {
    postorder(root);

    std::cout << std::endl;
}

template <class T>
void BST<T>::postorder(BSTNode<T>* n) {
    if (n == nullptr) {
        return;
    }

    postorder(n->left);
    postorder(n->right);
    std::cout << n->value << " ";
}

template <class T>
void BST<T>::inorder() {
    inorder(root);
    
    std::cout << std::endl;
}

template <class T>
void BST<T>::inorder(BSTNode<T>* n) {
    if (n == nullptr) {
        return;
    }

    inorder(n->left);
    std::cout << n->value << " ";
    inorder(n->right);
}

template <class T>
bool BST<T>::isEmpty() {
    return root;
}

template <class T>
BST<T>::~BST() {
    deleteNode(root);
}

template <class T>
void BST<T>::deleteNode(BSTNode<T>*& n) {
    if (n == nullptr) {
        return;
    }

    deleteNode(n->left);
    deleteNode(n->right);
    delete n;
}