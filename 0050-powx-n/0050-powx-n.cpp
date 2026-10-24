class Solution {
public:
    double myPow(double x, int n) {
        long long p = n;
        long double result = x;

        if(p < 0){
            result = 1 / result;
            p = -p;
        }

        long double ans = 1;
        while(p > 0){
            if(p % 2 == 1){
                ans = ans * result;
            }
            result = result * result;
            p = p >> 1;
        }
        return ans;
    }
};



      
      
      
      
      
      
      
      
      
      
      
      
      
        // long long p = n;
        // long double result = x;

        // if(p < 0){
        //     result = 1 / result;
        //     p = -p;
        // }

        // long double ans = 1;
        // while(p > 0){
        //     if(p % 2 == 1){
        //         ans = ans * result;
        //     }
        //     result = result * result;
        //     p = p >> 1;
        // }
        // return ans;