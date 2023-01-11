class Solution {
public:
    int titleToNumber(string columnTitle) {
        int answer = 0;
        long long cnt = 1;
        for (int i = columnTitle.size() - 1;  i >= 0; --i) {
            answer += (columnTitle[i] - 'A' + 1) * static_cast<int>(cnt);
            cnt *= 26;
        }
        return answer;
    }
};

int main() {
  
  
  return 0;  
}
