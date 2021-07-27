
class Solution {
public:
    Node* copyRandomList(Node* head)
    {
        // method 1 
        // using extra space - unordered map
        if(head == NULL)
        {
            return NULL;
        }
        unordered_map<Node*, Node*>m;
        Node* cur = head;
        while(cur != NULL)
        {
            Node* copy = new Node(cur->val);
            m[cur] = copy;
            cur = cur->next;
        }
        cur = head;
        while(cur != NULL)
        {
            m[cur]->next = m[cur->next];
            m[cur]->random = m[cur->random];
            cur = cur->next;
        }
        return m[head];
    }
};
//tc o(n)+o(n)~o(n)

//sc o(n)

// https://youtu.be/VNf6VynfpdM


class Solution {
public:
    Node* copyRandomList(Node* head)
    {
        // method 2
        if(head == NULL)
        {
            return NULL;
        }
        // step1 
        // make copy of each node,
        // and link them together side-by-side in a single list.
        
        Node* cur = head;
        while(cur != NULL)
        {
            Node* next = cur->next;
            Node* copy = new Node(cur->val);
            cur->next = copy;
            copy->next = next;
            cur = next;
        }
        // step2
        // assign random pointers to the copy nodes.
        
        cur = head;
        while(cur != NULL)
        {
            if(cur->random == NULL)
            {
                cur->next->random = NULL;
            }
            else
            {
                cur->next->random = cur->random->next;   
            }
            cur = cur->next->next;
        }
        // step3
        // restore the original list, and extract the copy list.
        
        cur = head;
        Node* dummy = new Node(0);
        Node* copy_cur = dummy;
        while(cur != NULL)
        {
            Node* next = cur->next->next;
            copy_cur->next = cur->next;
            cur->next = next;
            copy_cur = copy_cur->next;
            cur = next;
        }
        return dummy->next;
    }
};
//tc o(n)+o(n)+o(n)~o(n)

//sc o(1)

// https://youtu.be/VNf6VynfpdM
