class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        vector<int> initial(1, pushed[0]);
        int k = 0;
        int i = 1;
        if (pushed == popped) return true;
        while (true) {
            if (initial.size() != 0 && popped[k] == initial.back()) {
                initial.pop_back();
                ++k;
            } else if (i < pushed.size()) {
                initial.push_back(pushed[i]);
                ++i;
            } else {
                break;
            }
            
        }
        
        return k == popped.size() && i == pushed.size();
    }
};

int main() {
  
  
  
  return 0;  
}
