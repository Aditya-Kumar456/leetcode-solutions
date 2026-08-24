class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>>pq;

        for(int i : nums){
            pq.push(i);
        }

        while(pq.size() > k){
            pq.pop();
        }
        return pq.top();
    }
};