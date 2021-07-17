class Solution {
public:
    ListNode* middle(ListNode* head)
    {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    ListNode* reverse(ListNode* head)
    {
        ListNode* prev = NULL;
        ListNode* cur = head;
        while(cur != NULL)
        {
            ListNode* next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        return prev;
    }
    void reorderList(ListNode* head) 
    {
        // base cases
        if(head == NULL || head->next == NULL || head->next->next == NULL)
        {
            return;
        }
        
        // find middle of the linked list
        // method 1 , find length and the find middle node
        // o(n) + o(n)
        // method 2, using slow and fast pointers
        // o(n)
        ListNode* middlenode = middle(head);
        
        // reverse the second half of the linked list
        ListNode* reversedlist = reverse(middlenode->next);
        middlenode->next = NULL;
        
        // merge the first half and the reversed second half of the linked list accordingly
        ListNode* cur1 = head;
        ListNode* cur2 = reversedlist;
        while(cur1 != NULL && cur2 != NULL)
        {
            ListNode* next1 = cur1->next;
            ListNode* next2 = cur2->next;
            cur1->next = cur2;
            cur2->next = next1;
            cur1 = next1;
            cur2 = next2;
        }
        
    }
