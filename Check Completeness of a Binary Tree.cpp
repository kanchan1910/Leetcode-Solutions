/* [1,2,3,5,null,7,8] speciaL case*/
class Solution {
public:
    bool isCompleteTree(TreeNode* root) 
    { 
        bool f = false; // indicates non-full node
       queue<TreeNode*>q;
       q.push(root);
       while(!q.empty())
       {
           TreeNode* tmp =  q.front();
           q.pop();
           if(tmp->left != NULL)
           {
               if(f == true)
               {
                   return false;
               }
               q.push(tmp->left);
           }
           else
           {
               f = true;
           }
           if(tmp->right != NULL)
           {
               if(f == true)
               {
                   return false;
               }
               q.push(tmp->right);
           }
           else
           {
               f = true;
           }
       }
        return true;
    }
};
// tc o(n)
// sc o(n)
