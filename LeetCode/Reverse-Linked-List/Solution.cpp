1class Solution {
2public:
3    ListNode* reverseList(ListNode* head) {
4        if(head == NULL || head -> next == NULL){
5            return head;
6        }
7
8        ListNode* smallNode = reverseList(head -> next);
9        head -> next -> next = head;
10        head -> next = NULL;
11
12        return smallNode;
13    }
14};