class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int cnt1 = 0;
        int pos = 0;
        vector<vector<char>> tmp(box.size(), vector<char>(box[0].size(), '.'));
        for (int i = 0; i != box.size(); ++i) {
            for (int j = 0; j != box[0].size(); ++j) {
                if (box[i][j] == '#') {
                    ++cnt1;
                } else if (box[i][j] == '*') {
                    pos = j - 1;
                    tmp[i][j] = '*';
                    while (cnt1) {
                        tmp[i][pos] = '#';
                        --pos;
                        --cnt1;
                    }
                }
            }
            pos = box[0].size() - 1;    
            while (cnt1) {
                tmp[i][pos] = '#';
                --pos;
                --cnt1;    
            }           
        }
        vector<vector<char>> answer(box[0].size(), vector<char>(box.size(), ' '));
        for (int j = 0; j != box[0].size(); ++j) {
            for (int i = 0; i != box.size(); ++i) {
                answer[j][box.size() - i - 1] = tmp[i][j];
            }
        }
        return answer;
    }
};

int main() {
  
  
  
  return 0;  
}
