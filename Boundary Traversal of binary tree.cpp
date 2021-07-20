   void leftboundary(Node* root, vector<int>& ans)
    {
     if(root == NULL)
     {
         return;
     }
     if(root->left != NULL || root->right != NULL)
     {
         ans.push_back(root->data);
     }
     if(root->left != NULL)
     {
         leftboundary(root->left, ans);
     }
     else if(root->right != NULL)
     {
         leftboundary(root->right, ans);
     }
    }
    void rightboundary(Node* root, vector<int>& ans)
    {
     if(root == NULL)
     {
         return;
     }
     if(root->right != NULL)
     {
         rightboundary(root->right, ans);
     }
     else if(root->left != NULL)
     {
         rightboundary(root->left, ans);
     }
     if(root->left != NULL || root->right != NULL)
     {
         ans.push_back(root->data);
     }
    }
    void leafboundary(Node* root, vector<int>& ans)
    {
        if(root == NULL)
        {
            return;
        }
        leafboundary(root->left, ans);
        if(root->left == NULL && root->right == NULL)
        {
            ans.push_back(root->data);
        }
        leafboundary(root->right, ans);
    }
    vector <int> printBoundary(Node *root)
    {
        vector<int>ans;
        if(root == NULL)
        {
            return ans;
        }
        ans.push_back(root->data);
        if(root->left == NULL && root->right == NULL)
        {
            return ans;
        }
        leftboundary(root->left, ans);
        leafboundary(root, ans);
        rightboundary(root->right, ans);
        return ans;
    }
