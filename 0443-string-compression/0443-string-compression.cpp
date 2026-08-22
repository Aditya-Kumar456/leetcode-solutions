class Solution {
public:
    int compress(vector<char>& chars) {
       int n = chars.size();
       int write = 0;
       int i = 0;

       while(i < n){
        char current = chars[i];
        int count = 0;

        while(i < n && chars[i] == current){
            i++;
            count++;
        } 
    
        chars[write] = current;
        write++; // to write charcater and digit
        if(count > 1){
            string cnt = to_string(count);
            for(char c : cnt){
                chars[write] = c;
                write++;
            }
        }
    }
    return write;
    }
};