class Solution {
public:
    int numDifferentIntegers(string word) {
        for (auto &e: word) {
            if (isalpha(e))
                e = ' ';
        }
        istringstream is(word);
        unordered_set<string> us;
        string s;
        while (is >> s) {
            auto pos = s.find_first_not_of('0');
            if (pos == string::npos) {
                us.insert("0");
            } else {
                us.insert(string({s.cbegin() + pos, s.cend()}));
            }
        }
        return us.size();
    }
};

int main() {
  
  return 0;  
}
