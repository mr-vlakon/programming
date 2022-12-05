/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        long long left = 0;
        long long right = n;
        while (left != right) {
            auto mid = (left + right) / 2;
            if (guess(mid + 1) == -1) {
                right = mid;
            } else if (guess(mid + 1) == 1) {
                left = mid + 1;
            } else {
                return mid + 1;
            }
        }
        return right + 1;
    }
};

int main() {
  
  
  
  return 0;  
}
