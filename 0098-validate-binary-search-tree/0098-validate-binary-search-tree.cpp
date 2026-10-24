class Solution {
public:
    bool isBST(TreeNode* root, long long min, long long max){
        if(root == NULL){
            return true;
        }

        if(root -> val <= min || root -> val >= max){
            return false;
        }

        bool left = isBST(root -> left, min, root -> val);
        bool right = isBST(root -> right, root -> val, max);
        return left && right;
    }

    bool isValidBST(TreeNode* root) {
        return isBST(root, LLONG_MIN, LLONG_MAX);
    }
};