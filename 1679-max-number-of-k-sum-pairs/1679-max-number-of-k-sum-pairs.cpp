class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int, int>map;
        int count = 0;
        for(int i = 0; i < nums.size(); i++){
            int need = k - nums[i];
            if(map[need] > 0){
                count++;
                map[need]--;
            }
            else{
                map[nums[i]]++;
            }
        }
        return count;
    }
};





/*class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int count = 0;
        int i = 0;
        int j = nums.size() - 1;
        sort(nums.begin(), nums.end());
        while(i < j){
            int sum = nums[i] + nums[j];
            if(sum == k){
                count++;
                i++;
                j--;
            }
            else if(sum < k){
                i++;
            }
            else{
                j--;
            }
        }
        return count;
    }
};*/