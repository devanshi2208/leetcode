#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.size(), m = t.size();
        if (m > n) return 0;
        
        // dp[j] = number of ways to form t[0..j) using s[0..i) processed so far
        vector<unsigned int> dp(m + 1, 0);
        dp[0] = 1;  // empty t can always be formed exactly one way
        
        for (int i = 1; i <= n; i++) {
            // iterate j backwards so dp[j-1] still holds the value from row i-1
            for (int j = min(i, m); j >= 1; j--) {
                if (s[i - 1] == t[j - 1]) {
                    dp[j] += dp[j - 1];
                }
            }
        }
        
        return static_cast<int>(dp[m]);
    }
};