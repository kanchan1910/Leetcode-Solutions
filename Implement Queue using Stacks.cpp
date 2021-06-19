// https://leetcode.com/problems/implement-queue-using-stacks/
class MyQueue
{
public:
    /** Initialize your data structure here. */
    stack<int> input, output;
    MyQueue()
    {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x)
    {
        input.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() 
    {
        if(!output.empty())
        {
            int ans = output.top();
            output.pop();
            return ans;
        }
        while(!input.empty())
        {
            output.push(input.top());
            input.pop();
        }
        int ans = output.top();
        output.pop();
        return ans;
    }
    
    /** Get the front element. */
    int peek()
    {
        if(!output.empty())
        {
            return output.top();
        }
        while(!input.empty())
        {
            output.push(input.top());
            input.pop();
        }
        return output.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty()
    {
        if(input.empty() && output.empty())
        {
            return true;
        }
        return false;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */

// tc push o(1)
// tc pop o(1) amortised
// tc peep o(1) amortised
// tc empty o(1)
// sc o(2n), as used two stacks


// https://practice.geeksforgeeks.org/problems/queue-using-stack/1
class Queue {
    stack<int> input, output;
public:

    void enqueue(int x) 
    {
        input.push(x);
    }

    int dequeue()
    {
        if(!output.empty())
        {
            int ans = output.top();
            output.pop();
            return ans;
        }
        while(!input.empty())
        {
            output.push(input.top());
            input.pop();
        }
        int ans = output.top();
        output.pop();
        return ans;
    }
};


// https://youtu.be/3Et9MrMc02A
