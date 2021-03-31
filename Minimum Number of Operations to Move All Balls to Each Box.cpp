class Solution {
public:
    vector<int> minOperations(string boxes) 
    {
        vector<int>ballindex;
        for(int i = 0 ; i < boxes.length(); i++)
        {
            if(boxes[i] == '1')
            {
                ballindex.push_back(i);
            }
        }
        vector<int>ans;
        int op  = 0;
        for(int i = 0 ; i < boxes.length(); i++)
        {
            op = 0;
            for(int j = 0 ; j < ballindex.size();j++)
            {
                op += abs(ballindex[j] - i);
            }
            ans.push_back(op);
        }
        return ans;
    }
};

// tc O(n * n)
// sc O(n)
