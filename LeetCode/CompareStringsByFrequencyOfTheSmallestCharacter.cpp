class Solution {
public:
    int f(const string &s) {
        auto min = *min_element(s.cbegin(), s.cend());
        return count(s.cbegin(), s.cend(), min);
    }
    
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        vector<int> wordsF; 
        for (const auto &e: words) {
            wordsF.push_back(f(e));
        }
        sort(wordsF.begin(), wordsF.end());
        vector<int> queriesF;
        for (const auto &e: queries) {
            queriesF.push_back(f(e));
        }
        vector<int> answer;
        for (const auto &e: queriesF) {
            auto ub = upper_bound(wordsF.cbegin(), wordsF.cend(), e);
            answer.push_back(wordsF.cend() - ub);
        }
        return answer;
    }
};

int main() {
  
  return 0;  
}
