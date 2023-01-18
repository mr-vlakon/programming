class Solution {
public:
    string findLongestWord(string s, vector<string>& dictionary) {
        sort(dictionary.begin(), dictionary.end());
        stable_sort(dictionary.begin(), dictionary.end(), [&](const string &lhs, const string &rhs)     {
            return lhs.size() > rhs.size();
        });
        for (int i = 0; i != dictionary.size(); ++i) {
            auto start = s.begin();
            int j = 0;
            while (start != s.end() && j != dictionary[i].size()) {
                if (*start == dictionary[i][j]) {
                    ++j;
                }
                ++start;
            }
            if (j == dictionary[i].size()) {
                return dictionary[i];
            }
        }
        return "";
    }
};

int main() {
  

  return 0;
}
