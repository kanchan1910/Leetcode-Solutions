    long long findNth(long long N)
    {
        if(N < 0)
        {
            return 0;
        }
        long long res = 0;
        long long p = 1;
        
        while(N > 0)
        {
            res += p * (N % 9);
            
            N /= 9;
            
            p *= 10;
        }
        
        return res;
    }
