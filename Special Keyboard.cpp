
class Solution
{
public:
    int dp[78];
    long long int fun(int N)
    {
        if(N <= 6)
        {
            return N;
        }
        int mul = 2, ans = N;
        for(int i = N - 3; i >= 1; i--)
        {
            if(dp[i] == -1)
            {
                dp[i] = fun(i);
            }
            ans = max(ans, mul * dp[i]);
            mul++;
        }
        return ans;
    }
    long long int optimalKeys(int N)
    {
        if(N <= 6)
        {
            return N;
        }
        memset(dp, -1, sizeof(dp));
        return fun(N);
    }
};

