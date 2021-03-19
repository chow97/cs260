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

        void insert(const box& data);
        bool remove(int num);
        bool contains(int num, char* name)const;
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
        int size;
        
        void insert(node ** root, const box& data);
        bool contains(node * root, int num, char* name) const;
        bool remove(node ** root, int num);
        void deleteNode(node ** target);
        //void display(ostream& out, node * root, int level) const;
        void destroyTree(node ** root);
        void copyTree(node ** newRoot, node * root);
        void inOrder(node ** root, int start, int stop, char* name);

};
#endif