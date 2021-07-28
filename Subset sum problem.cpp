
    bool isSubsetSum(int N, int arr[], int sum)
    {
         bool dp[sum + 1][N + 1];
    
        for(int i = 0; i <= sum; i++)
        {
             dp[i][0] = false;
        }
    
        for(int i = 0; i <= N; i++)
        {
            dp[0][i] = true;
        }
    
        for(int i = 1; i <= sum; i++)
        {
            for(int j = 1; j <= N; j++)
            {
                if(arr[j - 1] > i)
                {
                    dp[i][j] = dp[i][j-1];   
                }
                
                else
                {
                    dp[i][j] = dp[i][j-1] || dp[i - arr[j - 1]][j - 1];
                }
            }
        }
        return dp[sum][N];
    }
