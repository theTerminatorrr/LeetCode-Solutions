class Solution
{
public:
    int numDecodings(string s)
    {
        int n=s.length();
        int next1=1,next2=0;

        for(int i=n-1; i>=0; i--)
        {
            int curr=next1;
            if( (i+1 < n) && (s.substr(i,2) <= "26") ) curr+=next2;
            if(s[i] == '0') curr=0;

            next2=next1;
            next1=curr;
        }
        return next1;
    }
};
