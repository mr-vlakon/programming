class Solution {
public:
    string largestGoodInteger(string num) {
        string res;
        
        for (decltype(num.size()) i = 0; i <= num.size() - 3; ++i) {
            unordered_set<char> us(num.cbegin() + i, num.cbegin() + i + 3);
            if (us.size() == 1) {
                string tmp(num.cbegin() + i, num.cbegin() + i + 3);
                if (tmp > res)
                    res = tmp;
            }
        }
        
        
        return res;
    }
};

int main() {

  
  return 0;  
}
