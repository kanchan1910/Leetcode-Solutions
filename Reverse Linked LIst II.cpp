class Solution {
public:
    ListNode* reverse(ListNode* head)
    {
        ListNode* prev = NULL;
        while(head != NULL)
        {
            ListNode* next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right)
    {
        if(left == right)
        {
            return head;
        }
        ListNode* left_node = NULL;
        ListNode* right_node = NULL;
        ListNode* left_node_prev = NULL;
        ListNode* right_node_next = NULL;
        ListNode* cur = head;
        int count = 0;
        bool f = false;
        while(cur != NULL && count <= right)
        {
            count++;
            if(count < left)
            {
                f = true;
                left_node_prev = cur;
            }
            if(count == left)
            {
                left_node = cur;
            }
            if(count == right)
            {
                right_node = cur;
                right_node_next = cur->next;
            }
            cur = cur->next;
        }
        right_node->next = NULL;
        reverse(left_node);
        if(f == true)
        {
           left_node_prev->next = right_node;   
        }
        else
        {
            head = right_node;
        }
        left_node->next = right_node_next;   
        return head;
    }
};
// tc o(n) + o(n)
// sc o(1)


class Solution {
public:

    ListNode* reverseBetween(ListNode* head, int left, int right)
    {
        if(left == right)
        {
            return head;
        }
        ListNode* left_node = NULL;
        ListNode* right_node = NULL;
        ListNode* left_node_prev = NULL;
        ListNode* right_node_next = NULL;
        ListNode* cur = head;
        ListNode* prev = NULL;
        int count = 0;
        bool f = false;
        while(cur != NULL && count <= right)
        {
            count++;
            if(count < left)
            {
                f = true;
                left_node_prev = cur;
            }
            if(count == left)
            {
                left_node = cur;
            }
            if(count == right)
            {
                right_node = cur;
                right_node_next = cur->next;
            }
            ListNode* next = cur->next;
            if(count > left && count <= right)
            {
                cur->next = prev;
            }
            prev = cur;
            cur = next;
        }

        if(f == true)
        {
           left_node_prev->next = right_node;   
        }
        else
        {
            head = right_node;
        }
        left_node->next = right_node_next;   
        return head;
    }
};
// tc o(n)
// sc o(1)


