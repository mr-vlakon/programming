class Solution {
public:
    int convertToInt(const string &s) {
        return stoi(string{s.cbegin(), s.cbegin() + 2})*60 + stoi(string{s.cbegin() + 3, s.cend()});
    }
    vector<string> alertNames(vector<string>& keyName, vector<string>& keyTime) {
        vector<pair<string, int>> v;
        for (int i = 0; i != keyName.size(); ++i) {
            v.push_back({keyName[i], convertToInt(keyTime[i])});
        }
        sort(v.begin(), v.end(), [](pair<string, int> &lhs, pair<string, int> &rhs) {
            return lhs.second < rhs.second;
        });
        unordered_map<string, vector<int>> um;
        for (const auto &e: v) {
            um[e.first].push_back(e.second);
        }
        vector<string> answer;
        for (const auto &e: um) {
            if (e.second.size() >= 3) {
                for (int i = 2; i < e.second.size(); ++i) {
                    if ((e.second[i] - e.second[i - 2]) <= 60) {
                        answer.push_back(e.first);
                        break;
                    }
                }   
            }
        }
        sort(answer.begin(), answer.end());
        return answer;
    }
};

int main() {
  
  
  
  return 0;  
}
