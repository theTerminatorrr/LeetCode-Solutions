#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maximumSwap(int num)
    {
        string st = to_string(num);
        int n = st.size();

        priority_queue<pair<char, int>> pq;

        for(int i = 0; i < n; i++)
        {
            pq.push({st[i], i});
        }
        for(int j = 0; j < n; j++)
        {
            while(! pq.empty() && pq.top().second < j)
                pq.pop();
            if(pq.top().first > st[j])
            {
                swap(st[j], st[pq.top().second]);
                break;
            }
        }
        return stoi(st);
    }
};

int main()
{
    Solution s;

    int n;
    cout << "Enter a number: ";
    cin >> n;

    cout << "Maximum number after at most one swap: " << s.maximumSwap(n) << endl;

    return 0;
}
