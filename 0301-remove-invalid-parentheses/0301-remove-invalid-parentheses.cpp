class Solution {
public:
    vector<string> ans;
    void dfs(string& s, int i, int left, int right, int open, string cur) {
        if (i == s.size()) {
            if (left == 0 && right == 0 && open == 0)
                ans.push_back(cur);
            return;
        }

        if (s[i] == '(') {
            if (left > 0)
                dfs(s, i + 1, left - 1, right, open, cur);

            dfs(s, i + 1, left, right, open + 1, cur + '(');
        }
        else if (s[i] == ')') {
            if (right > 0)
                dfs(s, i + 1, left, right - 1, open, cur);

            if (open > 0)
                dfs(s, i + 1, left, right, open - 1, cur + ')');
        }
        else {
            dfs(s, i + 1, left, right, open, cur + s[i]);
        }
    }
    vector<string> removeInvalidParentheses(string s) {
        int left = 0, right = 0;

        for (char c : s) {
            if (c == '(')
                left++;
            else if (c == ')') {
                if (left)
                    left--;
                else
                    right++;
            }
        }
        dfs(s, 0, left, right, 0, "");
        sort(ans.begin(), ans.end());
        ans.erase(unique(ans.begin(), ans.end()), ans.end());

        return ans;
    }
};