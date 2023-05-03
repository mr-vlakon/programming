class Solution {
public:
    vector<string> getFolderNames(vector<string>& names) {
        unordered_set<string> us;
        vector<string> answer;
        unordered_map<string, int> cnt;
        int k = 0;
        string tmp;
        for (const auto &e: names) {
            if (us.find(e) == us.cend()) {
                answer.push_back(e);
                us.insert(e);
            } else {
                k = cnt[e] + 1;
                tmp = e + "(" + to_string(k) + ")";
                while (us.find(tmp) != us.cend()) {
                    ++k;
                    tmp = e + "(" + to_string(k) + ")";    
                }
                us.insert(tmp);
                cnt[e] = k;
                answer.push_back(tmp);
            }
        }
        return answer;
    }
};
/*
class Solution {
public:
    vector<string> getFolderNames(vector<string>& names) {
        vector<string> answer;
        unordered_map<string, int> cnt;
        int k = 0;
        string tmp;
        for (const auto &e: names) {
            if (cnt.find(e) == cnt.cend()) {
                answer.push_back(e);
                cnt[e] = 0;
            } else {
                k = cnt[e] + 1;
                tmp = e + "(" + to_string(k) + ")";
                while (cnt.find(tmp) != cnt.cend()) {
                    ++k;
                    tmp = e + "(" + to_string(k) + ")";    
                }
                cnt[e] = k;
                cnt[tmp] = 0;
                answer.push_back(tmp);
            }
        }
        return answer;
    }
};
*/

int main() {
  
  
  
  return 0;  
}
