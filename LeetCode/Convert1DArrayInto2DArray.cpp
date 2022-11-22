class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        int size = original.size() / m;
        int i = 0;
        vector<vector<int>> answer;
        int j = 0;
        if (n * m != original.size()) return {};
        while (i != m) {
            answer.push_back({original.cbegin() + i * size, original.cbegin() + i * size + n});         
            ++i;
        }
        return answer;
    }
};

int main() {
  
  
  
  return 0;  
}
