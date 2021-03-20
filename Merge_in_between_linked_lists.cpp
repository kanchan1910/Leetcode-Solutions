class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        
        int counta = 1;
        ListNode *temp1 = list1;
        while (counta < a){
            temp1 = temp1->next;
            counta++;
        }                                //Gets the pointer to a
        
		int countb = 1;
        ListNode *temp2 = list1;
        while(countb <= b){
            temp2 = temp2->next;
            countb++;
        }                                //Gets the pointer to b
        
		ListNode *tail=list2;
        while(tail->next != NULL){
            tail=tail->next;
        }                               //Gets the pointer to the tail of list2
        
		
		temp1->next=list2;              //set the next pointer of a to the head of list2
        
		tail->next = temp2->next;      //set next of tail of list2 to the pointer to b
        
		return list1;                   //return the original list i.e. list1
        
    }
};
