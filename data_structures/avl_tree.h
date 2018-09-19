#pragma once

#include<iostream>

template<class T>
class Node
{
    public:
    T key;
    Node<T>* left;
    Node<T>* right;
    size_t height;

    Node(T key, Node<T>* right = NULL, Node<T>* left = NULL)
    {
        this->key=key;
        this->left=left;
        this->right=right;
        this->height=1;
    }
};

template<class T>
class AVL
{
    private:
    Node<T>* rootNode;
    size_t numNodes;

    public:
    AVL(T init_key)
    {
        rootNode = new Node(init_key, NULL, NULL);
        numNodes = 1;
    }

    void insert(Node<T>* node, const T& key);

    size_t get_height(Node<T>* node);

    void update_height(Node<T>* node);

    int check_balance(Node<T>* node);

    void rotate_right(Node<T>* node);

    void rotate_left(Node<T>* node);

};