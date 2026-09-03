class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        sort(nums1.begin(), nums1.end());

        int target = nums1[0] % 2;
        bool hasOdd = false;

        for (int x : nums1) {
            if (x % 2 == target) {
                if (x % 2 == 1) hasOdd = true;
            } 
            else if (!hasOdd) {
                return false;
            }
        }

        return true;
    }
};