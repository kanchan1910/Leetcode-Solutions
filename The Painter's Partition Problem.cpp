// see all other methods of this problem
// https://www.geeksforgeeks.org/painters-partition-problem/


  bool isValid(int arr[], int n, int k, long long cur_min)
    {
        long long painters = 1;
        long long cur_sum = 0;
        for(long long i = 0; i < n; i++)
        {
            if(arr[i] > cur_min)
            {
                return false;
            }
            if(cur_sum + arr[i] > cur_min)
            {
                painters++;
                cur_sum = arr[i];
                if(painters > k)
                {
                    return false;
                }
            }
            else
            {
                cur_sum += arr[i];
            }
        }
        return true;
    }
    long long minTime(int arr[], int n, int k)
    {

        long long sum = 0;
        for(int i = 0; i < n; i++)
        {
            sum += arr[i];
        }
        long long l = 0, r = sum;
        long long ans = INT_MAX;
        while(l <= r)
        {
            long long mid = (l + (r - l) / 2);
            if(isValid(arr, n, k, mid) == true)
            {
                ans = mid;
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        return ans;
    }
    
// tc o(nlogm), where m is the sum of all boards length
// sc o(1)
