class Solution
{
public:
    int longestPalindrome(string s)
    {
        int res = 0, odd = 0, freq[128] = {0};

        for (char c : s)
            freq[c]++;

        for (int num : freq)
        {
            res += num - (num % 2 ? odd : 0);
            odd = (num % 2 ? 1 : odd);
        }

        return res;
    }
};
