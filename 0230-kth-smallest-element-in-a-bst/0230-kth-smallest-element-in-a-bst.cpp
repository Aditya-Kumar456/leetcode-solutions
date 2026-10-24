class Solution {
public:
    int solve(TreeNode* root, int &i, int k){
        if(root == NULL){
            return -1;
        }

        int left = solve(root -> left, i, k);

        if(left != -1){
            return left;
        }

        i++;
        if(i == k){
            return root -> val;
        }

        return solve(root -> right, i, k);
    }

    int kthSmallest(TreeNode* root, int k) {
        int i = 0;
        int ans = solve(root, i, k);
        return ans;
    }
};

/*

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        int count = 0;
        int ans = -1;

        TreeNode* curr = root;

        while (curr != NULL) {

            if (curr->left == NULL) {
                count++;

                if (count == k) {
                    ans = curr->val;
                }

                curr = curr->right;
            }
            else {
                TreeNode* pred = curr->left;

                while (pred->right != NULL && pred->right != curr) {
                    pred = pred->right;
                }

                if (pred->right == NULL) {
                    pred->right = curr;
                    curr = curr->left;
                }
                else {
                    pred->right = NULL;
                    count++;

                    if (count == k) {
                        ans = curr->val;
                    }

                    curr = curr->right;
                }
            }

            if (ans != -1) {
                return ans;
            }
        }

        return ans;
    }
};

*/