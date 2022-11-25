class Solution {
public:
    int minimumOneBitOperations(int n) {
        vector<int> v;
        while(n) {
            v.push_back(n % 2);
            n /= 2;
        }
        int answer = 0;
        int sign = 1;
        for (int i = v.size() - 1; i >= 0; --i) {
            if (v[i] != 0) {
                answer += sign * (pow(2, i + 1)  - 1);
                sign = -sign;
            }
        }
        return answer;
    }
};

int main() {
  
  
  
  return 0;  
}
