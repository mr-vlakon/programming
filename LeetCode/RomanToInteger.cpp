class Solution {
public:
    int romanToInt(string s) {
        int answer = 0;
        for (int i = 0; i < s.size(); ++i) {
            if ((i + 1) < s.size() && s[i] == 'I' && s[i + 1] == 'V') {
                answer += 4;
                ++i;
            } else if ((i + 1) < s.size() && s[i] == 'I' && s[i + 1] == 'X') {
                answer += 9;
                ++i;
            } else if ((i + 1) < s.size() && s[i] == 'X' && s[i + 1] == 'L') {
                answer += 40;
                ++i;
            } else if ((i + 1) < s.size() && s[i] == 'X' && s[i + 1] == 'C') {
                answer += 90;
                ++i;
            } else if ((i + 1) < s.size() && s[i] == 'C' && s[i + 1] == 'D') {
                answer += 400;
                ++i;
            } else if ((i + 1) < s.size() && s[i] == 'C' && s[i + 1] == 'M') {
                answer += 900;
                ++i;
            } else {
                switch(s[i]) {
                    case 'I': {
                        answer += 1;
                        break;
                    }
                    case 'V': {
                        answer += 5;
                        break;
                    }
                    case 'X': {
                        answer += 10;
                        break;
                    }
                    case 'L': {
                        answer += 50;
                        break;
                    }
                    case 'C': {
                        answer += 100;
                        break;
                    }
                    case 'D': {
                        answer += 500;
                        break;
                    }
                    case 'M': {
                        answer += 1000;
                        break;
                    }
                    default: {
                        break;
                    }
                }
            }
        }
        return answer;
    }
};

int main() {
  
  
  
  return 0;  
}
