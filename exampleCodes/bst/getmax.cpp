int getmax(node* root)
{
    int max = 0;
    if (root->right != nullptr) {
	max = getmax(root->right);
    } else {
	max = root->data;
    }
    return max;
}
