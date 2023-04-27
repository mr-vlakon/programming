class Solution {
public:
    int unhappyFriends(int n, vector<vector<int>>& preferences, vector<vector<int>>& pairs) {
        vector<int> matches(n, 0);
        for (int i = 0; i != pairs.size(); ++i) {
            matches[pairs[i][0]] = pairs[i][1];
            matches[pairs[i][1]] = pairs[i][0];
        }
        int answer = 0;
        bool flag = false;
        for (int i = 0; i != matches.size(); ++i) {
            flag = false;
            for (const auto &e: preferences[i]) {
                if (e == matches[i]) {
                    break;
                } else {
                    for (const auto &p: preferences[e]) {
                        if (p == matches[e]) {
                            break;
                        } else if (p == i) {
                            ++answer;
                            flag = true;
                            break;
                        }
                    }
                    if (flag) break;
                }
            }
        }
        return answer;
    }
};

int main() {
  
  
  
  return 0;  
}
