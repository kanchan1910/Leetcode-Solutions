vector<int> twoOddNum(int Arr[], int N)  
    {
        int xxor = 0;
        for(int i = 0; i < N; i++)
        {
            xxor ^= Arr[i];
        }
        // xxor = x ^ y
        // x = ? , y = ?
        // now we need to find the first set bit in the xxor
        // for this
        int set_bit_no;
        set_bit_no = xxor & (~(xxor) + 1);
        // set bit is comming at a position means, one of the x or y will hve set bit at that position and the other will have 0 at that position
        // so both of them will be in different set;
        int x = 0, y = 0;
        for(int i = 0; i < N; i++)
        {
            if(Arr[i] & set_bit_no)
            {
                x ^= Arr[i];
            }
            else
            {
                y ^= Arr[i];
            }
        }
        if(x <= y)
        {
            return {y, x};
        }
        else
        {
            return {x, y};
        }
    }

// tc o(n)
// sc o(1)
