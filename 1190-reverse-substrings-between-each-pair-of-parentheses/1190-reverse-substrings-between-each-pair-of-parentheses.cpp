class Solution {
public:
    string reverseParentheses(string s) {
        int n = s.size();
        vector<int> match(n), st;

        for (int i = 0; i < n; i++) {
            if (s[i] == '(')
                st.push_back(i);
            else if (s[i] == ')') {
                int j = st.back();
                st.pop_back();
                match[i] = j;
                match[j] = i;
            }
        }

        string ans;
        ans.reserve(n);

        int i = 0, dir = 1;

        while (i >= 0 && i < n) {
            if (s[i] == '(' || s[i] == ')') {
                i = match[i];
                dir = -dir;
            } else {
                ans += s[i];
            }
            i += dir;
        }

        return ans;
    }
};