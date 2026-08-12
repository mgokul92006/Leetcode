class Solution {
public:
    int path(string target, set<string>& s) {
        string b = "0000";
        if (s.find(b) != s.end())
            return -1;
        s.insert("0000");
        queue<tuple<string, int>> q;
        q.push({b, 0});
        while (!q.empty()) {
            auto [st, m] = q.front();
            q.pop();
            if (st == target)
                return m;
            for (int i = 0; i < st.size(); i++) {
                string temp1 = st, temp2 = st;
                int c = temp1[i] - '0';
                if (c + 1 == 10) {
                    temp1[i] = 0 + '0';
                } else {
                    temp1[i] = c + 1 + '0';
                }
                if (s.find(temp1) == s.end()) {
                    q.push({temp1, m + 1});
                    s.insert(temp1);
                }
                if (c - 1 < 0) {
                    temp2[i] = 9 + '0';
                }
                else{
                    temp2[i]=c-1+'0';
                }
                if (s.find(temp2) == s.end()) {
                        s.insert(temp2);
                        q.push({temp2,m+1});
                }
            }
        }
        return -1;
    }
    int openLock(vector<string>& deadends, string target) {
        set<string> s;
        for (auto i : deadends)
            s.insert(i);
        return path(target, s);
    }
};