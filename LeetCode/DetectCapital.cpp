class Solution {
public:
    bool detectCapitalUse(string word) {
        bool firstCapital = false;
        int cnt = 0;
        for (int i = 0; i != word.size(); ++i) {
            if ((word[i] >= 'A') && (word[i] <= 'Z')) {
                if (i == 0) {
                    firstCapital = true;
                }
                ++cnt;
            }
        }
        return (cnt == 0) ? true : (cnt == word.size()) ? true : (firstCapital == true && cnt == 1) ? true : (cnt == word.size()) ? true : false;
    }
};

int main() {
  
  
  return 0;  
}
