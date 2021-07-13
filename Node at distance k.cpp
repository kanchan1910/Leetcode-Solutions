int countkdistanceNode(node *root, node* target, int k)
{
    unordered_map<node*, node*>m;
    queue<node*>par;
    par.push(root);
    while(!par.empty())
    {
        node* front = par.front();
        par.pop();
        if(front == root)
        {
            m[front] = NULL;
        }
        if(front->left != NULL)
        {
            par.push(front->left);
            m[front->left] = front;
        }
        if(front->right != NULL)
        {
            par.push(front->right);
            m[front->right] = front;
        }
    }
    queue<node*>q;
    unordered_set<node*>s;
    q.push(target);
    s.insert(target);
    while(!q.empty() && k > 0)
    {
        k--;
        int size = q.size();
        for(int i = 0; i < size; i++)
        {
            node* front = q.front();
            q.pop();
            if(front->left != NULL && s.find(front->left) == s.end())
            {
                q.push(front->left);
                s.insert(front->left);
            }
            if(front->right != NULL && s.find(front->right) == s.end())
            {
                q.push(front->right);
                s.insert(front->right);
            }
            if(m[front] != NULL && s.find(m[front]) == s.end())
            {
                q.push(m[front]);
                s.insert(m[front]);
            }
        }
    }
    return q.size();
}
