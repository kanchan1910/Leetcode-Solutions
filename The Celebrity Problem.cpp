class Solution 
{
    public:
    int celebrity(vector<vector<int> >& M, int n) 
    {
       stack<int>s;
       for(int i = 0; i < n; i++)
       {
           s.push(i);
       }
       while(s.size() >= 2)
       {
           int a = s.top();
           s.pop();
           int b = s.top();
           s.pop();
           if(M[a][b] == 0)
           {
               s.push(a);
           }
           else
           {
               s.push(b);
           }
       }
       int ans = s.top();
       for(int i = 0; i < n; i++)
       {
           if(i != ans)
           {
               if(M[i][ans] == 0 || M[ans][i] == 1)
               {
                   return -1;
               }
           }
       }
       return ans;
    }
};
// tc o(n)
// sc o(n)

/// https://youtu.be/CiiXBvrX-5A
