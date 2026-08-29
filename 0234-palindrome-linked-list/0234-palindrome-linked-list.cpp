class Solution {
public:
    ListNode* getMiddle(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head -> next;
        while(fast != NULL && fast ->next != NULL){
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        return slow;
    }

    ListNode* reverse(ListNode* head){
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* forward = NULL;
        while(curr != NULL){
            forward = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = forward;
        }
        return prev;
    }

    bool isPalindrome(ListNode* head) {
        if(head == NULL || head -> next == NULL){
            return true;
        }

        ListNode* middle = getMiddle(head);
        ListNode* temp = middle -> next;
        middle -> next = reverse(temp);

        ListNode* head1 = head;
        ListNode* head2 = middle -> next;
        while(head2 != NULL){
            if(head2 -> val != head1 -> val){
                return 0;
            }

            head1 = head1 -> next;
            head2 = head2 -> next;
        }
        return true;
    }
};