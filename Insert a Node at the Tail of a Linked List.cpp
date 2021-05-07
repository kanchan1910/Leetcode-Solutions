// https://www.hackerrank.com/challenges/insert-a-node-at-the-tail-of-a-linked-list/problem

SinglyLinkedListNode* insertNodeAtTail(SinglyLinkedListNode* head, int data) {
    if(head == NULL)
    {
        SinglyLinkedListNode* node = new SinglyLinkedListNode(data);
        return node;
    }
	SinglyLinkedListNode*cur = head;
    while(cur->next != NULL)
    {
        cur = cur->next;
    }
    SinglyLinkedListNode* node = new SinglyLinkedListNode(data);
    cur->next = node;
    return head;
    
}
