class Solution {
public:
    int maximumLength(string s) {
        vector<vector<int>> v(26);
        for (int i = 0; i != s.size(); ++i) {
            v[s[i] - 'a'].push_back(i);
        }
        
        int tmp = 0;
        vector<vector<pair<int, int>>> vect;
        for (int i = 0; i != 26; ++i) {
            if (v[i].size() < 3) continue;
            unordered_map<int, int> un;
            int prev = v[i][0];
            ++un[1];
            for (int j = 1; j < v[i].size(); ++j) {
                if ((v[i][j] - v[i][j - 1]) == 1)
                {
                    ++un[v[i][j] - prev + 1];
                }
                else
                {
                    ++un[1];
                    if (j == (v[i].size() - 1)) {
                        ++un[1];
                    }
                    prev = v[i][j];
                }
            }
            vector<pair<int, int>> t;
            for (const auto &e: un) {
                t.push_back({e.first, e.second});
            }
            vect.push_back(t);
        }
        
        if (vect.size() != 0){
        for (auto &e: vect) {
            sort(e.begin(), e.end(), [&](pair<int, int> &left, pair<int, int> &right) {
               return left.first < right.first; 
            });
        }
        }
        int answer = -1;
        int tmpT = 0;
        for (const auto &e: vect) {
            tmpT = 0;
            for (int i = e.size() - 1; i >= 0; --i) {
                tmpT += e[i].second;
                if (tmpT >= 3) {
                    answer = max(answer, e[i].first);
                }
            }
        }
        return answer;
    }
};

int main()
{



  return 0;
}
