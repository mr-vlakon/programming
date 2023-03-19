class Solution {
public:
    int minTimeToType(string word) {
        int answer = word.size();
        int start = 0;
        int pos1 = 0;
        int pos2 = 0;
        for (int i = 0; i != word.size(); ++i) {
            pos1 = abs((word[i] - 'a') - start);
            pos2 = (26 - pos1);
            answer += min(pos1, pos2);
            start = word[i] - 'a';
        }
        return answer;    
    }
};

int main() {
  
  
  
  return 0;  
}
