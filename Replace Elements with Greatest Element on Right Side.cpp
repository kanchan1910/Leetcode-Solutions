class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) 
    {
        int n = arr.size();
        if(n == 1)
        {
            return {-1};
        }
        vector<int>ans(n);
        for(int i = 0; i < n - 1; i++)
        {
            int maxi = -1;
            for(int j = i + 1; j < n ; j++)
            {
                maxi = max(maxi, arr[j]);
            }
            ans[i] = maxi;
        }
        ans[n - 1] = -1;
        return ans;
    }
};
// tc o(n * n)
// sc o(1)


class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) 
    {
        int n = arr.size();
        if(n == 1)
        {
            return {-1};
        }
        vector<int>ans(n);
        stack<int>s;
        int maxi = -1;
        for(int i = n - 1; i >= 0; i--)
        {
            if(s.empty())
            {
                ans[i] = -1;
            }
            else
            {
                ans[i] = maxi;
            }
             s.push(arr[i]);
             maxi = max(maxi, s.top());    
        }
        return ans;
    }
};


// tc o(n)
// sc o(n)
