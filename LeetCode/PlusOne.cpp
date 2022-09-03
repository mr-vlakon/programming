class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> res;
        reverse(digits.begin(), digits.end());
        int perenos = 0;
        for (decltype(digits.size()) i = 0; i != digits.size(); ++i) {
            if(i == 0) {
                digits[i] += 1;
                if (digits[i] / 10 == 1) {
                    digits[i] %= 10;
                    perenos = 1;
                }
            } else {
                digits[i] += perenos;
                if (digits[i] / 10 == 1) {
                    digits[i] %= 10;
                    perenos = 1;
                } else
                    perenos = 0;
            }
            res.push_back(digits[i]);  
        }
        if (perenos > 0) {
            res.push_back(perenos);
        }
        reverse(res.begin(), res.end());    
        return res;
    }
};

int main() {

  return 0;  
}
