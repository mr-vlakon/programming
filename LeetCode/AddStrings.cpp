class Solution {
public:
    string addStrings(string num1, string num2) {
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        int i = 0;
        vector<int> result;
        int tmp = 0;
        int x = 0;
        while (i != max(num1.size(), num2.size())) {
            x = tmp;
            if ( i < num1.size())
                x += (num1[i] - '0');
            if ( i < num2.size())
                x += (num2[i] - '0');
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
        string res;
        for(const auto &e: result) {
            cout << e;
            res.push_back(static_cast<char>(e + '0'));
        }
        return res;
    }
};

int main() {
  
  return 0; 
}
