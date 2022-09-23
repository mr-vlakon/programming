class Solution {
public:
    int minSwaps(string s) {
        vector<char> one;
        vector<char> zero;
        for (const auto &e: s) {
            if (e == '1') {
                one.push_back(e);
            } else {
                zero.push_back(e);
            }
        }
        if (abs(static_cast<int>(one.size()) - static_cast<int>(zero.size())) > 1) return -1;
        int l1 = 0, k1 = 0, l2 = 0, k2 = 0;
        string res;
        string first;
        string second;
        int status = 0;
        if (zero.size() == one.size()) {
            status = 1;
            for (decltype(s.size()) i = 0; i != s.size(); ++i) {
                    if (i % 2 == 0) {
                            first.push_back(zero[l1++]);
                            second.push_back(one[l2++]);
                    } else {
                            first.push_back(one[k1++]);
                            second.push_back(zero[k2++]);
                    }
            }
        }
        int l = 0, k = 0;
        if (zero.size() > one.size()) {
            status = 2;
            for (decltype(s.size()) i = 0; i != s.size(); ++i) {
                    if (i % 2 == 0) {
                            first.push_back(zero[l++]);
                    } else {
                            first.push_back(one[k++]);
                    }
            }
        }
        if (one.size() > zero.size()) {
            status = 3;
            for (decltype(s.size()) i = 0; i != s.size(); ++i) {
                    if (i % 2 == 0) {
                            first.push_back(one[l++]);
                    } else {
                            first.push_back(zero[k++]);
                    }
            }
        }
        int cnt = 0;
        if (status == 2 || status == 3) {
            for (decltype(first.size()) i = 0; i != first.size(); ++i) {
                if (first[i] != s[i])
                    ++cnt;
            }
        }
        int cnt1 = 0, cnt2 = 0;
        if (status == 1) {
            for (decltype(first.size()) i = 0; i != first.size(); ++i) {
                if (first[i] != s[i])
                    ++cnt1;
            }
            
            for (decltype(second.size()) i = 0; i != second.size(); ++i) {
                if (second[i] != s[i])
                    ++cnt2;
            }
            if (cnt1 > cnt2) {
                cnt = cnt2;
            } else
                cnt = cnt1;
        }
        return cnt / 2;
        
    }
};

int main() {
  
  
  return 0;  
}
