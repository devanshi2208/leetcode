class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int ans = 0;
        
        for (int num = 100; num <= 999; num++) {
            // Number must be even
            if (num % 2 != 0) continue;
            
            int x = num;
            vector<int> need(10, 0);
            
            // Count digits needed
            for (int i = 0; i < 3; i++) {
                need[x % 10]++;
                x /= 10;
            }
            
            // Count digits available
            vector<int> have(10, 0);
            for (int d : digits) {
                have[d]++;
            }
            
            // Check if we have enough copies
            bool possible = true;
            for (int d = 0; d <= 9; d++) {
                if (need[d] > have[d]) {
                    possible = false;
                    break;
                }
            }
            
            if (possible) ans++;
        }
        
        return ans;
    }
};