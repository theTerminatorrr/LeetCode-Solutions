class Solution {
public:
    int climbStairs(int n) {
        int prev = 1, prev_prev = 1;

        for (int i = 1; i < n; i++) {
            int temp = prev;
            prev += prev_prev;
            prev_prev = temp;
        }

        return prev;
    }
};
