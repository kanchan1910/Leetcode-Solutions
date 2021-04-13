class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) 
    {
        int n = arr.size();
        int max_so_far = INT_MIN;
        int ans = 0;
        for(int i = 0; i < n; i++)
        {
            max_so_far = max(max_so_far, arr[i]);
            if(max_so_far == i)
            {
                ans++;
            }
        }
        return ans;
    }
};
