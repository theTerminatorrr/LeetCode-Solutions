class Solution
{
public:
    string maximumOddBinaryNumber(string s)
    {
        int n = s.length(), cnt0 = 0, cnt1 = -1;
        
        for(int i = 0; i < n; ++i)
        {
            if(s[i] == '0')
            {
                ++cnt0;
            }
            else 
                ++cnt1;
        }
        return string(cnt1, '1') + string(cnt0, '0') + '1';
    }
};



