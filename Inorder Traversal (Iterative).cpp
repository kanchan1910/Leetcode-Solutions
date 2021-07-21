    vector<int> inOrder(Node* root)
    {
       vector<int>ans;
       stack<Node*>s;
       Node* cur = root;
       while(cur != NULL || s.size() != 0)
       {
           while(cur != NULL)
           {
               s.push(cur);
               cur = cur->left;
           }
           cur = s.top();
           s.pop();
           ans.push_back(cur->data);
           cur = cur->right;
       }
       return ans;
    }
    // tc o(n)
    // sc o(n)
