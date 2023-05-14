class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int answer = 0;
        for (const auto &e: derived) {
            answer ^= e;
        }
        return answer == 0;
    }
};

int main() {
  
  
  return 0;  
}
