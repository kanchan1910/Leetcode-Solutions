// https://www.geeksforgeeks.org/remove-bst-keys-outside-the-given-range/
class Solution {
    public:
    Node* removekeys(Node* root, int l, int r) 
    {
        if(root == NULL)
        {
            return NULL;
        }
        root->left = removekeys(root->left, l, r);
        root->right = removekeys(root->right, l, r);
        if(root->data <= r && root->data >= l)
        {
            return root;
        }
        if(root->data < l)
        {
            Node* rchild = root->right;
            delete root;
            return rchild;
        }
        if(root->data > r)
        {
            Node* lchild = root->left;
            delete root;
            return root->left;
        }
        return root;
    }
};
