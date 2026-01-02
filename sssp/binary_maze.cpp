#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int shortestPathBinaryMatrix(vector<vector<int>> &grid)
    {
        int row = grid.size();
        int col = grid[0].size();

        int dr[] = {-1, 1, 0, 0, -1, -1, 1, 1};
        int dc[] = {0, 0, -1, 1, -1, 1, -1, 1};

        vector<vector<int>> dist(row, vector<int>(col, 1e8));
        queue<pair<int, pair<int, int>>> q;

        pair<int, int> src = {0, 0};
        pair<int, int> dst = {row - 1, col - 1};
        if (grid[0][0] == 1 || grid[row - 1][col - 1] == 1)
            return -1;
        if (grid[0][0] == 0 && (src.first == dst.first) && (src.second == dst.second))
            return 1;

        dist[src.first][src.second] = 0;
        q.push({0, {src.first, src.second}});

        while (!q.empty())
        {
            auto it = q.front();
            q.pop();

            int cost = it.first;
            int r = it.second.first;
            int c = it.second.second;

            for (int i = 0; i < 8; i++)
            {
                int newr = r + dr[i];
                int newc = c + dc[i];

                if (newr >= 0 && newr < row && newc >= 0 && newc < col && grid[newr][newc] != 1 && cost + 1 < dist[newr][newc])
                {
                    dist[newr][newc] = cost + 1;
                    if (newr == dst.first && newc == dst.second)
                        return dist[newr][newc] + 1;
                    q.push({dist[newr][newc], {newr, newc}});
                }
            }
        }
        return -1;
    }
};