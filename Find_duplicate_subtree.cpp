
class Solution {
public:
    unordered_map<string , int>m;
      string fun(TreeNode* root, vector<TreeNode*>&ans)
    {
        if(root == NULL)
        {
            return "#";
        }

        string str = "";
          str += to_string(root->val) + "#"; // due to this case 
// [2,1,11,11,null,1]
          str += fun(root->left , ans) + "#";
          str += fun(root->right, ans);
          m[str]++;
    //      cout << str << endl;
          if(m[str] == 2)
          {
              ans.push_back(root);
          }
          return str;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root)
    {
     vector<TreeNode*>ans;   
        fun(root, ans);
        return ans;
    }
};
