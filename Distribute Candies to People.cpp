class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people)
    {
        vector<int>v(num_people, 0);
        int num = 1;
        while(candies != 0)
        {
            for(int i = 0; i < num_people; i++)
            {
                if(num <= candies)
                {
                    v[i] += num;
                    candies -= num;
                }
                else
                {
                    v[i] += candies;
                    candies = 0;
                }
                num++;
            }
        }
        return v;
    }
};


class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people)
    {
        vector<int>v(num_people, 0);
        int num = 1;
        while(candies != 0)
        {
            for(int i = 0; i < num_people; i++)
            {
                v[i] += min(candies, num);
                candies -= min(candies, num);
                num++;
            }
        }
        return v;
    }
};
