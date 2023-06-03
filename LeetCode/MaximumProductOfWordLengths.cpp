class Solution {
public:
    int maxProduct(vector<string>& words) {
        int answer = 0;
        vector<int> vect(words.size(), 0);
        for (int i = 0; i != words.size(); ++i) {
            for (const auto &e: words[i]) {
                vect[i] |= (1 << (e - 'a'));      
            }
        }
        for (int i = 0; i != words.size() - 1; ++i) {
            for (int j = i + 1; j != words.size(); ++j) {
                if ((words[i].size() * words[j].size()) <= answer) continue;
                if ((vect[i]&vect[j]) == 0) {
                    answer = max(answer, static_cast<int>(words[i].size() * words[j].size()));
                }
            }
        }   
        return answer;
    }
};

int main() {
  
  
  
  
  return 0;  
}
