class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int cnt[26] = {};

        for (char c : s)
            cnt[c - 'a']++;

        int n = s.size();
        int matched = 0;

     
        while (matched < n && cnt[target[matched] - 'a'] > 0) {
            cnt[target[matched] - 'a']--;
            matched++;
        }

       
        for (int i = matched; i >= 0; i--) {
            if (i < matched)
                cnt[target[i] - 'a']++;

            if (i == n) continue;

            
            for (int j = target[i] - 'a' + 1; j < 26; j++) {
                if (cnt[j] > 0) {
                    string ans = target.substr(0, i);
                    ans += char('a' + j);
                    cnt[j]--;

                    
                    for (int k = 0; k < 26; k++)
                        ans += string(cnt[k], char('a' + k));

                    return ans;
                }
            }
        }

        return "";
    }
};