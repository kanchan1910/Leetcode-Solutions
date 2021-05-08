Node* mergeTwoLinkedList(Node* a, Node* b)
{
    Node* tmp = new Node(0);
    Node* res = tmp;
    while(a != NULL && b != NULL)
    {
        if(a->data <= b->data)
        {
            tmp->bottom = a;
            tmp = tmp->bottom;
            a = a->bottom;
        }
        else
        {
            tmp->bottom = b;
            tmp = tmp->bottom;
            b = b->bottom;
        }
    }
    if(a != NULL)
    {
        tmp->bottom = a;
    }
    else
    {
        tmp->bottom = b;
    }
    return res->bottom;
}
Node *flatten(Node *root)
{
  if(root == NULL)
  {
      return NULL;
  }
  if(root->next == NULL)
  {
      return root;
  }
  return mergeTwoLinkedList(root, flatten(root->next));
}
// tc o(summation of all nodes, as we are traversing each node once)
// sc o(1)
