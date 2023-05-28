class Solution {
public:
    string removeTrailingZeros(string num) {
        int cnt = 0;
        for (int i = 0; i != num.size(); ++i) {
            if (num[i] == '0') ++cnt;
            else cnt = 0;
        }
        return {num.begin(), num.end() - cnt};
    }
};

int main() {
  
  
  
  
  return 0;  
}
