class Solution {
public:
    int longestPalindrome(string word1, string word2) {
       string s = word1 + word2;
       int n = s.length();
       int dp[n + 1][n + 1];
       int ans = INT_MIN;
        for(int i = 0 ; i < n ; i++)
        {
            dp[i][i] = 1;
        }
        for(int len = 2; len <= n ; len++)
        {
            for(int i = 0 ; i < n - len + 1; i++)
            {
                int j = i + len - 1;
                if(s[i] == s[j] && len == 2)
                {
                    dp[i][j] = 2;
     // this extra condition added for the constraint that there should be non-empty subsequence from both the given words.
                 if(i < word1.length() && j >= word1.length())
                    {
                        ans = max(ans , dp[i][j]);
                    }
                }
                else if(s[i] == s[j])
                {
                    dp[i][j] = 2 + dp[i + 1][j - 1];
                    if(i < word1.length() && j >= word1.length())
                    {
                        ans = max(ans , dp[i][j]);
                    }
                }
                else
                {
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
                }
            }
        }
        return ans == INT_MIN ? 0 : ans;
    }
};

// rest all is same as the longest palindromic subsequence 
// tc o(n * n)
// sc o(n)
 
