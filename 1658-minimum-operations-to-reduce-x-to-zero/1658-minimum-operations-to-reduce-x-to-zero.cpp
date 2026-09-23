class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int target = accumulate(nums.begin(), nums.end(), 0) - x;
        int n = nums.size();

        if (target < 0) return -1;
        if (target == 0) return n;

        int left = 0, sum = 0, best = -1;

        for (int right = 0; right < n; right++) {
            sum += nums[right];

            while (sum > target)
                sum -= nums[left++];

            if (sum == target)
                best = max(best, right - left + 1);
        }

        return best == -1 ? -1 : n - best;
    }
};