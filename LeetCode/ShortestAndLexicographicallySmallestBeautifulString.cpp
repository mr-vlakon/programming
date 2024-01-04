class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        deque<char> d;
        deque<deque<char>> dd;
        int counter = 0;
        for (int i = 0; i != s.size(); ++i) {
            if (s[i] == '1') {
                d.push_back(s[i]);
                ++counter;
                if (counter == k) {
                    dd.push_back(d);
                    while (d.front() != '1') {
                        d.pop_front();
                    }
                    --counter;
                    d.pop_front();
                }
            } else {
                d.push_back(s[i]);           
            }
        }
        deque<string> tmp;
        for (const auto &e: dd) {
            string str;
            bool isFirstNul = false;
            for (const auto &p : e) {
                if (p != '0' || isFirstNul) {
                    str.push_back(p);
                }
                if (p == '1') {
                    isFirstNul = true;
                }    
            }
            tmp.push_back(str);
        }
        sort(tmp.begin(), tmp.end(), [](string &lhs, string &rhs) {
            return lhs < rhs;  
        });
        stable_sort(tmp.begin(), tmp.end(), [](const string &lhs, const string &rhs) {
            return lhs.size() < rhs.size();  
        });
        auto minE = tmp.begin();
        string ans;
        if (minE != tmp.cend()) {
            ans = *minE;
        }
        return ans;
    }
};

int main()
{

  return 0;
}
