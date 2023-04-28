class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        horizontalCuts.push_back(h);
        horizontalCuts.push_back(0);
        verticalCuts.push_back(0);
        verticalCuts.push_back(w);
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());        
        int maxV1 = 0;
        for (int i = 1; i != horizontalCuts.size(); ++i) {
            if ((horizontalCuts[i] - horizontalCuts[i - 1]) > maxV1) {
                maxV1 = (horizontalCuts[i] - horizontalCuts[i - 1]);
            }
        }
        int maxV2 = 0;
        for (int i = 1; i != verticalCuts.size(); ++i) {
            if ((verticalCuts[i] - verticalCuts[i - 1]) > maxV2) {
                maxV2 = (verticalCuts[i] - verticalCuts[i - 1]);
            }
        }
        return static_cast<long long>(maxV1)*maxV2 % 1000000007;
    }
};

int main() {
  
  
  
  return 0;  
}
