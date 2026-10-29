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

    vector<int>mergeArrays(vector<int>bst1,  vector<int>bst2){
        vector<int>ans(bst1.size() + bst2.size());
        int i = 0, j = 0, k = 0;

        while(i < bst1.size() && j < bst2.size()){
            if(bst1[i] < bst2[j]){
                ans[k++] = bst1[i++];
            }
            else{
                ans[k++] = bst2[j++];
            }
        }

        while(i < bst1.size()){
            ans[k++] = bst1[i++];
        }

        while(j < bst2.size()){
            ans[k++] = bst2[j++];
        }
        return ans;
    }

    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int>bst1, bst2;
        inorder(root1, bst1);
        inorder(root2, bst2);
        return mergeArrays(bst1, bst2);
    }
};