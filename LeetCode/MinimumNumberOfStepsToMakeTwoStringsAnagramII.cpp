class Solution {
public:
    int minSteps(string s, string t) {
        unordered_map<char, int> um1;
        for (const auto &e: s) {
            ++um1[e];
        }
        unordered_map<char, int> um2;
        for (const auto &e: t) {
            ++um2[e];
        }
        int answer = 0;
        for (auto &e: um2) {
            auto it = um1.find(e.first);
            if (it == um1.cend()) {
                answer += e.second;
                um1[e.first] = e.second;
            } else {
                if (it->second > e.second) {
                    answer += (it->second - e.second);
                    e.second = it->second;
                } else if (it->second < e.second) {
                    answer += (e.second - it->second);
                    it->second = e.second;
                }
            }
        }
        for (auto &e: um1) {
            auto it = um2.find(e.first);
            if (it == um2.cend()) {
                answer += e.second;
                um1[e.first] = e.second;
            } else {
                if (it->second > e.second) {
                    answer += (it->second - e.second);
                    e.second = it->second;
                } else if (it->second < e.second) {
                    answer += (e.second - it->second);
                    it->second = e.second;
                }
            }
        }
        return answer;
    }
};

int main() {
  
  
  
  return 0;  
}
