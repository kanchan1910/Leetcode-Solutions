void fun(Node* root, int k, vector<int>& ans)
{
    if(root == NULL)
    {
        return;
    }
    if(k == 0)
    {
        ans.push_back(root->data);
        return;
    }
    fun(root->left, k - 1, ans);
    fun(root->right, k - 1, ans);
}
// function should print the nodes at k distance from root
vector<int> Kdistance(struct Node *root, int k)
{
    
    vector<int>ans;
    fun(root, k, ans);
    return ans;
}
