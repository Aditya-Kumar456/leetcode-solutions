class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0){
            return false;
        }

        long long reversed = 0;
        int original = x;
        while(x != 0){
            int digits = x % 10;
            reversed = reversed * 10 + digits;
            x = x / 10;
        }
        if(original == reversed){
            return true;
        }
        return false;
    }
};