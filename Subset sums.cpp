 void subsets(int index, int n, int sum, vector<int>arr, vector<int>& v)
    {
        if(index == n)
        {
            v.push_back(sum);
            return;
        }
        // include
        subsets(index + 1, n, sum + arr[index], arr, v);
        // exclude
        subsets(index + 1, n, sum, arr, v);
    }
    vector<int> subsetSums(vector<int> arr, int n)
    {
        vector<int>v;
        subsets(0, n, 0, arr, v);
        sort(v.begin(), v.end());
        return v;
    }
// tc o(2^n)
// sc o(2^n)
