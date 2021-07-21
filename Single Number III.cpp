class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) 
    {
        long long n = nums.size();
        long long xxor = 0;
        for(int i = 0; i < n; i++)
        {
            xxor ^= nums[i];
        }
        // xxor = x ^ y
        // we need to find the values of x and y
        // so if we find out the first position of the set bit and the divide the array into two sets, one having set bit at that position and another set having 0 bit at that position, so xor at that postion have set bit means , either of x or y will have set bit at that postion and the another one will have zzero bit at that position, so eventually , x and y will be in the two diff sets, so we can easily find them
        long long set_bit_no;
        set_bit_no = xxor & (~(xxor) + 1);
        long long side1 = 0, side2 = 0;
        for(int i = 0; i < n; i++)
        {
            if((set_bit_no & nums[i]))
            {
                side1 ^= nums[i];
            }
            else
            {
                side2 ^= nums[i];
            }
        }
        return {(int)side1, (int)side2};
    }
};

// tc o(n)
// sc o(1)
