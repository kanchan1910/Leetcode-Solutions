class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) 
    {
        // with extra space
        unordered_map<int, int>m;
        int n = nums.size();
        for(int i = 0; i < n; i++)
        {
            m[nums[i]]++;
        }
        vector<int>ans;
        for(int i = 1; i <= n; i++)
        {
            if(m.find(i) == m.end())
            {
                ans.push_back(i);
            }
        }
        return ans;
    }
};
// tc o(n)
// sc o(n)

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) 
    {
        // without extra space      
        int n = nums.size();
        vector<int>ans;
        for(int i = 0; i < n; i++)
        {
            int index = abs(nums[i]) - 1;
            if(nums[index] > 0)
            {
                nums[index] = -nums[index];
            }
        }
        for(int i = 0; i < n; i++)
        {
            if(nums[i] > 0)
            {
                ans.push_back(i + 1);
            }
        }
        return ans;
    }
};
// tc o(n)
// sc o(1)
