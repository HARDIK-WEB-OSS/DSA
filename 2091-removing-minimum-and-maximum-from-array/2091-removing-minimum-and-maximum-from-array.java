class Solution {
    public int minimumDeletions(int[] nums) {
        int n = nums.length;

        int mn = 0, mx = 0;

        for (int i = 1; i < n; i++) {
            if (nums[i] < nums[mn]) mn = i;
            if (nums[i] > nums[mx]) mx = i;
        }

        int l = Math.min(mn, mx);
        int r = Math.max(mn, mx);

        return Math.min(
            Math.min(r + 1, n - l),
            l + 1 + n - r
        );
    }
}