class Solution {
public:
    bool digitCount(string num) {
        for (decltype(num.size()) i = 0; i != num.size(); ++i) {
            auto cnt = count(num.cbegin(), num.cend(), char(i + '0'));
            if ( (num[i] - '0') != cnt)
                return false;
        }
        return true;
    }
};

int main() {
  
  
  return 0;  
}
