#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <algorithm>
using namespace std;

int main() {
	int n = 0;
	cin >> n;
	vector<string> v;
	string s;
	while (cin >> s) {
		v.push_back(s);
	}

	for (decltype(v.size()) i = 0; i != v.size(); ++i) {
		unordered_set<char> us;
		string tmp = v[i];
		int cnt = 0;
		auto first = (tolower(v[i][0]) - 'a' + 1);
		while (cnt != 3) {
			auto pos = tmp.find(",");
			string str(tmp.cbegin(), tmp.cbegin() + pos);
			for (const auto &e: str) {
				us.insert(e);
			}
			tmp.erase(tmp.begin(), tmp.begin() + pos + 1);
			++cnt;
		}
		auto pos = tmp.find(",");
		string x(tmp.cbegin(), tmp.cbegin() + pos);
		tmp.erase(tmp.begin(), tmp.begin() + pos + 1);

		pos = tmp.find(",");
		string y(tmp.cbegin(), tmp.cbegin() + pos);
		tmp.erase(tmp.begin(), tmp.begin() + pos + 1);
		string z(tmp.cbegin(), tmp.cend());

		int sum = 0;

		int xx = stoi(x);
		int yy = stoi(y);
		int zz = stoi(z);
		if ((zz < 1950) || (zz > 2021)) continue;
		if ((yy > 12) || (yy < 1)) continue;
		if ((xx > 31) || (xx < 1)) continue;

		while (xx) {
			int tmp = xx % 10;
			sum += tmp;
			xx /= 10;
		}

		while (yy) {
			int tmp = yy % 10;
			sum += tmp;
			yy /= 10;
		}

		int result = us.size() + sum * 64 + first * 256;
		string res;
		while (result) {
			int tmp = result % 16;
			if (tmp >= 10) {
				if (tmp == 10)
					res += 'A';
				if (tmp == 11)
					res += 'B';
				if (tmp == 12)
					res += 'C';
				if (tmp == 13)
					res += 'D';
				if (tmp == 14)
					res += 'E';
				if (tmp == 15)
					res += 'F';
			} else
				res += to_string(tmp);
			result /= 16;
		}

		reverse(res.begin(), res.end());
		string q = res;
		if (q.size() < 3) {
			while (q.size() != 3)
				q.insert(q.begin(), '0');
		} else
			q = string(res.cend() - 3 , res.cend());
		cout << q << " ";
	}

	return 0;
}
