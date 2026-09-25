class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int cnt[10] = {};
        for (int x : digits) cnt[x]++;

        int ans = 0;

        for (int a = 1; a <= 9; a++) {
            if (!cnt[a]) continue;
            cnt[a]--;

            for (int b = 0; b <= 9; b++) {
                if (!cnt[b]) continue;
                cnt[b]--;

                for (int c = 0; c <= 8; c += 2) {
                    if (cnt[c])
                        ans++;
                }

                cnt[b]++;
            }

            cnt[a]++;
        }

        return ans;
    }
};