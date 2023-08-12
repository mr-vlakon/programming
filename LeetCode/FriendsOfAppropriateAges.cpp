class Solution {
public:
    void binary(const vector<int> &ages, const int &tar, int &left, int &right) {
        if (left > right) return;
        int mid = (left + right) / 2;
        if (ages[mid] <= tar) {
            right = mid - 1;
            binary(ages, tar, left, right);
        } else {
            t = mid;
            left = mid + 1;
            binary(ages, tar, left, right);
        }
    }
    int numFriendRequests(vector<int>& ages) {
        sort(ages.rbegin(), ages.rend());
        int answer = 0;
        int cnt = 1;
        int tmp = 0;
        int left = 0;
        int right = ages.size() - 1;
        for (int i = 0; i < ages.size() - 1;) {
            left = i + 1;
            right = ages.size() - 1;
            binary(ages, 0.5*ages[i] + 7.0, left, right);
            cnt = 1;
            tmp = ages[i];
            ++i;
            while ((i < ages.size()) && (ages[i] == tmp)) {
                ++cnt;
                ++i;
            }
            answer += cnt*(t - i + cnt);
            t = i;
        }
        return answer;
    }
private:
    int t = 0;
};

int main() {



  return 0;
}
