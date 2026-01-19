

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        if (k >= m + n - 2) return m + n - 2;

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

        pq.push({0, 0, 0, k});

        vector<vector<int>> visited(m, vector<int>(n, -1));
        visited[0][0] = k;

        vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        while (!pq.empty()) {
            auto curr = pq.top();
            pq.pop();

            int steps = curr[0];
            int r = curr[1];
            int c = curr[2];
            int cur_k = curr[3];

            if (r == m - 1 && c == n - 1) {
                return steps;
            }
            

            if (cur_k < visited[r][c]) continue;

            for (auto& d : dirs) {
                int nr = r + d.first;
                int nc = c + d.second;

                if (nr >= 0 && nr < m && nc >= 0 && nc < n) {
                    int new_k = cur_k - grid[nr][nc];

                    if (new_k >= 0 && new_k > visited[nr][nc]) {
                        visited[nr][nc] = new_k;
                        pq.push({steps + 1, nr, nc, new_k});
                    }
                }
            }
        }

        return -1;
    }
};