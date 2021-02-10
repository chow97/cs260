void traverse_inorder(node* root) 
{
    if (root != nullptr) {
	traverse_inorder(root->left);
	cout << root->data << endl;
	traverse_inorder(root->right);
    }
}

