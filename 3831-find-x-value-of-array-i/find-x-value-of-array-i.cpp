class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long> ans(k, 0);
        vector<long long> dp(k, 0);

        for (int x : nums) {
            vector<long long> cur(k, 0);

            int val = x % k;

            
            cur[val]++;

           
            for (int r = 0; r < k; r++) {
                int newR = (r * val) % k;
                cur[newR] += dp[r];
            }

        
            for (int r = 0; r < k; r++) {
                ans[r] += cur[r];
            }

            dp = cur;
        }

        return ans;
    }
};