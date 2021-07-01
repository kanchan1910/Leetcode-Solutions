class Solution {
public:
    int maxArea(vector<int>& height)
    {
        int n = height.size();
        int area = 0;
        int l = 0, r = n - 1;
        while(l < r)
        {
            int width = (r - l);
            if(height[l] == height[r])
             {
                 area = max(area, height[l] * width);
                 l++, r--;
             }
            else if(height[l] < height[r])
             {
                 area = max(area, height[l] * width);
                 l++;
             }
            else if(height[l] > height[r])
            {
                area = max(area, height[r] * width);
                r--;
            }
        }
        return area;
    }
};

     
