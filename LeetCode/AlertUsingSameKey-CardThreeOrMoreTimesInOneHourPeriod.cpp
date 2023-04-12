class Solution {
public:
    int convertToInt(const string &s) {
        return 10*(s[0] - '0')*60 + (s[1] - '0')*60 + (s[3] - '0')*10 + (s[4] - '0');
    }
    vector<string> alertNames(vector<string>& keyName, vector<string>& keyTime) {
        unordered_map<string, vector<int>> um;
        for (int i = 0; i != keyName.size(); ++i) {
            um[keyName[i]].push_back(convertToInt(keyTime[i]));
        }
        for (auto &e: um) {
            sort(e.second.begin(), e.second.end());
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
