class AuthenticationManager {
public:
    AuthenticationManager(int timeToLive) :timeToLiv(timeToLive){

    }
    
    void generate(string tokenId, int currentTime) {
        um[tokenId] = timeToLiv + currentTime;
    }
    
    void renew(string tokenId, int currentTime) {
        auto it = um.find(tokenId);
        if (it == um.cend()) return;
        if (it->second <= currentTime) {
            um.erase(it);
            return;
        }
        um[tokenId] = timeToLiv + currentTime;
    }

    int countUnexpiredTokens(int currentTime) {
        cnt = 0;
        for (const auto &e: um) {     
            if (e.second > currentTime) {
                ++cnt;
            }
        }
        return cnt;
    }
private:
    int cnt = 0;
    unordered_map<string, int> um;
    int timeToLiv = 0;
};

/**
 * Your AuthenticationManager object will be instantiated and called as such:
 * AuthenticationManager* obj = new AuthenticationManager(timeToLive);
 * obj->generate(tokenId,currentTime);
 * obj->renew(tokenId,currentTime);
 * int param_3 = obj->countUnexpiredTokens(currentTime);
 */

int main() {
  
  
  
  
  return 0;  
}
