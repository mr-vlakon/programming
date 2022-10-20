class Solution {
public:
    int findComplement(int num) {
        string s;
        while (num) {
            s += to_string(num % 2);
            num /= 2;
        }
        for (auto &e: s) {
            if (e == '0') {
                e = '1';
            } else {
                e = '0';
            }
        }
        int i = 0;
        int answer = 0;
        for (const auto &e: s) {
            answer += (e - '0') * pow(2, i);
            ++i;
        }
        return answer;
    }
};

int main() {
  
  
  
  return 0;  
}
