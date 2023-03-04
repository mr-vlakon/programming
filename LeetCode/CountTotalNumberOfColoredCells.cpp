class Solution {
public:
    long long coloredCells(int n) {
        int i = 1;
        long long answer = 1;
        long long start = 4;
        while (i < n) {
            answer += start;
            start += 4;
            ++i;
        }        
        return answer;
    }
};

int main() {
  
  
  
  return 0;  
}
