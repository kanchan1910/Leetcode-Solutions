class Solution {
public:
    int dp[1005][1005];
    int lcs(string str1, string str2, int n , int m)
    {
     if(n == 0 || m == 0)
      {
         return 0;
      }
        if(dp[n][m] != -1)
        {
            return dp[n][m];
        }
     if(str1[n - 1] == str2[m - 1])
        {
          dp[n][m] = 1 + lcs(str1, str2 , n - 1, m - 1);
        }
        else
        {
           dp[n][m] =  max(lcs(str1, str2, n - 1 , m), lcs(str1, str2, n , m -1)); 
        }
        return dp[n][m];
    }
    int longestPalindromeSubseq(string s) 
    {
        memset(dp, -1 , sizeof(dp));
        int n = s.length();
        string str = s;
        reverse(s.begin(), s.end());
        return lcs(str, s, n , n);
    }
};
// tle 


class Solution {
public:

    int longestPalindromeSubseq(string s) 
    {
       int n = s.length();
       int dp[n + 1][n + 1];
        string str1 = s;
        reverse(s.begin(), s.end());
        string str2 = s;
       for(int i = 0 ; i <= n; i++)
       {
           for(int j = 0 ; j <= n; j++)
           {
               if(i == 0 || j == 0)
               {
                   dp[i][j] = 0;
               }
               else if(str1[i - 1] == str2[j - 1])
               {
                   dp[i][j] = 1 + dp[i - 1][j - 1];
               }
               else if(str1[i -1 ] != str2[j - 1])
               {
                   dp[i][j] = max(dp[i - 1][j] , dp[i][j - 1]);
               }
           }
           
       }
        return dp[n][n];
    }
};
// accepted    method same as LCS
// tc o(n * n)
// sc o(n)


class Solution {
public:

    int longestPalindromeSubseq(string s) 
    {
       int n = s.length();
       int dp[n + 1][n + 1];
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
                }
                else if(s[i] == s[j])
                {
                    dp[i][j] = 2 + dp[i + 1][j - 1];
                }
                else
                {
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[0][n - 1];
    }
};
// accepted 
// tc o(n * n)
// sc o(n)
