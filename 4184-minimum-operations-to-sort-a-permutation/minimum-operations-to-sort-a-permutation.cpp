class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int p = find(nums.begin(), nums.end(), 0) - nums.begin();

        bool normal = true, reversed = true;

        for (int i = 0; i < n; i++) {
            if (nums[(p + i) % n] != i)
                normal = false;

            if (nums[(p - i + n) % n] != i)
                reversed = false;
        }

        int ans = INT_MAX;

        if (normal)
            ans = min(p, n - p + 2);

        if (reversed)
            ans = min(ans, min(n - p, p + 2));

        return ans == INT_MAX ? -1 : ans;
    }
};