int maxSubarraySum(int arr[], int n){
       int cur_sum = arr[0];
       int max_sum = arr[0];
       for(int i = 1; i < n; i++)
       {
           cur_sum = max(arr[i], cur_sum + arr[i]);
           max_sum = max(max_sum, cur_sum);
       }
       return max_sum;
    }
// tc o(n)
// sc o(n)
