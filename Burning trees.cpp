// https://practice.geeksforgeeks.org/problems/burning-tree/1
class Solution {
    public:
  unordered_map<Node*, Node*>m;
    int finding_parents(Node* root)
    {
        queue<pair<Node*, Node*>>q;
        q.push({root, NULL});
        m[root] = NULL;
        while(!q.empty())
        {
                    pair<Node*, Node*>p = q.front();
                    m[p.first] = p.second;
                    q.pop();
                    if(p.first->left != NULL)
                    {
                        q.push({p.first->left,p.first});
                    }
                    if(p.first->right != NULL)
                    {
                        q.push({p.first->right,p.first});
                    }
        }
    }
    Node* search(int value, Node* root)
    {
        if(root == NULL)
        {
            return NULL;
        }
        if(root->data == value)
        {
            return root;
        }
        Node* left = search(value, root->left);
        if(left == NULL)
        {
            return search(value, root->right);
        }
        else
        {
            return left;
        }
    }
    int minTime(Node* root, int target) 
    {
        finding_parents(root);
        int ans = 0;
        Node* tar = search(target, root);
        queue<Node*>q;
        unordered_set<int>s;
        s.insert(tar->data);
        q.push(tar);
        while(!q.empty())
        {
            bool f= false;
            int n = q.size();
            for(int i = 0; i < n; i++)
            {
            Node* front = q.front();
            q.pop();
            if(front->left != NULL && s.find(front->left->data) == s.end())
            {
                f = true;
                s.insert(front->left->data);
                q.push(front->left);
            }
             if(front->right != NULL && s.find(front->right->data) == s.end())
            {
                f = true;
                s.insert(front->right->data);
                q.push(front->right);
            }
             if(m[front] != NULL && s.find(m[front]->data) == s.end())
            {
                f = true;
                s.insert(m[front]->data);
                q.push(m[front]);
            }
            }
            if(f == true)
            {
                ans++;
            }
        }
return ans;
    }
};
