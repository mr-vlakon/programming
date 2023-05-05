class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int answer = INT_MAX;
        int tmp0 = 0;
        for (int i = 0; i != s.size(); ++i) {
            tmp0 += !(s[i] - '0');
            answer = min(answer, (i + 1 - 2*tmp0));
        }
        answer += tmp0;
        answer = min(answer, tmp0);
        return answer;
    }
};

int main() {
  
  
  
  return 0;  
}
