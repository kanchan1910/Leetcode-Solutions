// https://practice.geeksforgeeks.org/problems/stack-using-two-queues/1

//Function to push an element into stack using two queues.
queue<int>q1, q2;
void QueueStack :: push(int x)
{
       q2.push(x);
       while(!q1.empty())
       {
           q2.push(q1.front());
           q1.pop();
       }
       swap(q1, q2);
}

//Function to pop an element from stack using two queues. 
int QueueStack :: pop()
{
    if(q1.empty())
    {
        return -1;
    }
    int ans = q1.front();
    q1.pop();
    return ans;
        // Your Code       
}
// sc o(2n)
// tc push o(n)
// tc pop o(1)




class MyStack {
public:
    /** Initialize your data structure here. */
    queue<int>q1, q2;
    MyStack()
    {
        
    }
    
    /** Push element x onto stack. */
    void push(int x)
    {
        q2.push(x);
        while(q1.size() > 0)
        {
            q2.push(q1.front());
            q1.pop();
        }
        swap(q1, q2);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() 
    {
        int ans = q1.front();
        q1.pop();
        return ans;
    }
    
    /** Get the top element. */
    int top() 
    {
        int ans = q1.front();
        return ans;
    }
    
    /** Returns whether the stack is empty. */
    bool empty() 
    {
        return q1.size() == 0 ? true : false;
        
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
 
 // https://leetcode.com/problems/implement-stack-using-queues/
