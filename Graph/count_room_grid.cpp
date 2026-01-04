#include <bits/stdc++.h>
using namespace std;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

void bfs(vector<vector<int>> &grid, int x, int y)
{

    grid[x][y] = 1;
    queue<pair<int, int>> q;
    q.push({x, y});

    while (!q.empty())
    {
        int prevx = q.front().first;
        int prevy = q.front().second;

        q.pop();

        for (int i = 0; i < 4; i++)
        {

            int newx = prevx + dx[i];
            int newy = prevy + dy[i];

            if (newx >= 0 && newx < grid[0].size() && newy >= 0 && newy < grid[0].size() && (grid[newx][newy] == 0))
            {

                q.push({newx, newy});
                grid[newx][newy] = 1;
            }
        }
    }
}

int main()
{

    int n, m;
    cin >> n >> m;
    int room = 0;

    vector<vector<int>> grid(n, vector<int>(m));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 0)
            {
                room++;
                bfs(grid, i, j);
            }
        }
    }

    cout << room << endl;
}