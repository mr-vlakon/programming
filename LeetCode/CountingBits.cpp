class Solution {
public:
    vector<int> countBits(int n) {
        int i = 0;
        vector<int> result;
        while (i <= n) {
            int tmp = i;
            vector<int> v;
            while(tmp) {
                int q = tmp % 2;
                v.push_back(q);
                tmp /= 2;
            }
            result.push_back(count(v.cbegin(), v.cend(),1));
            ++i;
        }
        return result;
    }
};

int main() {

  return 0;  
}
