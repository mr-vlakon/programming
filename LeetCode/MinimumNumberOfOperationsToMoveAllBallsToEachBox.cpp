class Solution {
public:
    vector<int> minOperations(string boxes) {
        vector<int> answer;
        for (decltype(boxes.size()) i = 0; i != boxes.size(); ++i) {
            int tmp = 0;
            for (decltype(boxes.size()) j = 0; j != boxes.size(); ++j) {
                if (i != j && boxes[j] == '1') {
                    tmp += abs(static_cast<int>(i) - static_cast<int>(j));
                }
            }
            answer.push_back(tmp);
        }
        
        return answer;
    }
};

int main() {
  
  
  
  return 0;  
}
