class Solution {
public:
    void createMapping(vector<int>& postorder, unordered_map<int, int> &nodeToIndex, int n){
        for(int i = 0; i < n; i++){
            nodeToIndex[postorder[i]] = i;
        }
    }

    TreeNode* solve(vector<int>& preorder, vector<int>& postorder, int &index, int postorderStart, int postorderEnd, int n, unordered_map<int, int>& nodeToIndex){
        if(index >= n || postorderStart > postorderEnd){
            return NULL;
        }

        TreeNode* root = new TreeNode(preorder[index++]);
        if(postorderStart == postorderEnd){
            return root;
        }

        int element = preorder[index];
        int position = nodeToIndex[element];

        root -> left = solve(preorder, postorder, index, postorderStart, position, n, nodeToIndex);
        root -> right = solve(preorder, postorder, index, position + 1, postorderEnd - 1, n, nodeToIndex);

        return root;
    }

    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        int n = preorder.size();
        int preOrderIndex = 0;
        unordered_map<int, int>nodeToIndex;
        createMapping(postorder, nodeToIndex, n);
        TreeNode* ans = solve(preorder, postorder, preOrderIndex, 0, n - 1, n, nodeToIndex);
        return ans;
    }
};