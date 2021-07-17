	// naive
 void rearrangeEvenOdd(Node *head)
    {
       int len = 0;
       Node* cur = head;
       while(cur != NULL)
       {
           len++;
           cur = cur->next;
       }
       if(len % 2 != 0)
       {
           Node* cur1 = head;
           Node* cur2 = head->next;
           Node* fix2 = head->next;   
           while(cur2 != NULL)
           {
               cur1->next = cur2->next;
               cur2->next = cur1->next->next;
               cur1 = cur1->next;
               cur2 = cur2->next;   
           }
           cur1->next = fix2;
       }
       else
       {
           Node* cur1 = head;
           Node* cur2 = head->next;
           Node* fix2 = head->next;
           while(cur2->next != NULL)
           {
               cur1->next = cur2->next;
               cur2->next = cur1->next->next;
               cur1 = cur1->next;
               cur2 = cur2->next;   
           }
           cur1->next = fix2;
       }
    }
    // tc o(n) + o(n)
    
    
    // optimized
    
        void rearrangeEvenOdd(Node *head)
    {
          Node* cur1 = head;
          Node* cur2 = head->next;
          Node* fix2 = head->next;   
          while(cur2 != NULL && cur2->next != NULL)
          {
              cur1->next = cur2->next;
              cur2->next = cur1->next->next;
              cur1 = cur1->next;
              cur2 = cur2->next;   
          }
          cur1->next = fix2;
    }
    // tc o(n)
