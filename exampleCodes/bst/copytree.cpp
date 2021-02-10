node* copyOf(node* root){

    if (root == nullptr)
        return nullptr;

    node* newroot = new node;
    newroot->data = root->data;

    newroot->left = copyOf(root->left);
    newroot->right = copyOf(root->right);

    return newroot;
}
