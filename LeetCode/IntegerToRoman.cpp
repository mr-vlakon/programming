class Solution {
public:
    string intToRoman(int num) {
        int cnt = 10;
        string result;
        while (num != 0) {
            int tmp = num % cnt;
            num -= tmp;
            if (cnt == 10 && tmp == 9) {
                result.push_back('X');
                result.push_back('I');
            } else if (cnt == 10 && tmp >= 5) {
                int diff = tmp - 5;
                while (diff) {
                    result.push_back('I');
                    --diff;
                }
                result.push_back('V');    
            } else if (cnt == 10 && tmp == 4) {
                    result.push_back('V');
                    result.push_back('I');
            } else if (cnt == 10 && tmp < 4) {
                while (tmp) {
                    result.push_back('I');
                    --tmp;
                }
            } else if (cnt == 100 && tmp == 50) {
                result.push_back('L');
            } else if (cnt == 100 && tmp == 10) {
                result.push_back('X');
            } else if (cnt == 100 && tmp == 40) {
                result.push_back('L');
                result.push_back('X');
            } else if (cnt == 100 && tmp == 90) {
                result.push_back('C');
                result.push_back('X');
            } else if (cnt == 100 && tmp >= 50){
                int diff = tmp - 50;
                while (diff) {
                    result.push_back('X');
                    diff -= 10;
                }
                result.push_back('L');
            } else if (cnt == 100 && tmp < 50) {
                while (tmp > 0) {
                    result.push_back('X');
                    tmp -= 10;
                }
            } else if (cnt == 1000 && tmp == 500) {
                result.push_back('D');
            } else if (cnt == 1000 && tmp == 400) {
                result.push_back('D');
                result.push_back('C'); 
            } else if (cnt == 1000 && tmp < 400) {
                while (tmp > 0) {
                    result.push_back('C');
                    tmp -= 100;
                }
            } else if (cnt == 1000 && tmp == 900) {
                result.push_back('M');
                result.push_back('C');
            } else if (cnt == 1000 && tmp > 500) {
                int diff = tmp - 500;
                while (diff > 0) {
                    result.push_back('C');
                    diff -= 100;
                }
                result.push_back('D');
            } else if (cnt == 10000 && tmp >= 1000) {
                while (tmp) {
                    result.push_back('M');
                    tmp -= 1000;
                }
            }
            cnt *= 10;
        }
        reverse(result.begin(), result.end());
        return result;
    }
};

int main() {
  
  
  
  return 0;  
}
