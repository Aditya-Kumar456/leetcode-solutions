class Solution {
public:
    void inorder(TreeNode* root, vector<int>& ans){
        if(root == NULL){
            return;
        }

        inorder(root -> left, ans);
        ans.push_back(root -> val);
        inorder(root -> right, ans);
    }

    TreeNode* inorderToBST(int start , int end, vector<int>& ans){
        if( start > end){
            return NULL;
        }

        int mid = (start + end) / 2;
        TreeNode* root = new TreeNode(ans[mid]);
        root -> left = inorderToBST(start, mid - 1, ans);
        root -> right = inorderToBST(mid + 1, end, ans);

        return root;
    }

    TreeNode* balanceBST(TreeNode* root) {
        vector<int>inorderVal;
        inorder(root, inorderVal);
        int n = inorderVal.size() - 1;
        return inorderToBST(0, n, inorderVal);
    }
};