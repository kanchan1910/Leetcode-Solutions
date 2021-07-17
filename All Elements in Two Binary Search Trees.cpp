
class Solution {
public:
    void inorder(TreeNode* root, vector<int>&tmp)
    {
        if(root == NULL)
        {
            return;
        }
        inorder(root->left, tmp);
        tmp.push_back(root->val);
        inorder(root->right, tmp);
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) 
    {
        vector<int>tmp1, tmp2;
        inorder(root1, tmp1);
        inorder(root2, tmp2);
        int i = 0, j = 0;
        vector<int>ans;
        while(i < tmp1.size() && j < tmp2.size())
        {
            if(tmp1[i] < tmp2[j])
            {
                ans.push_back(tmp1[i]);
                i++;
            }
            else
            {
                ans.push_back(tmp2[j]);
                j++;
            }
        }
        while(i < tmp1.size())
        {
            ans.push_back(tmp1[i]);
            i++;
        }
        while(j < tmp2.size())
        {
            ans.push_back(tmp2[j]);
            j++;
        }
        return ans;
    }
};
// tc o(N)
// sc o(N)
