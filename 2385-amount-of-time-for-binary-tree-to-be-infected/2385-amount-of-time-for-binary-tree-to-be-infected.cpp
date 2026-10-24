class Solution {
public:
    TreeNode* createMapping(TreeNode* root, int target, unordered_map<TreeNode*, TreeNode*>& nodeToParent){
        TreeNode* res = NULL;
        queue<TreeNode*>q;
        q.push(root);
        nodeToParent[root] = NULL;

        while(!q.empty()){
            TreeNode* front = q.front();
            q.pop();

            if(front -> val == target){
                res = front;
            }

            if(front -> left){
                nodeToParent[front -> left] = front;
                q.push(front -> left);
            }

            if(front -> right){
                nodeToParent[front -> right] = front;
                q.push(front -> right);
            }
        }
        return res;
    }

    int burnTree(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& nodeToParent){
        unordered_map<TreeNode*, bool>visited;
        queue<TreeNode*>q;
        q.push(root);
        visited[root] = true;

        int ans = 0;

        while(!q.empty()){
            bool flag = 0;
            int size = q.size();
            for(int i = 0; i < size; i++){
                TreeNode* front = q.front();
                q.pop();

                if(front -> left && !visited[front -> left]){
                    flag = 1;
                    q.push(front -> left);
                    visited[front -> left] = true;
                }

                if(front -> right && !visited[front -> right]){
                    flag = 1;
                    q.push(front -> right);
                    visited[front -> right] = true;
                }

                if(nodeToParent[front] && !visited[nodeToParent[front]]){
                    flag = 1;
                    q.push(nodeToParent[front]);
                    visited[nodeToParent[front]] = true;
                }
            }

            if(flag == 1){
                ans++;
            }
        }
        return ans;
    }

    int amountOfTime(TreeNode* root, int start) {
        if(root == NULL){
            return 0;
        }        

        unordered_map<TreeNode*, TreeNode*>nodeToParent;
        TreeNode* targetNode = createMapping(root, start, nodeToParent);
        int ans = burnTree(targetNode, nodeToParent);
        return ans;
    }
};


    