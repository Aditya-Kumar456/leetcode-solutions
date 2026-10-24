class Solution {
public:
    TreeNode* minValue(TreeNode* root){
        TreeNode* temp = root;
        while(temp -> left != NULL){
            temp = temp -> left;
        }
        return temp;
    }
    
    TreeNode* deleteNode(TreeNode* root, int key) {
        // base case
        if(root == NULL){
            return NULL;
        }

        if(root -> val == key){
            // 0 child
            if(root -> left == NULL && root -> right == NULL){
                delete root;
                return NULL;
            }
            // 1(left child)
            if(root -> left != NULL && root -> right == NULL){
                TreeNode* temp = root -> left;
                delete root;
                return temp;
            }
            // 1(right child)
            if(root -> left == NULL && root -> right != NULL){
                TreeNode* temp = root -> right;
                delete root;
                return temp;
            }
            // 2(child)
            if(root -> left != NULL && root -> right != NULL){
                int mini = minValue(root -> right) -> val;
                root -> val = mini;
                root -> right = deleteNode(root -> right, mini);
                return root;
            }
        }
        else if(root -> val > key){
            root -> left = deleteNode(root -> left, key);
            return root;
        }
        else{
            root -> right = deleteNode(root -> right, key);
            return root;
        }
        return root;
    }
};







