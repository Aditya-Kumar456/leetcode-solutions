class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        TreeNode* temp = root;
        while(temp != NULL){
            if(temp -> val == val){
                return temp;
            }

            if(temp -> val > val){
                temp = temp -> left;
            }
            else{
                temp = temp -> right;
            }
        }
        return NULL;
    }
};