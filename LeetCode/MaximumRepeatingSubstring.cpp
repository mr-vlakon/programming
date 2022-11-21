class Solution {
public:
    int maxRepeating(string sequence, string word) {
        string s = word;
        int answer = 0;
        int i = 1;
        while (s.size() <= sequence.size()) {
            auto pos = sequence.find(s);
            if (pos != string::npos) {
                answer = i;
            } else {
                break;
            }
            s += word;
            ++i;
        }
        return answer;
    }
};

int main() {
  
  
  
  return 0;  
}
