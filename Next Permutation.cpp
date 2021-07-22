class Solution {
public:
    void nextPermutation(vector<int>& nums)
    {
        int n = nums.size();
        int i, j;
        if(n == 1)
        {
            return;
        }
        for(i = n - 2; i >= 0; i--)
        {
            if(nums[i] < nums[i + 1])
            {
                break;
            }
        }
        if(i < 0)
        {
            reverse(nums.begin(), nums.end());
            return;
        }
        for(j = n - 1; j >= i + 1; j--)
        {
            if(nums[j] > nums[i])
            {
                break;
            }
        }
        swap(nums[i], nums[j]);
        reverse(nums.begin() + i + 1, nums.end());
    }
};


// tc o(n)
// sc o(1)

// https://youtu.be/LuLCLgMElus

class Solution {
public:
    void nextPermutation(vector<int>& nums)
    {
        int n = nums.size();
        next_permutation(nums.begin(), nums.end());
    }
};
