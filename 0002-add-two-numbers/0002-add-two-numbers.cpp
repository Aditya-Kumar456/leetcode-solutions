class Solution {
public:
    void insertAtTail(ListNode* &head, ListNode* &tail, int val){
    ListNode* temp = new ListNode(val);

    if(head == NULL){
        head = temp;
        tail = temp;
        return;
    }
    tail -> next = temp;
    tail = temp;
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

    ListNode* add(ListNode* first, ListNode* second){
        int carry = 0;

        ListNode* ansHead = NULL;
        ListNode* ansTail = NULL;

        while(first != NULL || second != NULL || carry != 0){
            int val1 = 0;
            if(first != NULL){
                val1 = first -> val;
            }

            int val2 = 0;
            if(second != NULL){
                val2 = second -> val;
            }

            int sum = val1 + val2 + carry;
            int digit = sum % 10;
            insertAtTail(ansHead, ansTail, digit);
            carry = sum / 10;

            if(first != NULL){
                first = first -> next;
            }
            if(second != NULL){
                second = second -> next;
            }
        }
        return ansHead;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        return add(l1, l2);
    }
};