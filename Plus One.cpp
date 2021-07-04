    vector<int> increment(vector<int> arr ,int N) 
    {
        int sum = 0;
        int carry = 1;
        vector<int>ans;
        for(int i = N - 1; i >= 0; i--)
        {
            sum = arr[i] + carry;
            ans.push_back(sum % 10);
            carry = sum / 10;
        }
        if(carry != 0)
        {
            ans.push_back(carry);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }

// tc o(n)
// sc o(1)
