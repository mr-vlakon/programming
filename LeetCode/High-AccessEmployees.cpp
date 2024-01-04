class Solution {
public:
    int convertToInt(string &s) {
        string hours;
        hours.push_back(s[0]);
        hours.push_back(s[1]);
        string minutes;
        minutes.push_back(s[2]);
        minutes.push_back(s[3]);
    
        return stoi(hours)*60 + stoi(minutes); 
    }
    
    vector<string> findHighAccessEmployees(vector<vector<string>>& access_times) {
        unordered_map<string, vector<string>> unor;
        for (const auto &e: access_times) {
            
            unor[e[0]].push_back(e[1]);
        }
        for (auto &e: unor) {
            sort(e.second.begin(), e.second.end());
        }
        
        vector<string> answer;
        for (auto &e: unor) {
            for (int i = 0; i != e.second.size(); ++i) {
                if ((i + 2) < e.second.size()) {
                    if ((convertToInt(e.second[i + 2]) - convertToInt(e.second[i])) < 60) {
                        answer.push_back(e.first);
                        break;
                    }
                }
            }
         }
        return answer;
    }
};
