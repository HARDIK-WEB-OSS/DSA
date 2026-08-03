class Solution {

    private void dfs(int node, int[][] isConnected, int[] vis) {
        vis[node] = 1;

        for (int j = 0; j < isConnected.length; j++) {
            if (isConnected[node][j] == 1 && vis[j] == 0) {
                dfs(j, isConnected, vis);
            }
        }
    }

    public int findCircleNum(int[][] isConnected) {

        int n = isConnected.length;
        int[] vis = new int[n];

        int cnt = 0;

        for (int i = 0; i < n; i++) {
            if (vis[i] == 0) {
                cnt++;
                dfs(i, isConnected, vis);
            }
        }

        return cnt;
    }
}