class Solution {
public:
    string originalDigits(string s) {
        vector<int> v(26, 0);
        for (const auto &e: s) {
            ++v[e - 'a'];
        }
        string answer;
        vector<int> ans(10, 0);
        ans[0] = v[25];
        int t = v[25];
        string iterable = "zero";
        for (const auto &e: iterable) {
            v[e - 'a'] -= t;
        }

        ans[2] = v['w' - 'a'];
        t = v['w' - 'a'];
        iterable = "two";
        for (const auto &e: iterable) {
            v[e - 'a'] -= t;
        }

        
        ans[4] = v['u' - 'a'];
        t = v['u' - 'a'];
        iterable = "four";
        for (const auto &e: iterable) {
            v[e - 'a'] -= t;
        }
        ans[5] = v['f' - 'a'];
        t = v['f' - 'a'];
        iterable = "five";
        for (const auto &e: iterable) {
            v[e - 'a'] -= t;
        }

        ans[6] = v['x' - 'a'];
        t = v['x' - 'a'];
        iterable = "six";
        for (const auto &e: iterable) {
            v[e - 'a'] -= t;
        }
        ans[7] = v['s' - 'a'];
        t = v['s' - 'a'];
        iterable = "seven";
        for (const auto &e: iterable) {
            v[e - 'a'] -= t;
        }
        ans[8] = v['g' - 'a'];
        t = v['g' - 'a'];
        iterable = "eight";
        for (const auto &e: iterable) {
            v[e - 'a'] -= t;
        }
        
        
        ans[3] = v['h' - 'a'];
        t = v['h' - 'a'];
        iterable = "three";
        for (const auto &e: iterable) {
            v[e - 'a'] -= t;
        }


        ans[9] = v['i' - 'a'];
        t = v['i' - 'a'];
        iterable = "nine";
        for (const auto &e: iterable) {
            v[e - 'a'] -= t;
        }
        ans[1] = v['o' - 'a'];
        t = v['o' - 'a'];
        iterable = "one";
        for (const auto &e: iterable) {
            v[e - 'a'] -= t;
        }

        for (int i = 0; i != ans.size(); ++i) {
            answer += string(ans[i], (i) + '0');
        }
        return answer;
    }
};
/*
class Solution {
public:
    string originalDigits(string s) {
        vector<int> v(26, 0);
        for (const auto &e: s) {
            ++v[e - 'a'];
        }
        string result;
        result += string(v[25], '0');
        v['o' - 'a'] -= v[25];
        result += string(v['w' - 'a'], '2');
        v['o' - 'a'] -= v['w' - 'a'];
        result += string(v['u' - 'a'], '4');
        v['o' - 'a'] -= v['u' - 'a'];
        v['f' - 'a'] -= v['u' - 'a'];
        result += string(v['f' - 'a'], '5');
        v['i' - 'a'] -= v['f' - 'a'];
        v['v' - 'a'] -= v['f' - 'a'];
        result += string(v['x' - 'a'], '6');
        v['i' - 'a'] -= v['x' - 'a'];
        result += string(v['v' - 'a'], '7');
        result += string(v['g' - 'a'], '8');
        v['i' - 'a'] -= v['g' - 'a'];
        result += string(v['i' - 'a'], '9');
        v['h' - 'a'] -= v['g' - 'a'];
        result += string(v['h' - 'a'], '3');
        result += string(v['o' - 'a'], '1');
        sort(result.begin(), result.end());
        return result;
    }
};
*/
/*
class Solution {
public:
    string originalDigits(string s) {
        vector<int> v(26, 0);
        for (const auto &e: s) {
            ++v[e - 'a'];
        }
        v['o' - 'a'] -= v['z' - 'a'];
        v['o' - 'a'] -= v['w' - 'a'];
        string third;
        third += string(v['u' - 'a'], '4');
        v['o' - 'a'] -= v['u' - 'a'];
        v['f' - 'a'] -= v['u' - 'a'];
        third += string(v['f' - 'a'], '5');
        v['i' - 'a'] -= v['f' - 'a'];
        v['v' - 'a'] -= v['f' - 'a'];
        third += string(v['x' - 'a'], '6');
        v['i' - 'a'] -= v['x' - 'a'];
        third += string(v['v' - 'a'], '7');
        third += string(v['g' - 'a'], '8');
        v['i' - 'a'] -= v['g' - 'a'];
        third += string(v['i' - 'a'], '9');
        v['h' - 'a'] -= v['g' - 'a'];
        third = string(v['z' - 'a'], '0') + string(v['o' - 'a'], '1') + string(v['w' - 'a'], '2') + string(v['h' - 'a'], '3') +  third;
        return third;
    }
};
*/

int main() {


  return 0;
}
