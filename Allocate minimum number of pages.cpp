
class Solution 
{
    public:
    bool isValid(int arr[], int n, int m, int cur_min)
    {
        int students = 1;
        int cur_sum = 0;
        for(int i = 0; i < n; i++)
        {
            if(arr[i] > cur_min)
            {
                return false;
            }
            if(cur_sum + arr[i] > cur_min)
            {
                students++;
                cur_sum = arr[i];
                if(students > m)
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
    //Function to find minimum number of pages.
    int findPages(int arr[], int n, int m) 
    {
        if(m > n)
        {
            return -1;
        }
        long long sum = 0;
        for(int i = 0; i < n; i++)
        {
            sum += arr[i];
        }
        int l = 0, r = sum;
        int ans = INT_MAX;
        while(l <= r)
        {
            int mid = (l + r) / 2;
            if(isValid(arr, n, m, mid) == true)
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
};

/// tc o(nlogn)
/// sc o(1)



// See aditya verma video for reference
