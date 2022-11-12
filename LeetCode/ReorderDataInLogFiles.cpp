class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<string> digits_logs;
        vector<string> letter_logs;
        for (const auto &e: logs) {
            istringstream is(e);
            string s;
            is >> s;
            is >> s;
            if (s.find_first_not_of("0123456789") == string::npos) {
                digits_logs.push_back(e);
            } else {
                letter_logs.push_back(e);
            }            
        }
        vector<pair<string, string> > v;
        for (const auto &e: letter_logs) {
            istringstream is(e);
            string id;
            is >> id;
            string result;
            string s;
            while (is >> s) {
                result += s + " ";
            }
            result.erase(--result.cend());
            v.push_back({id, result});
        }
        sort(v.begin(), v.end(), [=](const pair<string, string> &lhs, 
                                     const pair<string, string> &rhs) {
            return lhs.first < rhs.first; 
        });
        stable_sort(v.begin(), v.end(), [=](const pair<string, string> &lhs, 
                                     const pair<string, string> &rhs) {
            return lhs.second < rhs.second; 
        });
        vector<string> answer;
        for (const auto &e: v) {
            string tmp = e.first + " " + e.second;
            answer.push_back(tmp);
        }
        copy(digits_logs.cbegin(), digits_logs.cend(), back_inserter(answer));
        return answer;
    }
};

int main() {
  
  
  
  return 0;  
}
