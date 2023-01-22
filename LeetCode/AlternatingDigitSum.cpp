class Solution {
public:
    int alternateDigitSum(int n) {
        vector<int> v;
        while (n) {
            v.push_back(n % 10);
            n /= 10;
        }
        int sign = 1;
        int answer = 0;
        for (int i = v.size() - 1; i >= 0; --i) {
            answer += v[i] * sign;
            sign =-sign;
        }
        return answer;
    }
};

int main() {
  
  
  return 0;  
}
