class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(), tokens.end());
        int start = 0;
        int end = tokens.size() - 1;
        int answer = 0;
        while (start <= end) {
            if (power >= tokens[start]) {
                answer++;
                power -= tokens[start];
                ++start;
            } else if ((answer >= 1 && (power + tokens[end]) >= tokens[start]) && (end != start))           {
                power += tokens[end];
                --answer;
                --end;
            } else {
                break;
            }
        }
        return answer;
    }
};

int main() {
  
  
  
  
  return 0;  
}
