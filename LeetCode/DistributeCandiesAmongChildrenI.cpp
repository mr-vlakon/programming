class Solution {
public:
    void generate(const int &n, const int &limit, int current, int i, int cnt, vector<int> tmp) {
        if (i == n) {
            int t = 0;
                for (const auto &e: tmp) {
                    t += e;
                }
            if (cnt == 3) {
                if (t == n)
                ++answer;
            }
            return;
        }
        if (current < limit) {
            generate(n, limit, current + 1, i + 1, cnt, tmp);
            tmp.push_back(current);
            generate(n, limit, 0, i + 1, cnt + 1, tmp);
            tmp.pop_back();
        } else {
            tmp.push_back(current);
            generate(n, limit, 0, i + 1, cnt + 1, tmp);            
            tmp.pop_back();
        }
    }
    
    int distributeCandies(int n, int limit) {
        int t = 0;
        for (int i = 0; i <= n; ++i) {
            for (int j = i; j <= n; ++j) {
                    if ((i <= limit) && (j - i) <= limit && (n - j) <= limit) {
                        ++answer;
                    }
            }
        }
        return answer;
    }
private:
    int answer = 0;
};

int main()
{



  return 0;
}
