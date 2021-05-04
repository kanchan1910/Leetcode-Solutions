
Problem Statement: Let’s define a Beautiful Function F(x) in such a way: Add 1 to the value of x, if the result of addition contains any trailing zeros then remove them all.

Example:
F(11) = 12
F(19) = 2 (20 –> 2)
F(99) = 1(100 –> 10 –> 1)

Let’s define a number to be reachable from x , if we can apply Beautiful Function some number of times (possibly zero) to x and get that number as result
Ex. 102 can be reachable from 1099 as F(F(1099)) = F(101) = 102
You are given a number N . Calculate how many numbers are reachable from N.
Input Format:
The first line contains an integer N. denoting the given number.

Constrains: 1 <= N <= 10^9
Sample Input	Sample output	Explanation
1	9	1,2,3,4,5,6,7,8,9 are reachable from 1.


l=[]
def fun(n):
    global l
    if n in l:
        return
    else:
        l.append(n)
        n=n+1
        n=str(n)
        n=n.rstrip('0')
        n=int(n)
        fun(n)
      
      
n=int(input())
fun(n)
print(len(l))



Problem Statement: There is a unique ATM in Wonderland. Imagine this ATM as an array of numbers. You can withdraw cash only from either ends of the array. Sarah wants to withdraw X amount of cash from the ATM. What are the minimum number of withdrawals Sarah would need to accumulate X amount of cash. If it is not possible for Sarah to withdraw X amount , return -1.
Input Format: The first line contains an integer N, denoting the number of elements in ATM.
Each line I of  the N subsequent lines (Where 0 <= I <N) contains an integer describing the cash in ATM.
The next line contains an integer X, denoting the total amount to withdraw.
Constrains:
1 <= N <= 10^5
1 <= ATM[i] <= 10^5
1 <= X <=10^5
Sample Input/Output:
Sample Input	Sample Output	Explanation
2 1 1 3	-1	The total amount of cash in the ATM is 2, hence Sarah cannot withdraw an amount of 3.


a=int(input())
b=[]
 
for i in range(a):
    temp=int(input())
    b.append(temp)
 
c=int(input())
if(sum(b)<c):
    print(-1)
    exit(0)
 
sum1=0
i=0
j=len(b)-1
minv=99999
 
while(i<len(b) and sum1<=c):
    sum1=sum1+b[i]
    i=i+1
i=i-1
r=i+1
flag=0
 
if(sum1==c and r<minv):
    flag=1
    minv=r
 
while(1):
    if(j>=0 and sum1+b[j]<=c):
        sum1=sum1+b[j]
        j=j-1
        r=r+1
    elif(i>=0):
        sum1=sum1-b[i]
        i=i-1
        r=r-1
    else:
        break
    if(sum1==c and r<minv):
        minv=r
 
if(sum1==c and r<minv):
    minv=r
if(minv==99999):
    print(-1)
else:
    print(minv)
