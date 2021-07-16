class Solution {
public:
    int thirdMax(vector<int>& nums)
    {
        int n = nums.size();
        long first = LONG_MIN, second = LONG_MIN, third = LONG_MIN;
        for(int i = 0; i < n; i++)
        {
            if(first < nums[i])
            {
                third = second;
                second = first;
                first = nums[i];
            }
            else if(second < nums[i] && nums[i] != first)
            {
                third = second;
                second = nums[i];
            }
            else if(third < nums[i] && nums[i] != first && nums[i] != second)
            {
                third = nums[i];
            }
        }
        return third == LONG_MIN ? first : third;
    }
};
// tc o(n)
// sc o(1)
