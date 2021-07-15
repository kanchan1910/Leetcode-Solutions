 int countBits(int N, long long int A[])
    {
       //  brute force
       long long ans = 0;
       for(int i = 0; i < N; i++)
       {
           for(int j = 0; j < N; j++)
           {
               int x = A[i] & A[j];
               int y = A[i] | A[j];
               int countand = __builtin_popcount(x);
               int countor = __builtin_popcount(y);
               ans = (ans + (countor - countand)) % 1000000007;
           }
       }
       return ans % 1000000007;
    }

// tc o(n * n)
// sc o(1)
// TLE



 int countBits(int N, long long int A[])
    {
       long long ans = 0;
       for(int i = 0; i < 32; i++)
       {
           long long count = 0;
           for(int j = 0; j < N; j++)
           {
               if(A[j] & (1 << i))
               {
                   count++;
               }
           }
           ans = (ans + ((count) * (N - count) * 2)) % 1000000007;
       }
       return ans % 1000000007;
    }
    // tc o(n * 32)
    // sc o(1)
    // ACCEPTED
