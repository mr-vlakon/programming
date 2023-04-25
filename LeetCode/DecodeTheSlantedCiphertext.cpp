class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        int size = encodedText.size() / rows;
        vector<vector<char>> v(rows, vector<char>(size, ' '));
        int cnt = 0;
        int row = 0;
        for (int i = 0; i != encodedText.size(); ++i) {
            v[row][cnt] = encodedText[i];
            ++cnt;
            if (cnt == size) {
                ++row;
                cnt = 0;
            }
        }
        int startCol = 0;
        int startRow = 0;
        string answer;
        int cnt0 = 0;
        for (int j = 0; j != v[0].size(); ++j) {
            startCol = j;
            startRow = 0;
            if (v[startRow][startCol] == ' ') {
                ++cnt0;
            } else {
                cnt0 = 0;
            }
            answer.push_back(v[startRow][startCol]);
            ++startCol;
            startRow++;
            while (startRow != v.size() && startCol != v[0].size()) {
                if (v[startRow][startCol] == ' ') {
                    ++cnt0;
                } else {
                    cnt0 = 0;
                }
                answer.push_back(v[startRow][startCol]);
                ++startRow;
                ++startCol;
            }
        }
        answer.erase(answer.cend() - cnt0, answer.cend());
        return answer;
    }
};

int main() {
  
  
  
  return 0;  
}
