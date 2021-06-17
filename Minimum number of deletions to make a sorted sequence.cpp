	int minDeletions(int arr[], int n) 
	{ 
	    int dp[n];
	    dp[0] = 1;
	    for(int i = 1; i < n; i++)
	    {
	        dp[i] = 1;
	        for(int j = 0; j < i; j++)
	        {
	            if(arr[j] < arr[i])
	            {
	                dp[i] = max(dp[i], dp[j] + 1);
	            }
	        }
	    }
	    return n - *max_element(dp, dp + n);
	} 
	// variation of longest increasing order problem

//  n(constant) - longest = minimum
