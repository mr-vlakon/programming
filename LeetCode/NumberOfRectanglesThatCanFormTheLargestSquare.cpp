class Solution {
public:
    int countGoodRectangles(vector<vector<int>>& rectangles) {
        int answer = 0;
        for (int i = 0; i != rectangles.size(); ++i) {
            if (min(rectangles[i][0], rectangles[i][1]) > answer)
                answer = min(rectangles[i][0], rectangles[i][1]);
        }
        
        int cnt = 0;
        for (const auto &e: rectangles) {
            if (min(e[0],e[1]) >= answer)
                ++cnt;
        }
        return cnt;
        
    }
};

int main() {
  
  
  
  return 0;  
}
