#ifndef TABLE_H
#define TABLE_H
//table.h
#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

struct node
{
    int data;
    node * left;
    node * right;;
};

void build(node * & root);  //supplied
void display(node *  root); //supplied
void destroy(node * & root); //supplied

/* ************** PLACE YOUR PROTOTYPE HERE ***************** */

void print_with_level(node* root,int level);
void print_indent(node* root);

int getmax(node* root);

#endif
