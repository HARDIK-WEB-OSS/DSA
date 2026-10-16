class Solution {
public:
    int sumCounts(vector<int>& nums) {
        const int MOD = 1e9 + 7, n = nums.size();
        struct Node { long long sum=0, sq=0, lazy=0; };
        vector<Node> t(4*n);
        vector<int> last(100001, -1);
        long long ans = 0;

        auto apply = [&](auto&& self, int p, int l, int r, long long v) -> void {
            long long len = r-l+1;
            t[p].sq = (t[p].sq + 2*v*t[p].sum + v*v%MOD*len) % MOD;
            t[p].sum = (t[p].sum + v*len) % MOD;
            t[p].lazy = (t[p].lazy + v) % MOD;
        };

        auto update = [&](auto&& self, int p, int l, int r, int ql, int qr) -> void {
            if (ql > r || qr < l) return;
            if (ql <= l && r <= qr) {
                apply(apply, p, l, r, 1);
                return;
            }
            int m = (l+r)/2;
            if (t[p].lazy) {
                apply(apply, p*2, l, m, t[p].lazy);
                apply(apply, p*2+1, m+1, r, t[p].lazy);
                t[p].lazy = 0;
            }
            self(self, p*2, l, m, ql, qr);
            self(self, p*2+1, m+1, r, ql, qr);
            t[p].sum = (t[p*2].sum+t[p*2+1].sum)%MOD;
            t[p].sq = (t[p*2].sq+t[p*2+1].sq)%MOD;
        };

        for (int i = 0; i < n; i++) {
            update(update, 1, 0, n-1, last[nums[i]]+1, i);
            last[nums[i]] = i;
            ans = (ans+t[1].sq)%MOD;
        }
        return ans;
    }
};