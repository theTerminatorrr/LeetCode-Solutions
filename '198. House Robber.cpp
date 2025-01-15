class Solution {
public:
    int rob(vector<int>& nums) {
        int prev2_max = 0, prev_max = 0;

        for (int cur : nums) {
            int temp = max(cur + prev2_max, prev_max);
            prev2_max = prev_max;
            prev_max = temp;
        }

        return prev_max;
    }
};
