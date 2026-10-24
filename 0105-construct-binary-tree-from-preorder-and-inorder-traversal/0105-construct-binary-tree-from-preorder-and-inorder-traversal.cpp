class Solution {
public:
    void createMapping(vector<int>& inorder, unordered_map<int, int> &nodeToIndex, int n){
        for(int i = 0; i < n; i++){
            nodeToIndex[inorder[i]] = i;
        }
    }

    TreeNode* solve(vector<int>& preorder, vector<int>& inorder, int & index, int inorderStart, int inorderEnd, int n, unordered_map<int, int>&  nodeToIndex){
        if(index >= n || inorderStart > inorderEnd){
            return NULL;
        }

        int element = preorder[index++];
        TreeNode* root = new TreeNode(element);
        int position = nodeToIndex[element];

        root -> left = solve(preorder, inorder, index, inorderStart, position - 1, n, nodeToIndex);
        root -> right = solve(preorder, inorder, index, position + 1, inorderEnd, n, nodeToIndex);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder){
        int n = preorder.size();
        int preOrderIndex = 0;
        unordered_map<int, int>nodeToIndex;
        createMapping(inorder, nodeToIndex, n);
        TreeNode* ans = solve(preorder, inorder, preOrderIndex, 0, n - 1, n, nodeToIndex);
        return ans;
    }
};