class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == NULL){
            return false;
        }        

        targetSum -= root -> val;
        
        if(root -> left == NULL && root -> right == NULL){
            if(targetSum == 0){
                return true;
            }
        }

        bool leftAns = hasPathSum(root -> left, targetSum);
        bool rightAns = hasPathSum(root -> right, targetSum);

        if(leftAns || rightAns){
            return true;
        }
        else{
            return false;
        }
    }
};