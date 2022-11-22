class Solution {
public:
    string digitSum(string s, int k) {
        while (s.size() > k) {
            string res;
            int tmp = 0;
            for (int i = 0; i != s.size(); ++i) {
                if (i % k == 0 && i != 0) {
                    res += to_string(tmp);
                    tmp = s[i] - '0';
                } else { 
                    tmp += s[i] - '0';
                }
            }
            res += to_string(tmp);
            s = res;
        }
        return s;    
    }
};

int main() {
  
  
  return 0;  
}
