class Solution {
public:
    bool checkIPv6(const string &s) {
        for (const auto &e: s) {
            if (isalpha(e)) {
                if (us.find(e) == us.cend()) {
                    return false;
                }
            }
        }
        if (s.size() == 0 || s.size() > 4) {
            return false;
        }
        return true;
    }
    bool checkIPv4(const string &s) {
        if ((s.size() == 0 || (s[0] == '0' && s.size() != 1)) || s.size() > 3) {
            return false;
        }
        if (s.find_first_not_of("0123456789") != string::npos) {
            return false;
        }
        if (stoi(s) >= 256) {
            return false;
        }
        return true;
    }

    string validIPAddress(string queryIP) {
        auto prevPos = 0;
        auto pos = queryIP.find(':');
        if (pos != string::npos) {
            auto cnt = count(queryIP.cbegin(), queryIP.cend(), ':');
            if (cnt != 7) {
                return "Neither";
            }
            pos = queryIP.find(':');
            string tmp = {queryIP.cbegin() + prevPos, queryIP.cbegin() + pos};
            if(!checkIPv6(tmp)) {
                return "Neither";
            }
            prevPos = pos + 1;
            ++pos;
            
            pos = queryIP.find(':', pos);
            tmp = {queryIP.cbegin() + prevPos, queryIP.cbegin() + pos};
            if(!checkIPv6(tmp)) {
                return "Neither";
            }
            prevPos = pos + 1;
            ++pos;
            pos = queryIP.find(':', pos);
            tmp = {queryIP.cbegin() + prevPos, queryIP.cbegin() + pos};
            if(!checkIPv6(tmp)) {
                return "Neither";
            }
            prevPos = pos + 1;
            ++pos;
            pos = queryIP.find(':', pos);
            tmp = {queryIP.cbegin() + prevPos, queryIP.cbegin() + pos};
            if(!checkIPv6(tmp)) {
                return "Neither";
            }
            prevPos = pos + 1;
            ++pos;
            pos = queryIP.find(':', pos);
            tmp = {queryIP.cbegin() + prevPos, queryIP.cbegin() + pos};
            prevPos = pos + 1;
            if(!checkIPv6(tmp)) {
                return "Neither";
            }
            ++pos;
            pos = queryIP.find(':', pos);
            tmp = {queryIP.cbegin() + prevPos, queryIP.cbegin() + pos};
            prevPos = pos + 1;
            if(!checkIPv6(tmp)) {
                return "Neither";
            }
            ++pos;
            pos = queryIP.find(':', pos);
            tmp = {queryIP.cbegin() + prevPos, queryIP.cbegin() + pos};
            prevPos = pos + 1;
            if(!checkIPv6(tmp)) {
                return "Neither";
            }
            tmp = {queryIP.cbegin() + prevPos, queryIP.cend()};
            if(!checkIPv6(tmp)) {
                return "Neither";
            }
            return "IPv6";
        } else {
            auto cnt = count(queryIP.cbegin(), queryIP.cend(), '.');
            if (cnt != 3) {
                return "Neither";
            }
            pos = queryIP.find('.');
            string tmp = {queryIP.cbegin() + prevPos, queryIP.cbegin() + pos};
            prevPos = pos + 1;
            if (!checkIPv4(tmp)) {
                return "Neither";
            }
            ++pos;
            pos = queryIP.find('.', pos);
            tmp = {queryIP.cbegin() + prevPos, queryIP.cbegin() + pos};
            prevPos = pos + 1;
            if (!checkIPv4(tmp)) {
                return "Neither";
            }
            ++pos;
            pos = queryIP.find('.', pos);
            tmp = {queryIP.cbegin() + prevPos, queryIP.cbegin() + pos};
            prevPos = pos + 1;
            if (!checkIPv4(tmp)) {
                return "Neither";
            }
            tmp = {queryIP.cbegin() + prevPos, queryIP.cend()};
            if (!checkIPv4(tmp)) {
                return "Neither";
            }        
            return "IPv4";        
        }
    }
private:
    unordered_set<char> us{'a','b','c','d','e','f','A','B','C','D','E','F'};
};

int main() {
  
  
  
  return 0;  
}
