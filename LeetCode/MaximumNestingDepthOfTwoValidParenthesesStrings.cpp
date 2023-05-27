class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int left = 0;
        int maxV = 0;
        for (int i = 0; i != seq.size(); ++i) {
            if (seq[i] == '(') {
                ++left;
            } else {
                --left;
            }
            maxV = max(maxV, left);
        }
        vector<int> answer(seq.size(), 0);
        int depth = 0;
        maxV /= 2;
        for (int i = 0; i != seq.size(); ++i) {
            if (seq[i] == '(') {
                ++depth;
                if (depth <=  maxV) {
                    answer[i] = 0; 
                } else if (depth > maxV) {
                    answer[i] = 1;
                } 
            } else {
                --depth;
                if (depth >= maxV) {
                    answer[i] = 1;
                } else {
                    answer[i] = 0;
                }
            }
        }
        return answer;
    }
};

int main() {
  
  
  
  return 0;  
}
