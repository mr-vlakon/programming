class Solution {
public:
    int maximumGroups(vector<int>& grades) {
        sort(grades.begin(), grades.end());
        int sumF = grades[0];
        int sumS = 0;
        int i = 1;
        int cnt = 1;
        int tmp = i;
        long long prev = grades[i];
        while (tmp < grades.size() && (i + tmp + 1) <= grades.size()) {
            long long sum = accumulate(grades.cbegin() + i, grades.cbegin() + i + tmp + 1, 0LL);
            ++i;
            tmp += i;
            if (prev < sum) {
                ++cnt;
            } else {
                break;
            }
            prev = sum;
        }
        return cnt;        
    }
};

int main() {
  
  return 0;  
}
