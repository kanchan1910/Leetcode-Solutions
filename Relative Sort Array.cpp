class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2)
    {
        int f[10001] = {0};
        int n1 = arr1.size();
        int n2 = arr2.size();
        for(int i = 0; i < n1; i++)
        {
            f[arr1[i]]++;
        }
        vector<int>ans;
        for(int i = 0; i < n2; i++)
        {
            while(f[arr2[i]] > 0)
            {
                ans.push_back(arr2[i]);
                f[arr2[i]]--;
            }
        }
        for(int i = 0; i <= 1000; i++)
        {
             while(f[i] > 0)
                {
                    ans.push_back(i);
                    f[i]--;
                }
        }
        return ans;
    }
};
// tc o(n)
// sc o(n)
