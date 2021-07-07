long long fun1(vector<long long> v, long long x)
    {
        long long n = v.size();
        long long l = 0;
        long long r = n - 1;
        long long ans = -1;
        while(l <= r)
        {
            int mid = (l + (r - l) / 2);
            if(v[mid] == x)
            {
                ans = mid;
                r = mid - 1;
            }
            else if(v[mid] < x)
            {
                l = mid + 1;
            }
            else if(v[mid] > x)
            {
                r = mid - 1;
            }
        }
        return ans;
    }
    long long fun2(vector<long long> v, long long x)
    {
        long long n = v.size();
        long long l = 0;
        long long r = n - 1;
        long long ans = -1;
        while(l <= r)
        {
            int mid = (l + (r - l) / 2);
            if(v[mid] == x)
            {
                ans = mid;
                l = mid + 1;
            }
            else if(v[mid] < x)
            {
                l = mid + 1;
            }
            else if(v[mid] > x)
            {
                r = mid - 1;
            }
        }
        return ans;
    }
    pair<long,long> indexes(vector<long long> v, long long x)
    {
        long long first = -1, last = -1;
        first = fun1(v, x);
        last = fun2(v, x);
        if(first == -1 && last == -1)
        {
            return {-1, -1};
        }
        return {first, last};
    }

// tc o(logn)
// sc o(1)
