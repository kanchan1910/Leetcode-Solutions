int intersectPoint(Node* head1, Node* head2)
{
    unordered_map<Node*, int>m;
    while(head1 != NULL)
    {
        m[head1] = 1;
        head1 = head1->next;
    }
    while(head2 != NULL)
    {
        if(m.find(head2) != m.end())
        {
            return head2->data;
        }
        head2 = head2->next;
    }
    return 0;
}


// tc O(n1 + n2)
// sc O(n1)


// burte force 
// tc O(n1 * n2)
// sc O(1)
// for each node of one linked list compare to each other node of linked list 2




//Function to find intersection point in Y shaped Linked Lists.
int intersectPoint(Node* head1, Node* head2)
{
    Node* s1 = head1;
    Node* s2 = head2;
    int len1 = 0, len2 = 0;
    while(head1 != NULL)
    {
        len1++;
        head1 = head1->next;
    }
    while(head2 != NULL)
    {
        len2++;
        head2 = head2->next;
    }
    head1 = s1, head2 = s2;
    if(len1 < len2)
    {
        int diff = len2 - len1;
        while(diff--)
        {
            head2 = head2->next;
        }
          while(head1 != NULL)
            {
            if(head1 == head2)
            {
                return head1->data;
            }
            head1 = head1->next;
            head2 = head2->next;
            }
    }
    else
    {
         int diff = len1 - len2;
            while(head1 != NULL && diff > 0)
            {
                head1 = head1->next;
                diff--;
            }
            while(head1 != NULL && head2 != NULL)
            {
            if(head1 == head2)
            {
                return head1->data;
            }
            head1 = head1->next;
            head2 = head2->next;
            }
    }
   return 0; 
}


// tc O(n1) + O(n2) + O(abs(n1 - n2)) + O(min(n1, n2))
// sc O(1)



//Function to find intersection point in Y shaped Linked Lists.
int intersectPoint(Node* head1, Node* head2)
{
  if(head1 == NULL || head2 == NULL)
  {
      return NULL;
  }
  Node* a = head1;
  Node* b = head2;
  while(a != b)
  {
      a = a == NULL ? head2 : a->next; 
      b = b == NULL ? head1 : b->next; 
  }
  return a->data;
}


// tc O(2 * max(n1, n2))
// sc O(1)
