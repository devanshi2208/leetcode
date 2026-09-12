class Solution {
public:
    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();

        vector<array<long long, 4>> a;
        for (int i = 0; i < n; i++) {
            a.push_back({intervals[i][0], intervals[i][1],
                         intervals[i][2], i});
        }

        sort(a.begin(), a.end());

        vector<vector<pair<long long, vector<int>>>> dp(
            n + 1, vector<pair<long long, vector<int>>>(5));

        auto better = [&](pair<long long, vector<int>> A,
                          pair<long long, vector<int>> B) {
            if (A.first != B.first)
                return A.first > B.first;

            vector<int> x = A.second;
            vector<int> y = B.second;

            sort(x.begin(), x.end());
            sort(y.begin(), y.end());

            return x < y;
        };

        for (int i = n - 1; i >= 0; i--) {
            for (int k = 1; k <= 4; k++) {
                auto best = dp[i + 1][k];

                int lo = i + 1, hi = n;

                while (lo < hi) {
                    int mid = lo + (hi - lo) / 2;

                    if (a[mid][0] > a[i][1])
                        hi = mid;
                    else
                        lo = mid + 1;
                }

                int nxt = lo;

                auto take = dp[nxt][k - 1];

                take.first += a[i][2];
                take.second.push_back((int)a[i][3]);

                if (better(take, best))
                    best = take;

                dp[i][k] = best;
            }
        }

        auto ans = dp[0][4].second;
        sort(ans.begin(), ans.end());

        return ans;
    }
};