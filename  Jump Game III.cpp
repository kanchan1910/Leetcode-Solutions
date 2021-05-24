class Solution {
public:
    
    bool canReach(vector<int>& arr, int start)
    { 
        unordered_set<int>s;
        int n = arr.size();
        queue<pair<int, int>>q;
        q.push({start, arr[start]});
        if(arr[start] == 0)
        {
            return true;
        }
        while(!q.empty())
        {
         int front_value = q.front().second;
         int front_index = q.front().first;
         q.pop();
         int newvalue1 = front_index + front_value;
         int newvalue2 = front_index - front_value;
         if((newvalue1 >= 0 && newvalue1 < n && arr[newvalue1] == 0) || (newvalue2 >= 0 && newvalue2 < n && arr[newvalue2] == 0))
         {
             return true;
         }
            if(newvalue1 >= 0 && newvalue1 < n && s.find(newvalue1) == s.end())
            {
                q.push({newvalue1, arr[newvalue1]});
                s.insert(newvalue1);
            }
            if(newvalue2 >= 0 && newvalue2 < n && s.find(newvalue2) == s.end())
            {
                q.push({newvalue2, arr[newvalue2]});
                s.insert(newvalue2);
            }
        }
        return false;
    }
};
