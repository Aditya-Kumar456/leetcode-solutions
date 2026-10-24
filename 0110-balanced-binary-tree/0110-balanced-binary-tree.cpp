class Solution {
public:
    pair<bool, int>isFastBalanced(TreeNode* root){
        if(root == NULL){
            pair<bool, int>p = make_pair(true, 0);
            return p;    
        }

        pair<bool, int>left = isFastBalanced(root -> left);
        pair<bool, int>right = isFastBalanced(root -> right);

        bool leftAns = left.first;
        bool rightAns = right.first;
        bool condition = abs(left.second - right.second) <= 1;

        pair<bool, int>ans;
        ans.second = max(left.second, right.second) + 1;

        if(leftAns && rightAns && condition){
            ans.first = true;
        }
        else{
            ans.first = false;
        }
        return ans;
    } 

    bool isBalanced(TreeNode* root) {
        return isFastBalanced(root).first;
    }
};