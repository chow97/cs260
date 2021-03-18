#include "bst.h"
using namespace std;

bst::bst(): root(NULL), size(0)
{
}

bst::bst(const bst& aTable):root(NULL), size(aTable.size)
{
	if(this != &aTable) 
    {
        destroyTree(&root);
        copyTree(&root, aTable.root);
    }
}
void bst::copyTree (node ** newRoot, node * root)
{
	if(root)
	{
		//copy root
		*newRoot = new node(root->item);
		copyTree(&(*newRoot)->left, root->left);
		copyTree(&(*newRoot)->right, root->right);
	}
	else
	{
		*newRoot = NULL;
	}
}

bst::~bst()
{
	destroyTree(&root); 
}
void bst::destroyTree (node ** root)
{
	if(*root)
	{
		destroyTree(&(*root)->left);
		destroyTree(&(*root)->right);
		delete *root;
		root = NULL;
	}
}

void bst::insert (const box& data)
{	
	insert(&root, data);
}

void bst::insert (node ** root, const box& data)
{
	if(! *root)
	{
		*root = new node(data);
		size++;
	}
	else if(data < (*root)->item)
	{
		insert(&((*root)->left), data);
	}
	else
	{
		insert(&((*root)->right), data);
	}
}

bool bst::contains(int num, char* name) const
{
	return contains(root, num, name);
}

bool bst::contains(node * root, int num, char* name) const
{
	if (! root)
		return false;
	else if(num == root->item.getNum() && strcmp(name, root->item.getName()) == 0)
		return true;
	else if(num < root->item.getNum())
		return contains(root->left, num, name);
	else
		return contains(root->right, num, name);
}

bool bst::remove (int num)
{
	return remove(&root, num);
}

bool bst::remove (node ** root, int num)
{
	if(! *root)
		return false;
	else if(num == (*root)->item.getNum()) {
		deleteNode(root);
		return true;
		}
	else if (num < (*root)->item.getNum())
		return remove(&((*root)->left), num);
	else
		return remove(&((*root)->right), num);
}

void bst::deleteNode (node ** target)
{
	node * temp;

	if(!(*target)->left && !(*target)->right)
	{
		delete *target;
		*target = NULL;
	}
	else if(!(*target)->left)
	{
		temp = *target;
		*target = (*target)->right;
		temp->right = NULL;
		delete temp;
	}
	else if(!(*target)->right)
	{
		temp = *target;
		*target = (*target)->left;
		temp->left = NULL;
		delete temp;
	}
	else
	{
		node * prev = NULL;
		node * curr = (*target)->right;
		while(curr->left)
		{
			prev = curr;
			curr = curr->left;
		}

		(*target)->item = curr->item;

		if(!prev)
		{
			(*target)->right = curr->right;
		}
		else
		{
			prev->left = curr->right;	
		} 

		curr->right = NULL;
		delete curr;
	}
	size--;
}