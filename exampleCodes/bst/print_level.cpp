void print_with_level(node* root,int level)
{
    if (root != nullptr) {
	for (int i=0;i<level;i++) {
	    cout << "-";
	}
	cout << root->data << endl;
	print_with_level(root->left,level+1);
	print_with_level(root->right,level+1);
    }
}

void print_indent(node* root) 
{
    print_with_level(root,0);
}
