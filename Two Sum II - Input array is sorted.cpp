class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target)
    {
        int n = numbers.size();
        int l = 0, r = n - 1;
        while(l < r)
        {
            int sum = numbers[l] + numbers[r];
            if(sum == target)
            {
                return {l + 1, r + 1};
            }
            else if(sum < target)
            {
                l++;
            }
            else if(sum > target)
            {
                r--;
            }
        }
        return {-1, -1};
    }
};
// tc o(n)
// sc o(1)
