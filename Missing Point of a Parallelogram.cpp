/*
Given three coordinate points A, B and C, find the missing point D such that ABCD can be a parallelogram. If there are multiple such points, find the lexicographically smallest coordinate.

Example 1:

Input:
A = (3, 2)
B = (3, 4)
c = (2, 2)
Output:
2.000000 0.000000
Explanation: There are two options for 
point D : (2, 4) and (2, 0) such that ABCD 
forms a parallelogram. Since (2, 0) is 
lexicographically smaller than (2, 4). Hence,
(2, 0) is the answer.
Your Task:
You don't need to read input or print anything. Your task is to complete the function findPoint() which takes three list of integers A[], B[] and C[] and return D[] list of two numbers with a precision of 6 decimal places where first element of D[ ] denote x coordinate and second element of D[ ] denote y coordinate.

Expected Time Complexity: O(1)
Expected Auxiliary Space: O(1)

Constraints:
1 ≤ x, y ≤ 1000 , where x and y denote coordinates of points A, B and C.

*/
    //// Since the opposite sides are equal, AD = BC and AB = CD, we can calculate the co-ordinates of the missing point (D) as: 
       int ax = A[0];
       int ay = A[1];
       int bx = B[0];
       int by = B[1];
       int cx = C[0];
       int cy = C[1];
        vector<vector<double>> v;
        v.push_back({ax+cx-bx,ay+cy-by});
        v.push_back({ax+bx-cx,ay+by-cy});
        v.push_back({bx+cx-ax,by+cy-ay});
        sort(v.begin(),v.end());
        return v[0];
//         If we draw three random points (unordered) on a plane then 3 parallelograms can be formed. Below figure might help you visualize the possible positions of vertex 'D'.
// Now, as we know that in a parallelogram, diagonals bisect each other. We can easily find out the co-ordinates of D without calculating the slope or length.
