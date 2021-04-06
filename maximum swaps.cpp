class Solution {
public:
    int maximumSwap(int num)
    {
        string str = to_string(num);
        string want = str;
        sort(want.begin(), want.end(), greater<int>());
        for(int i = 0 ; i < str.length(); i++)
        {
            if(str[i] != want[i])
            {
                int index = str.rfind(want[i]);
                swap(str[i], str[index]);
                break;
            }
        }
        return stoi(str);
    }
};



// str 2736 ~ 7236
// want 7632  (7,1)(6,3)(3,2)(2,0)
    
 // str 9173 ~  9713
// want 9731 (9,0)(7,2)(3,3)(1,1)


// str 98368 ~ 98863
// want 98863  (9,0)(8,1)(8,5)(6,3)(3,2)(3,4)

// str 1993 ~ 9913
// want 9931 
