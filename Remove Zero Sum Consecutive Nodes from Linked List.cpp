class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head)
    {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        int sum = 0;
        ListNode* cur = dummy;
        unordered_map<int, ListNode*>m;
        while(cur != NULL)
        {
            sum += cur->val;
            if(m.find(sum) != m.end())
            {
              ListNode* temp = m[sum]->next;
                int nowsum = sum;
                while(temp != cur)
                {
                    nowsum += temp->val;
                    m.erase(nowsum);
                    temp = temp->next;
                }
                m[sum]->next = cur->next;
            }
            else
            {
                m[sum] = cur;
            }
            cur = cur->next;
        }
        return dummy->next;
    }
};
