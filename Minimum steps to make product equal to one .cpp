class Solution {
  public:
    int makeProductOne(int arr[], int n)
    {
        int ans = 0;
        int count0 = 0;
        int countneg = 0;
        for(int i = 0; i < n; i++)
        {
            if(arr[i] == -1)
            {
                countneg++;
            }
            if(arr[i] < -1)
            {
                countneg++;
                ans += abs(arr[i] + 1);
            }
            if(arr[i] > 1)
            {
                ans += abs(arr[i] - 1);
            }
            if(arr[i] == 0)
            {
                count0++;
                ans++;
            }
        }
        if(countneg % 2 != 0)
        {
            if(count0 == 0)
            {
                ans += 2;
            }
        }
        return ans;
    }
};
// tc o(n)
// sc o(1)
