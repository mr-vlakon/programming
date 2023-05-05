class Solution {
public:
    int expressiveWords(string s, vector<string>& words) {
        int answer = 0;
        int start = 0;
        int start2 = 0;
        int cnt1 = 0;
        int cnt2 = 0;
        bool status = true;
        int diff = 0;
        char prev;
        for (const auto &e: words) {
            if (e.size() > s.size()) continue;
            start = 0;
            start2 = 0;
            cnt1 = 0;
            cnt2 = 0;
            status = true;
            while (start < s.size() || start2 < e.size()) {      
                if (s[start] != e[start2]) {
                    status = false;
                    break;
                }
                prev = e[start2];
                cnt1 = 0;
                cnt2 = 0;
                while (start < s.size() && s[start] == prev) {
                    ++cnt1;
                    ++start;
                }
                while (start2 < e.size() && e[start2] == prev) {
                    ++cnt2;
                    ++start2;
                }
                if ( (cnt1 < cnt2 || cnt1 < 3) && (cnt1 != cnt2)) {
                    status = false;
                    break;
                }
            }
            if (status) {
                ++answer;
            }
        }
        return answer;
    }
};

int main() {
  
  
  
  return 0;  
}
