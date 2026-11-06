class Solution {
public:
    TreeNode* curr;

    void inorder(TreeNode* root){
        if(root == NULL){
            return;
        }


        inorder(root -> left);
        root -> left = NULL;
        curr -> right = root;
        curr = root;
        inorder(root -> right);
    }

    TreeNode* increasingBST(TreeNode* root) {
        TreeNode* dummy = new TreeNode(0);
        curr = dummy;
        inorder(root);
        return dummy -> right;
    }
};