class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) 
    {
        vector<int>ans;
        int n = num.size();
        int carry = k;
        for(int i = n - 1; i >= 0; i--)
        {
            int sum = num[i] + carry;
            ans.push_back(sum % 10);
            carry = sum / 10;
        }
        while(carry > 0)
        {
            ans.push_back(carry % 10);
            carry = carry / 10;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
