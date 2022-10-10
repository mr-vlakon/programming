class Solution {
public:
    string largestOddNumber(string num) {
        reverse(num.begin(), num.end());
        while (num.size() != 0 && (*num.begin() - '0') % 2 == 0) {
            num.erase(num.begin());
            
        }
        reverse(num.begin(), num.end());
        return num;
    }
};

int main() {
  
  
  return 0;  
}
