/*Given a number K and string str of digits denoting a positive integer, build the largest number possible by performing swap operations on the digits of str at most K times.


Example 1:

Input:
K = 4
str = "1234567"
Output:
7654321
Explanation:
Three swaps can make the
input 1234567 to 7654321, swapping 1
with 7, 2 with 6 and finally 3 with 5
Example 2:

Input:
K = 3
str = "3435335"
Output:
5543333
Explanation:
Three swaps can make the input
3435335 to 5543333, swapping 3 
with 5, 4 with 5 and finally 3 with 4 

Your task:
You don't have to read input or print anything. Your task is to complete the function findMaximumNum() which takes the string and an integer as input and returns a string containing the largest number formed by perfoming the swap operation at most k times.


Expected Time Complexity: O(n!/(n-k)!) , where n = length of input string
Expected Auxiliary Space: O(n)


Constraints:
1 ≤ |str| ≤ 30
1 ≤ K ≤ 10*/

class Solution
{
    public:
    //Function to find the largest number after k swaps.
void fun(string str, int k, string &max, int index)
{
    if(k == 0)
    {
        return;
    }
    char cur_char = str[index];
    char max_char = str[index];
    for(int i = index + 1; i < str.length(); i++)
    {
        if(max_char < str[i])
        {
            max_char = str[i];
        }
    }
    if(cur_char != max_char)
    {
        k--;
    }
    for(int i = index; i < str.length(); i++)
    {
        if(str[i] == max_char)
        {
            swap(str[i], str[index]);
            if(max < str)
            {
                max = str;
            }
            fun(str, k, max, index + 1);
            swap(str[i], str[index]);
        }
    }
}
    string findMaximumNum(string str, int k)
    {
       string max = str;
       fun(str, k, max, 0);
       return max;
    }
};
/*Time Complexity: O(n^k). 
For every recursive call n recursive calls is generated until the value of k is 0. So total recursive calls are O((n)^k).
Space Complexity: O(n). 
The space required to store the output string.
*/


class Solution
{
    public:
    //Function to find the largest number after k swaps.
    void fun(string str, int k, string &max)
    {
        if(k == 0)
        {
            return;
        }
        for(int i = 0; i < str.length(); i++)
        {
            for(int j = i + 1; j < str.length(); j++)
            {
                if(str[i] < str[j])
                {
                 swap(str[i], str[j]);
                 if(max < str)
                 {
                     max = str;
                 }
                 fun(str, k - 1, max);
                 swap(str[i], str[j]);
                }
            }
        }
    }
    string findMaximumNum(string str, int k)
    {
       string max = str;
       fun(str, k, max);
       return max;
    }
};

// TLE
/*
Time Complexity: O((n^2)^k). 
For every recursive call n^2 recursive calls is generated until the value of k is 0. So total recursive calls are O((n^2)^k).
Space Complexity:O(n). 
This is the space required to store the output string.
*/
