class Solution {
public:
    static bool com(vector<int>&a, vector<int>&b)
    {
        if(a[0] == b[0])
        {
            return a[1] < b[1];
        }
        return a[0] < b[0];
    }
    // Variation of longest increasing susbsequence (LIS)
    int findLongestChain(vector<vector<int>>& pairs) 
    {
        /* [[3,4],[2,3],[1,2]] 
         You can select pairs in any order.
        */
      sort(pairs.begin(), pairs.end(), com);
      int n = pairs.size();
      int ans = 1;
      vector<int>dp(n, 1);
      for(int i = 1; i < n; i++)
      {
          for(int j = 0; j < i; j++)
          {
              if(pairs[i][0] > pairs[j][1])
              {
                  dp[i] = max(dp[i], dp[j] + 1);
              }
          }
          ans = max(ans, dp[i]);
      }

        return ans;
    }
};

// tc o(n* n)
// sc o(n)
