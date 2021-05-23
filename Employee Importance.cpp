/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    int getImportance(vector<Employee*> employees, int id)
    {
        unordered_map<int, pair<int, vector<int>>>m;
        for(auto x: employees)
        {
            m[x->id] = {x->importance, x->subordinates};
        }
        int ans = 0;
        queue<int>q;
        q.push(id);
        while(!q.empty())
        {
            int front = q.front();
            ans += m[front].first;
            q.pop();
            for(auto child: m[front].second)
            {
                q.push(child);
            }
        }
        return ans;
    }
};
