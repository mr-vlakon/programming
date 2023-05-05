class Solution {
public:
    string largestMerge(string word1, string word2) {
        string result;
        int start1 = 0;
        int start2 = 0;
        while (start1 < word1.size() && start2 < word2.size()) {
            if (word1[start1] > word2[start2]) {
                result.push_back(word1[start1]);
                ++start1;
            } else if (word1[start1] < word2[start2]){
                result.push_back(word2[start2]);
                ++start2;
            } else if (string{word1.cbegin() + start1, word1.cend()} < string{word2.cbegin() + start2, word2.cend()}) {
                result.push_back(word2[start2]);
                ++start2;
            } else {
                result.push_back(word1[start1]);
                ++start1;
            }
        }
        if (start1 != word1.size()) {
            result += string(word1.cbegin() + start1, word1.cend());
        } else if (start2 != word2.size()) {
            result += string(word2.cbegin() + start2, word2.cend());
        }
        return result;
    }
};

int main() {
  
  
  
  
  return 0;  
}
