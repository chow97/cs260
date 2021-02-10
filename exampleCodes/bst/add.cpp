node* add(node* root,int value)
{
    if (root == nullptr) {
	node* tmp = new node;
	tmp->data = value;
	tmp->left = nullptr;
	tmp->right = nullptr;
	return tmp;
    }

    if (value < root->data) 
	root->left  = add(root->left, value); 
    else if (value > root->data) 
	root->right = add(root->right, value);    
  
    return root; 
}
