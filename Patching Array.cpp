class Solution {
public:
    int minPatches(vector<int>& nums, int n) 
    {
    // count of numbers needed
        int need = 0;
        // we can get all numbers less than or equal to this sum
        long long sum = 0;
        // index of the array
        int i = 0;
        while(sum < n)
        {
            if(i < nums.size() && (sum + 1) >= nums[i])
            {
                sum += nums[i];
                i++;
            }
            else
            {
                need++;
                sum += (sum + 1);
            }
        }
        return need;
    }
};
// tc o(n)
// sc o(1)
