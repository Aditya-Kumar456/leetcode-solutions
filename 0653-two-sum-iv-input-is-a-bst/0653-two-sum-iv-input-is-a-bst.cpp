class Solution {
public:
    void inorder(TreeNode* root, vector<int>&ans){
        if(root == NULL){
            return;
        }

        inorder(root -> left, ans);
        ans.push_back(root -> val);
        inorder(root -> right, ans);
    } 

    bool findTarget(TreeNode* root, int k) {
        vector<int>inorderVal;
        inorder(root, inorderVal);
        int i = 0, j = inorderVal.size() - 1;
        while(i < j){
            int sum = inorderVal[i] + inorderVal[j];
            if(k == sum){
                return true;
            }
            else if(sum > k){
                j--;
            }
            else{
                i++;
            }
        }
        return false;
    }
};