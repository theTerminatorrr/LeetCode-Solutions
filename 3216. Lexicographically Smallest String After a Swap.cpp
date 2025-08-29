class Solution
{
public:
    string getSmallestString(string s)
    {
        for(int i = 0; i < s.size()-1; i++)
        {
            char first = s[i];
            char second = s[i+1];

            if(first % 2 == second % 2 && first > second)
            {
                s[i] = second;
                s[i+1] = first;
                break;
            }
        }
        return s;
    }
};
