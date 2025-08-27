class Solution
{
public:
    int maximizeSum(vector<int>& nums, int k)
    {
        int max = *max_element(nums.begin(), nums.end());

        int ans = 0;

        while(k--)
        {
            ans += max;
            max++;
        }

        return ans;
    }
};
