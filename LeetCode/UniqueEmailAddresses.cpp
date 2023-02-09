class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_map<string, unordered_set<string> > um;
        for (int i = 0; i != emails.size(); ++i) {
            string tmp;
            for (const auto &e: emails[i]) {
                if (e == '+' || e == '@') {
                    break;
                }
                if (e != '.') {
                    tmp.push_back(e);
                }
            }
            reverse(tmp.begin(), tmp.end());
            auto it = find(emails[i].cbegin(), emails[i].cend(), '@');
            um[string{it + 1, emails[i].cend()}].insert(tmp);
        }
        int answer = 0;
        for (const auto &e: um) {
            answer += e.second.size();
        }
        return answer;
    }
};

int main() {
  
  
  
  return 0;  
}
