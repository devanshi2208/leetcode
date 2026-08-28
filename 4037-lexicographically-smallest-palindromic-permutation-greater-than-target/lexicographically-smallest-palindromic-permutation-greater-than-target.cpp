class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {
        int freq[26] = {};

        for (char c : s)
            freq[c - 'a']++;

        int odd = 0;
        char mid = 0;

        for (int i = 0; i < 26; i++) {
            if (freq[i] % 2) {
                odd++;
                mid = 'a' + i;
            }
        }

        // More than one odd frequency => palindrome impossible
        if (odd > 1) return "";

        // Character counts for the first half
        int original[26];
        string smallestHalf;

        for (int i = 0; i < 26; i++) {
            original[i] = freq[i] / 2;
            smallestHalf += string(original[i], char('a' + i));
        }

        int m = smallestHalf.size();

        auto makePalindrome = [&](string half) {
            string ans = half;

            if (odd) ans += mid;

            string rev = half;
            reverse(rev.begin(), rev.end());
            ans += rev;

            return ans;
        };

        // Check the lexicographically smallest palindrome
        string smallest = makePalindrome(smallestHalf);

        if (smallest > target)
            return smallest;

        // Target's first half
        string tHalf = target.substr(0, m);

        // Check whether tHalf itself can be formed
        int cnt[26];
        copy(original, original + 26, cnt);

        bool possible = true;

        for (char c : tHalf) {
            if (cnt[c - 'a'] == 0) {
                possible = false;
                break;
            }
            cnt[c - 'a']--;
        }

        // If same first half is possible, check the complete palindrome
        if (possible) {
            string same = makePalindrome(tHalf);

            if (same > target)
                return same;
        }

        // Find smallest permutation of half strictly greater than tHalf
        for (int i = m - 1; i >= 0; i--) {
            copy(original, original + 26, cnt);

            bool prefixPossible = true;

            // Use target prefix [0...i-1]
            for (int j = 0; j < i; j++) {
                int x = tHalf[j] - 'a';

                if (cnt[x] == 0) {
                    prefixPossible = false;
                    break;
                }
                cnt[x]--;
            }

            if (!prefixPossible) continue;

            // Find smallest available character > tHalf[i]
            for (int c = tHalf[i] - 'a' + 1; c < 26; c++) {
                if (cnt[c] > 0) {
                    string half = tHalf.substr(0, i);
                    half += char('a' + c);
                    cnt[c]--;

                    // Fill remaining positions with smallest characters
                    for (int j = 0; j < 26; j++) {
                        half += string(cnt[j], char('a' + j));
                    }

                    return makePalindrome(half);
                }
            }
        }

        return "";
    }
};