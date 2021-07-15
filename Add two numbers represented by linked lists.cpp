
class Solution
{
    public:
    Node* reverse(Node* head)
    {
        Node* prev = NULL;
        Node* cur = head;
        while(cur != NULL)
        {
            Node* next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        return prev;
    }
    //Function to add two numbers represented by linked list.
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
       first = reverse(first);
       second = reverse(second);
       int carry = 0;
       Node* dummy = new Node(0);
       Node* tmp = dummy;
       while(first != NULL || second != NULL || carry != 0)
       {
           int sum = 0;
           if(first != NULL)
           {
               sum += first->data;
               first = first->next;
           }
           if(second != NULL)
           {
               sum += second->data;
               second = second->next;
           }
           sum += carry;
           carry = sum / 10;
           Node* node = new Node(sum % 10);
           tmp->next = node;
           tmp = tmp->next;
       }
       return dummy->next = reverse(dummy->next);
    }
};
