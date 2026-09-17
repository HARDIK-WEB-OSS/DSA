class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        int left = 0, sum = 0, ans = INT_MAX;
        vector<int> best(n, INT_MAX);

        for (int right = 0; right < n; right++) {
            sum += arr[right];

            while (sum > target)
                sum -= arr[left++];

            if (sum == target) {
                int len = right - left + 1;

                if (left > 0 && best[left - 1] != INT_MAX)
                    ans = min(ans, len + best[left - 1]);

                best[right] = len;
            }

            if (right > 0)
                best[right] = min(best[right], best[right - 1]);
        }

        return ans == INT_MAX ? -1 : ans;
    }
};