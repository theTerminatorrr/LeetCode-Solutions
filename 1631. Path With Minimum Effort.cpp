#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    struct node
    {
        int effort, row, col;
        node(int _effort, int _row, int _col)
        {
            effort = _effort;
            row = _row;
            col = _col;
        }
        bool operator>(const node &other) const
        {
            return effort > other.effort;
        }
    };

    bool check(int i, int j, int n, int m)
    {
        return i >= 0 && i < n && j >= 0 && j < m;
    }

public:
    int minimumEffortPath(vector<vector<int>> &heights)
    {
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>> dis(n, vector<int>(m, 1e9));
        dis[0][0] = 0;

        priority_queue<node, vector<node>, greater<node>> pq;
        pq.push(node(0, 0, 0));

        vector<int> dx = {-1, 0, 1, 0};
        vector<int> dy = {0, 1, 0, -1};

        while (!pq.empty())
        {
            int effort = pq.top().effort;
            int row = pq.top().row;
            int col = pq.top().col;
            pq.pop();

            if (row == n - 1 && col == m - 1) return effort;

            for (int i = 0; i < 4; i++)
            {
                int newRow = row + dx[i];
                int newCol = col + dy[i];
                if (check(newRow, newCol, n, m))
                {
                    int newEffort = max(effort, abs(heights[row][col] - heights[newRow][newCol]));
                    if (newEffort < dis[newRow][newCol])
                    {
                        dis[newRow][newCol] = newEffort;
                        pq.push(node(newEffort, newRow, newCol));
                    }
                }
            }
        }
        return dis[n - 1][m - 1];
    }
};

int main()
{
    int n, m;
    cout << "Enter rows and cols: ";
    cin >> n >> m;

    vector<vector<int>> heights(n, vector<int>(m));
    cout << "Enter grid values:\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> heights[i][j];
        }
    }

    Solution sol;
    int ans = sol.minimumEffortPath(heights);
    cout << "Minimum Effort Path: " << ans << "\n";

    return 0;
}
