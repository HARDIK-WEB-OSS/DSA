class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();

        int mn = 0, mx = 0;

        for (int i = 1; i < n; i++) {
            if (nums[i] < nums[mn]) mn = i;
            if (nums[i] > nums[mx]) mx = i;
        }

        int l = min(mn, mx);
        int r = max(mn, mx);

        return min({
            r + 1,           // remove both from front
            n - l,           // remove both from back
            l + 1 + n - r    // front for left + back for right
        });
    }
};