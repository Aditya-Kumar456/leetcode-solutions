class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n = grid.size();
        int count = 0;
        for(int r = 0; r < n; r++){
            for(int c = 0; c < n; c++){
                bool same = true;
                for(int k = 0; k < n; k++){
                    if(grid[r][k] != grid[k][c]){
                        same = false;
                        break;
                    }
                }
                if(same){
                    count++;
                }
            }
        }
        return count;
    }
};