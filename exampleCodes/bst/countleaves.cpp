int countLeaves(node* root)
{
    if (root != nullptr) {
	if ((root->left == nullptr) && (root->right == nullptr)) {
	    return 1;
	}

	return countLeaves(root->left) + countLeaves(root->right);
    }
    return 0;
}

int countLeaves2(node* root)
{
    int c = 0;
    if (root != nullptr) {
	if ((root->left == nullptr) && (root->right == nullptr)) {
	    c = 1;
	} else {
	    c = countLeaves2(root->left) + countLeaves2(root->right);
	}
    }
    return c;
}
