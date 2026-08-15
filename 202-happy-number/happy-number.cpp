class Solution {
public:
    int sumSquare(int n) {
        int sum = 0;
        while (n > 0) {
            int d = n % 10;
            sum += d * d;
            n /= 10;
        }
        return sum;
    }

    bool isHappy(int n) {
        int slow = n;
        int fast = n;

        do {
            slow = sumSquare(slow);
            fast = sumSquare(sumSquare(fast));
        } while (slow != fast);

        return slow == 1;
    }
};