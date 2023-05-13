class Solution {
public:
    int countSeniors(vector<string>& details) {
        int answer = 0;
        for (const auto &e: details) {
            if(stoi(string(e.cbegin() + 11, e.cbegin() + 13)) > 60) {
                ++answer;
            }
        }
        return answer;
    }
};

int main() {
  
  
  
  return 0;  
}
