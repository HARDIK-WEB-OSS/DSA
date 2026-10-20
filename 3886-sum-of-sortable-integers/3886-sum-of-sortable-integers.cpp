class Solution {
public:
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size(), ans = 0;

        for (int k = 1; k <= n; ++k) {
            if (n % k) continue;

            bool ok = true;
            int prevMax = 0;

            for (int i = 0; i < n && ok; i += k) {
                int mn = nums[i], mx = nums[i];
                int desc = 0;

                for (int j = i; j < i + k; ++j) {
                    mn = min(mn, nums[j]);
                    mx = max(mx, nums[j]);

                    int next = (j + 1 == i + k) ? i : j + 1;
                    if (nums[j] > nums[next]) ++desc;
                }

                if (desc > 1 || (i > 0 && prevMax > mn))
                    ok = false;

                prevMax = mx;
            }

            if (ok) ans += k;
        }

        return ans;
    }
};