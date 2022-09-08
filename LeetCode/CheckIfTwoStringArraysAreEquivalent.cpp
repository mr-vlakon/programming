class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string s1;
        for (const auto &e: word1) {
            s1 += e;
        }
        string s2;
        for (const auto &e: word2) {
            s2 += e;
        }
        return s1 == s2;
    }
};

int main() {
  
  
  return 0;  
}
