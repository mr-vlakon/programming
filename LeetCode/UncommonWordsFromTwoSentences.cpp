class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        istringstream is1(s1);
        string s;
        unordered_map<string, size_t> um;
        while (is1 >> s) {
            ++um[s];
        }
        istringstream is2(s2);
        while (is2 >> s) {
            ++um[s];
        }
        
        vector<string> answer;
        for (const auto &e: um) {
            if (e.second == 1)
                answer.push_back(e.first);
        }
        
        return answer;
    }
};

int main() {
  
  
  return 0;  
}
