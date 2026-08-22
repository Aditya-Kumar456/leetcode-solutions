class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int>map;
        stack<int>s;

        for(int num : nums2){
            while(!s.empty() && s.top() < num){
                map[s.top()] = num;
                s.pop();
            }
            s.push(num);

        }
        while(!s.empty()){
            map[s.top()] = -1;
            s.pop();
        }

        vector<int>ans;
        for(int num : nums1){
            ans.push_back(map[num]);
        }
        return ans;
    }
};