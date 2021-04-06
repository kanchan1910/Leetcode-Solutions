class Solution {
public:
    vector<int> sumZero(int n)
    { vector<int>ans;
     if(n % 2 != 0)
     {
         ans.push_back(0);
         n--;
     }
     int val = 1;
        for(int i = 1; i <= n; i += 2)
        {
            ans.push_back(val);
            ans.push_back(-val);
            val++;
        }
     return ans;
    }
};
