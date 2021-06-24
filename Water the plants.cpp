class Solution{
    public:
    int min_sprinklers(int gallery[], int n)
    {
       vector<int>ans(n, -1);
       for(int i = 0; i < n; i++)
       {
           if(gallery[i] >= 0)
           {
               int l = max(0, i - gallery[i]);
               int r =  min(n - 1, i + gallery[i]);
               for(int j = l; j <= r; j++)
               {
                   ans[j] = max(ans[j], r);
               }
           }
       }
       int res = 0;
       for(int i = 0; i < n;)
       {
           if(ans[i] == -1)
           {
               return -1;
           }
           res++;
           i = ans[i] + 1;
       }
       return res;
    }
};

// tc o(n)
// sc o(n)
