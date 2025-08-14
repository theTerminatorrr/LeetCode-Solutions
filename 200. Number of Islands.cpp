#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void dfs(vector<vector<char>>& grid, int r, int c, int rows, int cols)
    {
        if (r < 0 || r >= rows || c < 0 || c >= cols || grid[r][c] == '0')
        {
            return;
        }
        grid[r][c] = '0';

        dfs(grid, r - 1, c, rows, cols);
        dfs(grid, r + 1, c, rows, cols);
        dfs(grid, r, c - 1, rows, cols);
        dfs(grid, r, c + 1, rows, cols);
    }

    int numIslands(vector<vector<char>>& grid)
    {
        if (grid.empty()) return 0;

        int rows = grid.size();
        int cols = grid[0].size();
        int island_count = 0;

        for (int r = 0; r < rows; r++)
        {
            for (int c = 0; c < cols; c++)
            {
                if (grid[r][c] == '1')
                {
                    island_count++;
                    dfs(grid, r, c, rows, cols);
                }
            }
        }
        return island_count;
    }
};

int main()
{
    int rows, cols;
    cout << "Enter number of rows: ";
    cin >> rows;
    cout << "Enter number of columns: ";
    cin >> cols;

    vector<vector<char>> grid(rows, vector<char>(cols));
    cout << "Enter the grid (1 for land, 0 for water):\n";
    for (int r = 0; r < rows; r++)
    {
        for (int c = 0; c < cols; c++)
        {
            cin >> grid[r][c];
        }
    }

    Solution sol;
    int result = sol.numIslands(grid);
    cout << "Number of islands: " << result << endl;

    return 0;
}
