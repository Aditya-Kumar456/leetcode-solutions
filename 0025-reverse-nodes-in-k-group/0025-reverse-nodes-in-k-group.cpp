class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL){
            return NULL;
        }

        ListNode* temp = head;
        int count = 0;
        while(temp != NULL && count < k){
            temp = temp -> next;
            count++;
        }

        if(count < k){
            return head;
        }

        ListNode* curr = head;
        ListNode* forward = NULL;
        ListNode* prev = NULL;
        count = 0;
        while(curr != NULL && count < k){
            forward = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = forward;
            count++;
        }

        if(forward != NULL){
            head -> next = reverseKGroup(forward, k);
        }
        return prev;
    }
};