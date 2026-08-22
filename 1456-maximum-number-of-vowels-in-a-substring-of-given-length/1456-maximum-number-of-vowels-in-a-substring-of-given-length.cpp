class Solution {
public:
    bool isVowel(char ch){
        if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u'){
            return true;
        }
        return false;
    }
    int maxVowels(string s, int k) {
        int count = 0;
        for(int i = 0; i < k; i++){
            if(isVowel(s[i])){
                count++;
            }
        }
        int maxCount = count;
        for(int i = k; i < s.length(); i++){
            if(isVowel(s[i-k])){
                count--;
            }
            if(isVowel(s[i])){
                count++;
            }
            maxCount = max(maxCount, count);
        }
        return maxCount;
    }
};