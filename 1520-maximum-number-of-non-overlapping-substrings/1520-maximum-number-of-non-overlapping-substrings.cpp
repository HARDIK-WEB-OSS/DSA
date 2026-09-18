class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
    int n = s.size();
    vector<int> first(26, n), last(26, -1);
    for (int i = 0; i < n; i++) {
        int c = s[i] - 'a';
        first[c] = min(first[c], i);
        last[c] = i;
    }
    vector<pair<int,int>> intervals;
    for (int c = 0; c < 26; c++) {
        if (last[c] == -1) continue;
            int l = first[c], r = last[c];
        for (int i = l; i <= r; i++) {
            int x = s[i] - 'a';
             if (first[x] < l) {
                l = -1;
                break;
            }

            r = max(r, last[x]);
        }

        if (l != -1)
             intervals.push_back({r, l});
        }
    sort(intervals.begin(), intervals.end());
    vector<string> ans;
    int end = -1;
    for (auto [r, l] : intervals) {
        if (l > end) {
            ans.push_back(s.substr(l, r - l + 1));
            end = r;
        }
    }
    return ans;  
    }
};