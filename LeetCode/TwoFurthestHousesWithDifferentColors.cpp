class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int max = 0;
        for (int i = 0; i != colors.size() - 1; ++i) {
            for (int j = i + 1; j != colors.size(); ++j) {
                if (colors[j] != colors[i]) {
                    if (abs(j - i) > max) {
                        max = abs(j - i);
                    }
                }
            }
        }
        return max;
    }
};

int main() {
  
  
  return 0;  
}
