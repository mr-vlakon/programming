class Solution {
public:
    string reversePrefix(string word, char ch) {
        auto it = find(word.begin(), word.end(), ch);
        if (it == word.cend())
            return word;
        reverse(word.begin(), it + 1);
        return word;
    }
};

int main() {
  
  
  return 0;  
}
