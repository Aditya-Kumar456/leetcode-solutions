class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* duplicate = new ListNode(0);
        ListNode* temp = duplicate;
        int carry = 0;
        while (l1 != NULL || l2 != NULL || carry != 0) {
            int sum = carry;
            if (l1 != NULL) {
                sum = sum + l1 -> val;
                l1 = l1 -> next;
            }

            if (l2 != NULL) {
                sum = sum + l2 -> val;
                l2 = l2 -> next;
            }

            carry = sum / 10;
            int digit = sum % 10;
            temp -> next = new ListNode(digit);
            temp = temp -> next;
        }
        return duplicate -> next;
    }
};