class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long long n = 0;
        for(int i : nums){
            n ^= i;
        }

        long long bit = n & (-n);
        int a = 0, b = 0;
        for(long long i : nums){
            if(i & bit){
                a ^= i;
            }
            else{
                b ^= i;
            }
        }
        return {a, b};
    }
};