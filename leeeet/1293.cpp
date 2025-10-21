class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        if (m == 1 && n == 1) return 0;
        queue<vector<int>> q;
        q.push({0, 0, 0});
        vector<vector<vector<bool>>> visited(m, vector<vector<bool>>(n, vector<bool>(k + 1, false)));
        visited[0][0][0] = true;
        int steps = 0;
        vector<int> dir = {0, 1, 0, -1, 0};
        while (!q.empty()) {
            int size = q.size();
            steps++;
            while (size--) {
                auto curr = q.front();
                q.pop();
                int r = curr[0], c = curr[1],usedk = curr[2];
                for (int i = 0; i < 4; i++) {
                    int nr = r + dir[i];
                    int nc = c + dir[i + 1];
                    if (nr < 0 || nc < 0 || nr >= m || nc >=n)continue;
                    int nextK = usedk + grid[nr][nc];
                    if (nextK <= k && !visited[nr][nc][nextK]) {
                        if (nr == m-1 && nc == n - 1)return steps;
                        visited[nr][nc][nextK] = true;
                        q.push({nr, nc, nextK});
                    }
                }
            }
        }
        return -1;
    }
};