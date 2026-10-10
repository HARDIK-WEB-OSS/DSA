class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        long long k = (long long)k1 + k2;
        int cnt[100001] = {};
        long long sum = 0;

        for (int i = 0; i < nums1.size(); i++) {
            int d = abs(nums1[i] - nums2[i]);
            cnt[d]++;
            sum += d;
        }

        if (sum <= k) return 0;

        for (int d = 100000; d > 0 && k > 0; d--) {
            if (!cnt[d]) continue;

            long long take = min(k, (long long)cnt[d]);
            cnt[d] -= take;
            cnt[d - 1] += take;
            k -= take;
        }

        long long ans = 0;
        for (int d = 1; d <= 100000; d++)
            ans += 1LL * d * d * cnt[d];

        return ans;
    }
};