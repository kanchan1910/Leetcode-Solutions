    int findPlatform(int arr[], int dep[], int n)
    {
        sort(arr, arr + n);
        sort(dep, dep + n);
        int ans = 1;
        int platform = 1;
        int i = 1, j = 0;
        while(i < n && j < n)
        {
            if(arr[i] <= dep[j])
            {
                platform++;
                i++;
            }
            else if(arr[i] > dep[j])
            {
                platform--;
                j++;
            }
            ans = max(ans, platform);
        }
        return ans;
    }
// tc o(nlogn)
// sc o(1)
