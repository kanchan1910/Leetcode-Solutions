class Solution {
public:
    int heightChecker(vector<int>& h) 
    {
        int n = h.size();
        vector<int>ex;
        ex = h;
        sort(ex.begin(), ex.end());
        int ans = 0;
        for(int i = 0; i < n ; i++)
        {
            if(h[i] != ex[i])
            {
                ans++;
            }
        }
        return ans;
    }
};
// sc o(n)
// tc o(nlogn)
