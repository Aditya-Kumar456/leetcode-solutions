class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>>result;

        if(root == NULL){
            return result;
        }        

        queue<TreeNode*>q;
        q.push(root);
        q.push(NULL);
        vector<int>ans;

        while(!q.empty()){
            TreeNode* temp = q.front();
            q.pop();

            if(temp == NULL){
                result.push_back(ans); // previous level has completed
                ans.clear();
                if(!q.empty()){
                    q.push(NULL); // seperator for next level
                }
            }
            else{
                ans.push_back(temp -> val);
                if(temp -> left){
                    q.push(temp -> left);
                }
                if(temp -> right){
                    q.push(temp -> right);
                }
            }
        }
        reverse(result.begin(), result.end());
        return result;
    }
};