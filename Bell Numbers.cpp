    int bellNumber(int n)
    {
       int bell[n + 1][n + 1];
       bell[0][0] = 1;
       for(int i = 1; i <= n; i++)
       {
           bell[i][0] = bell[i - 1][i - 1]% 1000000007;
           for(int j = 1; j <= n; j++)
           {
               bell[i][j] = (bell[i][j - 1]% 1000000007 + bell[i - 1][j - 1]% 1000000007) % 1000000007;
           }
       }
       return bell[n][0];
    }
