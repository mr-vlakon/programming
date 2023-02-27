class Solution {
public:
    int convertTime(string current, string correct) {
        string s = current;
        auto pos = s.find(":");
        string tmpH(s.cbegin(), s.cbegin() + pos);
        int curH = stoi(tmpH);
        string tmpM(s.cbegin() + pos + 1, s.cend());
        int curM = stoi(tmpM);
        int resCur = curH *  60 + curM;
        
        s = correct;
        pos = s.find(":");
        tmpH = string(s.cbegin(), s.cbegin() + pos);
        curH = stoi(tmpH);
        tmpM = string(s.cbegin() + pos + 1, s.cend());
        curM = stoi(tmpM);
        int resCorr = curH *  60 + curM;
        
        int diff = abs(resCorr - resCur);
        int cnt = 0;
        while (diff) {
            if (diff >= 60) {
                diff -= 60;
                ++cnt;
            } else if (diff >= 15) {
                diff -= 15;
                ++cnt;
            } else if (diff >= 5) {
                diff -= 5;
                ++cnt;
            } else {
                cnt += diff;
                diff = 0;
            }
        }        
        return cnt;       
    }
};

int main() {
  
  
  return 0;  
}
