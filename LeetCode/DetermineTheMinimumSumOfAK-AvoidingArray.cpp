/*
class Solution {
public:
    void generate(const int &n, const int &k, int &sum, int cnt, vector<bool> &um) {
        if (cnt == n) {
            answer = min(answer, sum);
            return;
        }
        if (sum >= answer) return;
        for (int i = 1; i <= 60; ++i) {
            if (um[i] == false) {
                if ((k - i) >= 0 && um[k - i] == false) {
                    um[i] = true;
                    sum += i;
                    generate(n,  k, sum, cnt + 1, um);
                    sum -= i;
                    um[i] = false;
                } else if ((k - i) < 0) {
                    um[i] = true;
                    sum += i;
                    generate(n,  k, sum, cnt + 1, um);
                    sum -= i;
                    um[i] = false;
                    
                }
            }
        }
    }
    
    int minimumSum(int n, int k) {
        vector<int> v;
        int i = 0;
        int t = 1;
        int sum = 0;
        unordered_map<int ,int> um;
        while (i < n && t < 1000) {
            auto it = um.find(k - t);
            if (it == um.cend()) {
                sum += t;
                ++i;
                um[t] = 1;
                ++t;
            } else {
                ++t;
            }  
        }
        return sum;
    }
private:
    int answer = 0;
};
*/
// better solution
class Solution {
public:
    int minimumSum(int n, int k) {
        int target = k;
        if (n <= (target / 2)) return (n*(n + 1) / 2) % 1000000007;
        int half = target / 2;
        int finish = target + n - half - 1;
        return (static_cast<long long>(half)*(half + 1) / 2 + static_cast<long long>(finish)*(finish + 1) / 2 - static_cast<long long>(target)*(target - 1) /2) % 1000000007;
    }
};

int main() 
{



  return 0;
}
