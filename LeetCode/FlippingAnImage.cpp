class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        for (auto &e: image) {
            reverse(e.begin(), e.end());
            for (auto &p : e) {
                if (p == 1) {
                    p = 0;
                } else {
                    p = 1;
                }
            }
        }
        return image;
    }
};

int main() {
  
  
  return 0;  
}
