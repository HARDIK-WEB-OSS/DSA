class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice,
                          string arriveBob, string leaveBob) {
        auto day = [](string s) {
            int m = stoi(s.substr(0, 2));
            int d = stoi(s.substr(3, 2));
            int days[] = {0,31,59,90,120,151,181,212,243,273,304,334};
            return days[m - 1] + d;
        };

        int start = max(day(arriveAlice), day(arriveBob));
        int end = min(day(leaveAlice), day(leaveBob));

        return max(0, end - start + 1);
    }
};