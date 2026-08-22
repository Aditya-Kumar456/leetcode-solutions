class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        if(n < 3){
            return false;
        }
        int a = INT_MAX;
        int b = INT_MAX;
        for(int num : nums){
            if(a >= num){
                a = num;
            }
            else if(b >= num){
                b = num;
            }
            else{
                return true;
            }
        }
        return false;
    }
};