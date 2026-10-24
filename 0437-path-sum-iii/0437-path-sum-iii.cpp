class Solution {
public:
    void solve(TreeNode* root, int k, int &count, long long sum,
               unordered_map<long long, int> &mp) {

        if (root == NULL) {
            return;
        }

        sum += root->val;

        if (mp.find(sum - k) != mp.end()) {
            count += mp[sum - k];
        }

        mp[sum]++;
        solve(root->left, k, count, sum, mp);
        solve(root->right, k, count, sum, mp);
        mp[sum]--;
    }

    int pathSum(TreeNode* root, int targetSum) {
        int count = 0;
        long long sum = 0;
        unordered_map<long long, int> mp;
        mp[0] = 1;
        solve(root, targetSum, count, sum, mp);
        return count;
    }
};
