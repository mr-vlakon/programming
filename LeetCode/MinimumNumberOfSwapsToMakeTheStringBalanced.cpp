class Solution {
public:
    int minSwaps(string s) {
        int start = 0;
        int status = false;
        int end = s.size() - 1;
        int answer = 0;
        while (start < end) {
            if (s[start] == '[') {
                status++;
                ++start;
            } else if (status) {
                status--;
                ++start;
            } else {
                status++;
                ++start;
                end--;
                ++answer;
            }
        }
        return answer;
    }
};

int main() {
  
  
  return 0;  
}
