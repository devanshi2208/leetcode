
class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        vector<long long> squares;

        for (int x : nums) {
            squares.push_back(1LL * x * x);
        }

        sort(squares.begin(), squares.end());

        long long score = 0;
        int n = squares.size();
        int half = n / 2;

        for (int i = 0; i < half; i++) {
            score -= squares[i];
        }

        for (int i = half; i < n; i++) {
            score += squares[i];
        }

        return score;
    }
};
