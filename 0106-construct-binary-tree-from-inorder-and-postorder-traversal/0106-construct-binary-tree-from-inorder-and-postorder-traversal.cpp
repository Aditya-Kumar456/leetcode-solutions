class Solution {
public:
    void createMapping(vector<int>& inorder, unordered_map<int, int>&nodeToIndex, int n){
        for(int i = 0; i < n; i++){
            nodeToIndex[inorder[i]] = i;
        }
    }

    TreeNode* solve(vector<int>& inorder, vector<int>& postorder, int &index, int inorderStart, int inorderEnd, int n, unordered_map<int, int>&nodeToIndex){
        if(index < 0 || inorderStart > inorderEnd){
            return NULL;
        }

        int element = postorder[index--];
        TreeNode* root = new TreeNode(element);
        int position = nodeToIndex[element];

        root -> right = solve(inorder, postorder, index, position + 1, inorderEnd, n, nodeToIndex);
        root -> left = solve(inorder, postorder, index, inorderStart, position - 1, n, nodeToIndex);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = postorder.size();
        int postOrderIndex = n - 1;
        unordered_map<int, int>nodeToIndex;
        createMapping(inorder, nodeToIndex, n);
        TreeNode* ans = solve(inorder, postorder, postOrderIndex, 0, n - 1, n, nodeToIndex);
        return ans;
    }
};