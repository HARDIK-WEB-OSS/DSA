class Solution {
public:
    int minMaxWaitingTime(vector<int>& demand, vector<int>& fuel) {
        int n = demand.size();
        vector<int> telmorvian = demand;

        int fuel0 = fuel[0], fuel1 = fuel[1];

        vector<int> prefix(n + 1, 0);
        for (int i = 0; i < n; i++)
            prefix[i + 1] = prefix[i] + demand[i];

        // ---------- Step 1 : Rolling subset DP ----------
        vector<uint8_t> reach(fuel0 + 1, 0), nxt(fuel0 + 1, 0);
        reach[0] = 1;

        int kmax = 0;

        for (int i = 0; i < n; i++) {
            fill(nxt.begin(), nxt.end(), 0);

            bool any = false;
            int pref = prefix[i];

            for (int s = 0; s <= fuel0; s++) {
                if (!reach[s]) continue;

                if (s + demand[i] <= fuel0)
                    nxt[s + demand[i]] = 1;

                if (pref - s + demand[i] <= fuel1)
                    nxt[s] = 1;
            }

            for (int s = 0; s <= fuel0; s++) {
                if (nxt[s]) {
                    any = true;
                    break;
                }
            }

            if (!any) break;

            kmax = i + 1;
            reach.swap(nxt);
        }

        if (kmax == 0) return -1;

        // ---------- Step 2 ----------
        const int R = 21;
        const int INF = INT_MAX / 2;

        int STATES = R * R * (fuel0 + 1);

        vector<int> dp(STATES, INF), ndp(STATES, INF);

        auto ID = [&](int r0, int r1, int s) {
            return ((r0 * R + r1) * (fuel0 + 1) + s);
        };

        int dec0[R][R];
        int dec1[R][R];

        for (int a = 0; a < R; a++)
            for (int b = 0; b < R; b++) {
                dec0[a][b] = max(0, b - a);
                dec1[a][b] = max(0, a - b);
            }

        dp[ID(0, 0, 0)] = 0;

        for (int i = 0; i < kmax; i++) {

            fill(ndp.begin(), ndp.end(), INF);

            int d = demand[i];
            int pref = prefix[i];

            for (int r0 = 0; r0 < R; r0++) {
                for (int r1 = 0; r1 < R; r1++) {

                    int base = (r0 * R + r1) * (fuel0 + 1);

                    for (int s = 0; s <= fuel0; s++) {

                        int cur = dp[base + s];
                        if (cur >= INF) continue;

                        // Assign to dispenser 0
                        if (s + d <= fuel0) {

                            int nr0 = d;
                            int nr1 = dec0[r0][r1];

                            int idx = ID(nr0, nr1, s + d);

                            int val = max(cur, r0);

                            if (val < ndp[idx])
                                ndp[idx] = val;
                        }

                        // Assign to dispenser 1
                        if (pref - s + d <= fuel1) {

                            int nr0 = dec1[r0][r1];
                            int nr1 = d;

                            int idx = ID(nr0, nr1, s);

                            int val = max(cur, r1);

                            if (val < ndp[idx])
                                ndp[idx] = val;
                        }
                    }
                }
            }

            dp.swap(ndp);
        }

        int ans = INF;

        for (int x : dp)
            ans = min(ans, x);

        return ans;
    }
};