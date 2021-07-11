int atoi(string str)
    {
        int num = 0;
        bool neg = false;
        int i = 0;
        if(str[i] == '-')
        {
            neg = true;
            i++;
        }
        for(; i < str.length(); i++)
        {
            if(str[i] >= '0' && str[i] <= '9')
            {
                num = num * 10 + (str[i] - '0');
            }
            else
            {
                return -1;
            }
        }
        return (neg == true) ? -num : num;
    }

// tc o(n)
// sc o(1)
