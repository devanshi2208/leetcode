class Solution {
public:
    int stoneGameVIII(vector<int>& stones) {
        int n = stones.size();

        vector<long long> prefix(n);
        prefix[0] = stones[0];

        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1] + stones[i];
        }

        // If Alice takes all stones, she gets prefix[n-1].
        long long best = prefix[n - 1];

        // Consider taking the first i+1 stones.
        for (int i = n - 2; i >= 1; i--) {
            best = max(best, prefix[i] - best);
        }

        return (int)best;
    }
};