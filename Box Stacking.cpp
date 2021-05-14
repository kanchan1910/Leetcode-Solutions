  static bool com(pair<int , pair<int, int>>& a, pair<int, pair<int, int>>& b)
    {
        return (a.second.first * a.second.second) > (b.second.second * b.second.first);
    }
    int maxHeight(int height[],int width[],int length[],int n)
    {
     //STEP-1:Make an array of box (to store-> h,w,l)
    int len = 3*n;
    vector<pair<int, pair<int, int>>>v;

    for(int i = 0; i < n; i++)
    {
        int a = height[i];
        int b = max(width[i], length[i]);
        int c = min(width[i], length[i]);
        v.push_back({a, {b, c}});
         a = width[i];
         b = max(height[i], length[i]);
         c = min(height[i], length[i]);
        v.push_back({a, {b, c}});
         a = length[i];
         b = max(height[i], width[i]);
         c = min(height[i], width[i]);
        v.push_back({a, {b, c}});
    }
    sort(v.begin(), v.end(), com);
       //STEP-3: Find LIS
       int dp[len];
       for(int i = 0; i < len; i++)
       {
           dp[i] = v[i].first;
       }
       int ans = INT_MIN;
       for(int i = 1; i < len; i++)
       {
           for(int j = 0; j < i; j++)
           {
               if(v[i].second.second < v[j].second.second && v[i].second.first < v[j].second.first)
               {
                   dp[i] = max(dp[i], dp[j] + v[i].first);
               }
           }
           ans = max(ans, dp[i]);
       }
       return ans;
    }
