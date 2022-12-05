// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        long long left = 0;
        long long right = n;
        while (left != right) {
            auto mid = (left + right) / 2;
            if (isBadVersion(mid + 1)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return right + 1;
    }
};

int main() {
  
  return 0;  
}
