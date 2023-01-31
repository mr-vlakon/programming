class Solution {
public:
    string intToRoman(int num) {
        int cnt = 10;
        string result;
        while (num != 0) {
            int tmp = num % cnt;
            if (tmp == 0) {
                cnt *= 10;
                continue;
            }
            num -= tmp;
            if (tmp == 9) {
                result.push_back('X');
                result.push_back('I');
            } else if (tmp >= 5 && tmp < 9) {
                int diff = tmp - 5;
                while (diff) {
                    result.push_back('I');
                    --diff;
                }
                result.push_back('V');    
            } else if (tmp == 4) {
                    result.push_back('V');
                    result.push_back('I');
            } else if (tmp < 4) {
                while (tmp) {
                    result.push_back('I');
                    --tmp;
                }
            } else if (tmp == 10) {
                result.push_back('X');
            } else if (tmp == 40) {
                result.push_back('L');
                result.push_back('X');
            } else if (tmp == 90) {
                result.push_back('C');
                result.push_back('X');
            } else if (tmp >= 50 && tmp < 100){
                int diff = tmp - 50;
                while (diff) {
                    result.push_back('X');
                    diff -= 10;
                }
                result.push_back('L');
            } else if (tmp < 50) {
                while (tmp > 0) {
                    result.push_back('X');
                    tmp -= 10;
                }
            } else if (tmp == 500) {
                result.push_back('D');
            } else if (tmp == 400) {
                result.push_back('D');
                result.push_back('C'); 
            } else if (tmp < 400) {
                while (tmp > 0) {
                    result.push_back('C');
                    tmp -= 100;
                }
            } else if (tmp == 900) {
                result.push_back('M');
                result.push_back('C');
            } else if (tmp < 900) {
                int diff = tmp - 500;
                while (diff > 0) {
                    result.push_back('C');
                    diff -= 100;
                }
                result.push_back('D');
            } else if (tmp >= 1000) {
                while (tmp) {
                    result.push_back('M');
                    tmp -= 1000;
                }
            }
            cnt *= 10;
        }
        return {result.rbegin(), result.rend()};
    }
};

int main() {
  
  
  
  return 0;  
}
