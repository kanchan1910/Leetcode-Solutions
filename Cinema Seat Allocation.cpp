class Solution {
public:
    bool fun(int s, int e, vector<int>& row)
    {
        for(int seat: row)
        {
            if(seat >= s && seat <= e)
            {
                return false;
            }
        }
        return true;
    }
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats)
    {
        unordered_map<int, vector<int>>m;
        for(int i = 0; i < reservedSeats.size(); i++)
        {
            if(reservedSeats[i][1] == 1 || reservedSeats[i][1] == 10)
            {
                continue;
            }
            m[reservedSeats[i][0]].push_back(reservedSeats[i][1]);
        }
        int ans = (n - m.size()) * 2;
        for(auto &x: m)
        {
            if(fun(2, 5, x.second) == true|| fun(4, 7, x.second) == true || fun(6, 9, x.second) == true)
            {
                ans++;
            }
        }
        return ans;
    }
};
