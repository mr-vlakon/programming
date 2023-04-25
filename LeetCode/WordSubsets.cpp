class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<string> answer;
        vector<int> um2(26, 0);
        vector<int> tmp(26, 0);   
        for (const auto &e: words2) {
            tmp.assign(26, 0);
            for (const auto &p: e) {
                tmp[p - 'a']++;
            }
            for (int i = 0; i != tmp.size(); ++i) {
                um2[i] = max(um2[i], tmp[i]);
            }
        }
        bool status = false;
        vector<int> um1(26, 0);
        for (const auto &e: words1) {
            um1.assign(26, 0);
            for (const auto &p: e) {
                um1[p - 'a']++;
            }
            status = true;
            for (int i = 0; i != um2.size(); ++i) {
                if (um1[i] < um2[i]) {
                    status = false;
                    break;
                }
            }
            if (status) {
                answer.push_back(e);
            }
        }
        return answer;
    }
};

int main() {
  
  
  
  return 0;  
}
