class Solution {
public:
    string reverseWords(string s) {
        vector<string>words;
        string temp = "";
        for(char c : s){
            if (c == ' '){
                if(!temp.empty()){
                    words.push_back(temp);
                    temp = "";
                }
            }
            else{
                temp += c;
            }
        }
        if(!temp.empty()){
            words.push_back(temp);
        }
        int left = 0, right = words.size() - 1;
        while(left < right){
            swap(words[left], words[right]);
            left++;
            right--;
        }
        string ans = "";
        for(int i = 0; i < words.size(); i++){
            ans += words[i];
            if(i != words.size() - 1){
                ans += " ";
            }
        }
        return ans;
    }
};