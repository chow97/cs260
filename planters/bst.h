#ifndef BST_H
#define BSH_H
#include <iostream>
#include "box.h"


class bst
{
    public:
        bst();
        bst(const bst& aTable);
        ~bst();
        const bst& operator= (const bst& aTable);

        void insert(const box& data);
        bool remove(int num);
        void inOrder(int start, int stop, char* name);
    private:
        struct node
        {
            box item;
            node * left, * right;
            node(const box& data):item(data), left(0), right(0)
            {
            }
        };
        node * root;	
        
        void insert(node ** root, const box& data);
        bool remove(node ** root, int num);
        void deleteNode(node ** target);
        void destroyTree(node ** root);
        void copyTree(node ** newRoot, node * root);
        void inOrder(node ** root, int start, int stop, char* name);

};
#endif