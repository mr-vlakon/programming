class Solution {
public:
    string breakPalindrome(string palindrome) {
        if (palindrome.size() == 1) return "";
        if (count(palindrome.cbegin(), palindrome.cend(), 'a') == palindrome.size()) {
            palindrome[palindrome.size() - 1] = 'b';
            return palindrome;
        }
        auto pos = palindrome.find_first_not_of('a');
        if (pos != palindrome.size() / 2)
            palindrome[pos] = 'a'; 
        else {
            palindrome[palindrome.size() - 1] = 'b';
        }
        return palindrome;
    }
};

int main() {
  
  
  
  return 0;  
}
