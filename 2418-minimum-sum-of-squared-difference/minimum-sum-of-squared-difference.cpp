
class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        long long k = (long long)k1 + k2;
        vector<int> cnt(100001, 0);
        
        for (int i = 0; i < nums1.size(); i++) {
            cnt[abs(nums1[i] - nums2[i])]++;
        }
        
        for (int d = 100000; d > 0 && k > 0; d--) {
            if (cnt[d] == 0) continue;
            
            long long moves = min(k, (long long)cnt[d]);
            cnt[d] -= moves;
            cnt[d - 1] += moves;
            k -= moves;
        }
        
        long long ans = 0;
        for (int d = 1; d <= 100000; d++) {
            ans += 1LL * d * d * cnt[d];
        }
        
        return ans;
    }
};
