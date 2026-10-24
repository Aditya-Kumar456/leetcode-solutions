class Solution {
public:
    void solve(TreeNode* root, int targetSum, vector<int>path, vector<vector<int>>&ans){
        if(root == NULL){
            return;
        }

        path.push_back(root -> val);
        targetSum -= root -> val;

        if(root -> left == NULL && root -> right == NULL){
            if(targetSum == 0){
                ans.push_back(path);
            }
        }

        solve(root -> left, targetSum, path, ans);
        solve(root -> right, targetSum, path, ans);
        path.pop_back();

    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>>ans;
        vector<int>path;
        solve(root, targetSum, path, ans);
        return ans;        
    }
};