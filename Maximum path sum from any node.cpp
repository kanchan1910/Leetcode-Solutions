
class Solution
{
  public:
  int fun(Node* root, int& ans)
  {
      if(root == NULL)
      {
          return 0;
      }
      int left = fun(root->left, ans);
      int right = fun(root->right, ans);
      int max_sum = max(max(root->data + left, root->data + right), max(root->data, root->data + left + right));
      ans = max(ans, max_sum);
      return max({root->data, root->data + left, root->data + right});
  }
    //Function to return maximum path sum from any node in a tree.
    int findMaxSum(Node* root)
    {
        int ans = INT_MIN;
        fun(root, ans);
        return ans;
    }
};
// https://youtu.be/NIJN63astRc
