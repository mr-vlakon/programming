class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if (p.size() > s.size()) return {};
        unordered_map<char, int> um;
        for (const auto &e: p) {
            um[e]++;
        }
        unordered_map<char, int> hash;
        for (int i = 0; i != p.size(); ++i) {
            hash[s[i]]++;
        }
        vector<int> answer;
        if (hash == um) {
            answer.push_back(0);
        }
        for (int i = 1; i != s.size() - p.size() + 1; ++i) {
            hash[s[i - 1]]--;
            if (hash[s[i - 1]] == 0) {
                hash.erase(s[i - 1]);
            }
            hash[s[i + p.size() - 1]]++;
            if (hash == um) {
                answer.push_back(i);
            }
        }
        return answer;
    }
};

int main() {
  
  
  
  
  return 0;  
}
