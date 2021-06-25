
class Solution
{
    public:
    int dp[10005];
    int fun(int n, int x, int y, int z)
    {
        if(n == 0)
        {
            return 0;
        }
        if(dp[n] != -1)
        {
            return dp[n];
        }
        int op1 = INT_MIN, op2 = INT_MIN, op3 = INT_MIN;
        if(n >= x)
        {
            op1 = fun(n - x, x, y, z);
        }
        if(n >= y)
        {
            op2 = fun(n - y, x, y, z);
        }
        if(n >= z)
        {
            op3 = fun(n - z, x, y, z);
        }
        return dp[n] = 1 + max({op1, op2, op3});
    }
    //Function to find the maximum number of cuts.
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        memset(dp, -1, sizeof(dp));
        return fun(n, x, y, z) < 0 ? 0 : fun(n, x, y, z) ;
    }
};
// https://youtu.be/O0N4xn38Ncg
// tc o(n)
// sc o(n)
