class Solution {
public:
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        long long answer = 0;
        hFences.push_back(1);
        hFences.push_back(m);
        vFences.push_back(1);
        vFences.push_back(n);
        sort(hFences.begin(), hFences.end());
        sort(vFences.begin(), vFences.end());
        int maxStreakh = 0;
        int tmp = 0;
        unordered_set<int> unor1;
        for (int i = 0; i != vFences.size(); ++i) {
            for (int j = i; j != vFences.size(); ++j) {
                unor1.insert(vFences[j] - vFences[i]);
            }
        }
        for (int i = 0; i != hFences.size(); ++i) {
            for (int j = i; j != hFences.size(); ++j) {
                if (unor1.find(hFences[j] - hFences[i]) != unor1.cend()) {
                    answer = max(answer, static_cast<long long>(hFences[i] - hFences[j])*static_cast<long long>(hFences[i] - hFences[j]));
                }
            }
        }
        return (answer == 0) ? -1 : (answer % 1000000007);
    }
};

int main()
{



  return 0;
}
