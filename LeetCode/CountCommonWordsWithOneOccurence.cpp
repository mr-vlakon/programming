class Solution {
public:
    int countWords(vector<string>& words1, vector<string>& words2) {
        unordered_map<string, size_t> um1;
        for (const auto &e: words1) {
            ++um1[e];
        }
        vector<string> word1;
        for (const auto &e: um1) {
            if (e.second == 1)
                word1.push_back(e.first);
        }
        
        unordered_map<string, size_t> um2;
        for (const auto &e: words2) {
            ++um2[e];
        }
        vector<string> word2;
        for (const auto &e: um2) {
            if (e.second == 1)
                word2.push_back(e.first);
        }
        
        sort(word1.begin(), word1.end());
        sort(word2.begin(), word2.end());
        vector<string> answer;
        set_intersection(word1.begin(), word1.end(), word2.begin(), word2.end(), back_inserter(answer));
        return answer.size();
    }
};

int main() {
  
  
  return 0;  
}
