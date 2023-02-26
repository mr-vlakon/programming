class Solution {
public:
    void generate(int i, vector<int> &v, int cnt) {
        if (i == 10) {
            if (cnt == turn) {
                int minute = 0;
                for (int j = 0; j != 6; j++) {
                    minute += pow(2, j) * v[j];
                }
                int hour = 0;
                for (int j = 6; j != 10; ++j) {
                    hour += pow(2, (j - 6) )  * v[j];
                }
                string m_ = to_string(minute);
                if (m_.size() == 1) {
                    m_.insert(m_.begin(), '0');
                }
                if (hour < 12 && minute < 60)
                    res.push_back(to_string(hour) + ":" + m_);
                }
                return;
        }
        if (i > 10) {
            return;
        }
        v.push_back(1);
        generate(i + 1, v, cnt + 1);
        v.pop_back();
        v.push_back(0);
        generate(i + 1, v, cnt);
        v.pop_back();
    }
    vector<string> readBinaryWatch(int turnedOn) {
        vector<int> v; 
        turn = turnedOn; 
        generate(0, v, 0);
        return res;  
    }
private:
    vector<string> res;
    int turn = 0;
};

int main() {
  
  
  
  return 0;  
}
