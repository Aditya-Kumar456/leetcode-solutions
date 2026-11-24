class Solution {
public:

    int findMax(vector<int>& piles) {
        int maxi = INT_MIN;
        for(int i = 0; i < piles.size(); i++) {
            maxi = max(maxi, piles[i]);
        }
        return maxi;
    }

    long long calculateTotalHour(vector<int>& piles, int hourly) {
        long long totalHour = 0;
        for(int i = 0; i < piles.size(); i++) {
            totalHour += (piles[i] + 1LL * hourly - 1) / hourly;
            if(totalHour > INT_MAX) {
                return totalHour;
            }
        }
        return totalHour;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int start = 1;
        int end = findMax(piles);
        while(start <= end) {
            int mid = start + (end - start) / 2;
            long long totalHour = calculateTotalHour(piles, mid);
            if(totalHour <= h) {
                end = mid - 1;
            }
            else {
                start = mid + 1;
            }
        }

        return start;
    }
};