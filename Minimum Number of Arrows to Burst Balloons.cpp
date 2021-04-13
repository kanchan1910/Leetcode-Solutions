class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) 
    {
        int ans = 0;
        int n = points.size();
        if(n == 1)
        {
            return n;
        }
        sort(points.begin(), points.end());
        int tmp = points[0][1];
        for(int i = 1; i < n; i++)
        {
            if(points[i][0] > tmp)
            {
                ans++;
                tmp = points[i][1];
            }
            else
            {
                tmp = min(tmp, points[i][1]); 
            }
        }
        return ans + 1;
    }
};
