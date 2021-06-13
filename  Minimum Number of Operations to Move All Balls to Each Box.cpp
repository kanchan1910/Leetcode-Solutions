class Solution {
public:
    vector<int> minOperations(string boxes)
    {
        int n = boxes.length();
        vector<int>ans(n);
        vector<int>tmp;
        for(int i = 0; i < n; i++)
        {
            if(boxes[i] == '1')
            {
              tmp.push_back(i);   
            }
        }
        for(int i = 0; i < n; i++)
        {
            int sum = 0;
            for(int j = 0; j < tmp.size(); j++)
            {
                sum += abs(i - tmp[j]);
            }
            ans[i] = sum;
        }
        return ans;
    }
};
