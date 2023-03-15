class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int answer = 0;
        for (int i = 0; i != patterns.size(); ++i) {
            if (word.find(patterns[i]) != string::npos) {
                ++answer;
            }
        }
        return answer;
    }
};

int main() {
  
  
  return 0;  
}
