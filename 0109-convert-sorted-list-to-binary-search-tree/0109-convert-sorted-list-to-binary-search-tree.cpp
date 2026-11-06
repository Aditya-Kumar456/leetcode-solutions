class Solution {
public:
    ListNode* getMiddle(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = NULL;

        while(fast != NULL && fast -> next != NULL){
            prev = slow;
            slow = slow -> next;
            fast = fast -> next -> next;
        }

        if(prev != NULL){
            prev -> next = NULL;
        }

        return slow;
    }
    
    TreeNode* sortedListToBST(ListNode* head) {
        if(head == NULL){
            return NULL;
        }

        ListNode* mid = getMiddle(head);
        TreeNode* root = new TreeNode(mid -> val);

        if(head == mid){
            return root;
        }

        root -> left = sortedListToBST(head);
        root -> right = sortedListToBST(mid -> next);
        return root;
    }
};