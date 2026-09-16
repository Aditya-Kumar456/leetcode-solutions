class Solution {
public:
    void reverseString(vector<char>& s) {
        stack<char>st;

        for(int i = 0; i < s.size(); i++){
            char ch = s[i];
            st.push(ch);
        }

        string ans = "";
        while(!st.empty()){
            char ch = st.top();
            ans.push_back(ch);
            st.pop();
        }

        for(int i = 0; i < s.size(); i++){
            s[i] = ans[i];
        }
    }
};