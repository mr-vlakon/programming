class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        istringstream is(sentence);
        string s;
        int index = 1;
        while (is >> s) {
            auto res = std::mismatch(searchWord.begin(), searchWord.end(), s.begin());
            if (res.first == searchWord.end()) {
                return index;
            }
            ++index;
        }
        return -1;
    }
};

int main() {

  return 0;  
}
