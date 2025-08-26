class Solution
{
public:
    int buyChoco(vector<int>& prices, int money)
    {
        int min1 = INT_MAX, min2 = INT_MAX;

        for(int price : prices)
        {
            if(price < min1)
            {
                min2 = min1;
                min1 = price;
            }
            else if(price < min2) min2 = price;
        }

        int total = min1 + min2;

        return total > money ? money : money - total;
    }
};
