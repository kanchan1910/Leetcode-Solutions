class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) 
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int sum = 0;
        for(int i = 0; i < n && k > 0; i++)
        {
            if(nums[i] < 0)
            {
                nums[i] = -nums[i];
                k--;
            }
            else if(nums[i] == 0)
            {
                break;
            }
        }
        for(int i = 0; i < n; i++)
        {
            sum += nums[i];
        }
        if(k % 2 != 0)
        {
            int mini = *min_element(nums.begin(), nums.end());
            sum -= 2 * mini;   
        }
        return sum;
    }
};

/*
[4,2,3]
1
[3,-1,0,2]
3
[2,-3,-1,5,-4]
2
[-8,3,-5,-3,-5,-2]
6
*/

