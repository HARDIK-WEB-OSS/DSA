class Solution {
public:
    int minMoves(vector<string>& g, int E) {
        int m = g.size(), n = g[0].size();
        int sr, sc, L = 0;

        vector<vector<int>> id(m, vector<int>(n, -1));

        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++) {
                if (g[i][j] == 'S') sr = i, sc = j;
                if (g[i][j] == 'L') id[i][j] = L++;
            }

        if (!L) return 0;

        int M = 1 << L, cells = m * n;
        vector<signed char> best(cells * M, -1);
        vector<int> q;
        q.reserve(cells * M);

        int start = (sr * n + sc) * 51 + E;
        q.push_back(start);
        best[(sr * n + sc) * M] = E;

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};
        int head = 0, dist = 0, full = M - 1;

        while (head < q.size()) {
            int end = q.size();

            while (head < end) {
                int z = q[head++];
                int e = z % 51;
                z /= 51;
                int mask = z / cells;
                int cell = z % cells;
                int r = cell / n, c = cell % n;

                if (mask == full) return dist;
                if (!e) continue;

                for (int d = 0; d < 4; d++) {
                    int nr = r + dr[d], nc = c + dc[d];

                    if (nr < 0 || nr >= m || nc < 0 || nc >= n ||
                        g[nr][nc] == 'X')
                        continue;

                    int ne = e - 1;
                    int nm = mask;

                    if (g[nr][nc] == 'L')
                        nm |= 1 << id[nr][nc];

                    if (g[nr][nc] == 'R')
                        ne = E;

                    int ncid = nr * n + nc;
                    int idx = ncid * M + nm;

                    if (best[idx] >= ne) continue;

                    best[idx] = ne;
                    q.push_back((nm * cells + ncid) * 51 + ne);
                }
            }

            dist++;
        }

        return -1;
    }
};