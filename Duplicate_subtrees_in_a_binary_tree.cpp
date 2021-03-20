string fun(Node* root , unordered_map<string, int>&m)
 {
     if(root == NULL)
     {
         return "#";
     }
    
     string str = "";
      if(root->left == NULL && root->right == NULL)
     {
         str += to_string(root->data);
         return str;
     }
     str += to_string(root->data);
     str += fun(root->left , m);
     str += fun(root->right , m);
     m[str]++;
     return str;
 }
bool dupSub(Node *root)
{
    unordered_map<string,int>m;
    fun(root , m);
    for(auto x : m)
    {
        if( x. second > 1)
        {
            return true;
        }
    }
    return false;
}
