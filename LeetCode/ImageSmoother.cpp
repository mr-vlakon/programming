class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        vector<vector<int>> answer(img.size(), vector<int>(img[0].size(), 0));
        int cnt = 0;
        double tmp = 0;
        for (int i = 0; i != img.size(); ++i) {
            cnt = 0;
            tmp = 0.0;
            for (int j = 0; j != img[0].size(); ++j) {
                tmp += img[i][j];
                ++cnt;
                if ((i - 1) >= 0) {
                    tmp += img[i - 1][j];
                    ++cnt;
                }
                if ((i + 1) < img.size()) {
                    tmp += img[i + 1][j];
                    ++cnt;
                }
                if ((j + 1) < img[0].size()) {
                    tmp += img[i][j + 1];
                    ++cnt;
                    if ((i + 1) < img.size()) {
                        tmp += img[i + 1][j + 1];
                        ++cnt;
                    }
                    if ((i - 1) >= 0) {
                        tmp += img[i - 1][j + 1];
                        ++cnt;
                    }
                }
                if ((j - 1) >= 0) {
                    tmp += img[i][j - 1];
                    ++cnt;
                    if ((i + 1) < img.size()) {
                        tmp += img[i + 1][j - 1];
                        ++cnt;
                    }
                    if ((i - 1) >= 0) {
                        tmp += img[i - 1][j - 1];
                        ++cnt;
                    }
                }
                answer[i][j] = floor(tmp / cnt);
                tmp = 0;
                cnt = 0;
            }
        }
        return answer;
    }
};

int main() {
  
  
  
  return 0;  
}
