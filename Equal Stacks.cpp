// https://www.hackerrank.com/challenges/equal-stacks/problem
int equalStacks(vector<int> h1, vector<int> h2, vector<int> h3)
{
    int sum1 = 0, sum2 = 0, sum3 = 0;
    for(int i = 0; i < h1.size(); i++)
    {
        sum1 += h1[i];
    }
    for(int i = 0; i < h2.size(); i++)
    {
        sum2 += h2[i];
    }
    for(int i = 0; i < h3.size(); i++)
    {
        sum3 += h3[i];
    }
    if(sum1 == sum2 && sum2 == sum3)
    {
        return sum1;
    }
    int i = 0, j = 0, k = 0;
    while(true)
    {
        if(i == h1.size() || j == h2.size() || k == h3.size())
        {
            return 0;
        }
        if(sum1 >= sum2 && sum1 >= sum3)
        {
            sum1 -= h1[i];
            i++;
        }
        else if(sum2 >= sum1 && sum2 >= sum3)
        {
            sum2 -= h2[j];
            j++;
        }
        else if(sum3 >= sum1 && sum3 >= sum2)
        {
            sum3 -= h3[k];
            k++;
        }
        if(sum1 == sum2 && sum2 == sum3)
        {
            return sum1;
        }
    }
    return 0;
}
