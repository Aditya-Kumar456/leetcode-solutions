class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()){
            return false;
        }

        unordered_map<char, int>count;

        for(char ch : s){
            count[ch]++;
        }

        for(char ch : t){
            count[ch]--;
        }

        for(auto x : count){
            if(x.second != 0){
                return false;
            }
        }
        return true;
    }
};