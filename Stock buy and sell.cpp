    vector<vector<int> > stockBuySell(vector<int> A, int n)
    {
        vector<vector<int>>ans;
        for(int i = 1; i < n; i++)
        {
            if(A[i] > A[i - 1])
            {
                vector<int>tmp;
                tmp.push_back(i - 1);
                tmp.push_back(i);
                ans.push_back(tmp);
            }
        }
        return ans;
    }

// tc o(n)
// sc o(1)
