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

int main() {
  
  
  
  return 0;  
}
