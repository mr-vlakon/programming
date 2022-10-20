class Solution {
public:
    int getLucky(string s, int k) {
        string res;
        for (const auto &e: s) {
            res += to_string(e - 'a' + 1);
        }   
        
        int i = 0;
        int result = 0;
        while (i != k) {
            result = 0;
            for (const auto &e: res) {
                result += (e - '0');
            }
            res = to_string(result);
            ++i;
        }
        return stoi(res);
    }
};

int main() {
  
  
  return 0;  
}
