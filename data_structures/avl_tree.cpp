#pragma once
#include "avl_tree.h"

/*
 *  Function to insert a new node under given node
 */
template<class T>
void AVL<T>::insert(Node<T>* node, const T& key)
{
    if(node==NULL)
    {
        node = new Node<T>(key);
        numNodes += 1;
    }
    else
    {
        if(key < node->key)
        {
            insert(node->left, key);
        }
        else
        {
            insert(node->right, key);
        }
    }
}

/*
 *  Function to check whether a given node is balanced
 */
template<class T>
int AVL<T>::check_balance(Node<T>* node)
{
    return get_height(node->left) - get_height(node->right);
}

/*
 *  Returns the height of a given node
 */
template<class T>
size_t AVL<T>::get_height(Node<T>* node)
{
    size_t ret_height = 0;
    if(node!=NULL)
    {
        ret_height = node->height;
    }
    return ret_height;
}

/*
 *  Updates the height of a given node
 */
template<class T>
void AVL<T>::update_height(Node<T>* node)
{
    if(node==NULL)
    {

    }
    else if(node->left != NULL && node->right!=NULL)
    {
        node->height = std::max(node->left->height, node->right->height) +1;
    }
    else if(node->left!=NULL)
    {
        node->height = node->left->height+1;
    }
    else
    {
        node->height = node->right->height+1;
    }
}