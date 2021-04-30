class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) 
    {
        vector<int>arr1;
        int a = 1;
        if(x == 1)
        {
            arr1.push_back(1);
        }
        else
        {
          while(a <= bound)
          {
              arr1.push_back(a);
              a *= x;
          }   
        }
        vector<int>arr2;
        if(y == 1)
        {
            arr2.push_back(1);
        }
        else
        {
            int b = 1;
            while(b <= bound)
            {
                arr2.push_back(b);
                b *= y;
            }   
        }
        unordered_set<int>s;
        for(int i = 0; i < arr1.size(); i++)
        {
            for(int j = 0; j < arr2.size(); j++)
            {
                if(arr1[i] + arr2[j] <= bound)
                {
                    s.insert(arr1[i] + arr2[j]);   
                }
            }
        }
        vector<int>ans;
        for(auto x : s)
        {
            ans.push_back(x);
        }
        return ans;
    }
};
