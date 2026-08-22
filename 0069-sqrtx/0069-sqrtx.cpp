class Solution {
public:
    int mySqrt(int x) {
        if(x < 2){
            return x;
        }
        int start = 0;
        int end = x / 2;
        int ans;
        while(start <= end){
            int mid = start + (end - start) / 2;
            if((long long)mid * mid <= x){
                ans = mid;
                start = mid + 1;
            }
            else{
                end = mid - 1;
            }
        }
        return ans;
    }
};