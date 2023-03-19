class Solution {
public:
    string reformatNumber(string number) {
        vector<char> v;
        for (const auto &e: number) {
            if (isdigit(e)) {
                v.push_back(e);
            }
        }
        string answer;
        int cnt = 0;
        int cnt1 = 0;
        int count = v.size() / 3;
        int tmp = v.size() - count * 3;
        if (tmp == 1) {
            --count;
            tmp += 3;
        }
        int q = 0;
        for (int i = 0; i != v.size(); ++i) {
            if (q != count) {
                ++cnt;
                answer.push_back(v[i]);
                if (cnt == 3) {
                    if (i != (v.size() - 1)) {
                        answer.push_back('-');
                    }
                    cnt = 0;
                    ++q;
                }
            } else {
                if (tmp == 4) {
                    ++cnt1;
                    answer.push_back(v[i]);
                    if (cnt1 == 2) {
                        if (i != (v.size() - 1)) {
                            answer.push_back('-');
                        }
                        cnt1 = 0;
                    }
                } else {
                    answer.push_back(v[i]);
                }
            }
            
        }
        return answer;
    }
};

int main() {
  
  
  return 0;  
}
