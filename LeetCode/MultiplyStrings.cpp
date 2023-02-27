class Solution {
public:
    string multiply(string num1, string num2) {
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        string answer(203, '0');
        int tmp = 0;
        int k = 0;
        int ost = 0;
        int q = 0;
        int r = 0;
        for (int i = 0; i != num2.size(); ++i) {
             for (int j = 0; j != num1.size(); ++j) {
                tmp = (num1[j] - '0') * (num2[i] - '0');
                k = 0;
                if (tmp != 0) {
                    while (tmp) {
                        ost = tmp % 10;
                        int t = answer[k + j + i] - '0';
                        if (answer[k + j + i] != '0' && ( (t + ost) <= 9)) {
                            answer[k + j + i] = ost + t + '0';
                        } else if (answer[k + j + i] == '0') {
                            answer[k + j + i] = ost  + '0';
                        } else if ((t + ost) >= 10) {
                            answer[k + j + i] = (ost + t) % 10 + '0';
                            q = (answer[k + j + i + 1] - '0') + 1;
                            r = 1;    
                            if (q <= 9) {
                                answer[k + j + i + 1] = q + '0';
                            } else {                           
                                while (q >= 10) {
                                    answer[k + j + i + r] = (q % 10) + '0';
                                    q = (q / 10) + (answer[k + j + i + r + 1] - '0');
                                    ++r;
                                }
                                answer[k + j + i + r] += 1;
                            }
                        }
                        ++k;
                        tmp /= 10;
                    }
                } 
            }
        }
        reverse(answer.begin(), answer.end());
        auto it = find_if(answer.begin(), answer.end(), [](const char &c) {
            return c != '0';
        });
        if (it == answer.end()) {
            return "0";
        }
        return {it, answer.end()};        
    }
};

int main() {
  
  
  return 0;  
}
