/*

Given an integer n. Return the nth row of the following look-and-say pattern.
1
11
21
1211
111221


Example 1:

Input:
n = 5
Output: 111221
Explanation: The 5th row of the given pattern
will be 111221.
Example 2:

Input:
n = 3
Output: 21
Explanation: The 3rd row of the given pattern
will be 21.
 


Your Task:  
You dont need to read input or print anything. Complete the function lookandsay() which takes integer n as input parameter and returns a string denoting the contents of the nth row of given pattern.


Expected Time Complexity: O(2n)
Expected Auxiliary Space: O(2n-1)  


Constraints:
1 <= n <= 30
https://www.geeksforgeeks.org/look-and-say-sequence/
*/
    string lookandsay(int n)
    {
        if(n == 1)
        {
            return "1";
        }
        if(n == 2)
        {
            return "11";
        }
        string prev = "11";
        for(int i = 3; i <= n; i++)
        {
            prev += "#";
            int n = prev.length();
            int count = 1;
            string tmp_ans = "";
            for(int j = 1; j < n; j++)
            {
                if(prev[j] == prev[j - 1])
                {
                    count++;
                }
                else
                {
                    tmp_ans += to_string(count);
                    tmp_ans += prev[j - 1];
                    count = 1;
                }
            }
            prev = tmp_ans;
        }
        return prev;
    }
