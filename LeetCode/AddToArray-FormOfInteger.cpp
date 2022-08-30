class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        vector<int> v;
        while(k) {
           int tmp = k % 10;
           v.push_back(tmp);
           k /= 10;
        }
        reverse(num.begin(), num.end());
        //reverse(v.begin(), v.end());
        int i = 0;
        vector<int> result;
        int tmp = 0;
        int x = 0;
        while (i != max(v.size(), num.size())) {
            
            x = tmp;
            if ( i < v.size())
                x += v[i];
            if ( i < num.size())
                x += num[i];
            if (x / 10 == 0)
                result.push_back(x);
            else
                result.push_back(x % 10);
            tmp = x / 10;
            
            ++i;
        }
        
        if (tmp > 0)
            result.push_back(tmp);
        reverse(result.begin(), result.end());
        
        return result;
    }
};

int main() {
  
  
  return 0;  
}
