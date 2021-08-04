class Solution{
public:
    int dp[105][105];
    int fun(int n, int m)
    {
        if(n > m)
        {
            return 0;
        }
        if(n == 0)
        {
            return 1;
        }
        if(dp[n][m] != -1)
        {
            return dp[n][m];
        }
        return dp[n][m] = fun(n - 1, m / 2) + fun(n, m - 1);
    }
    int numberSequence(int m, int n)
    {
        memset(dp, -1, sizeof(dp));
        return fun(n, m);
    }
};
