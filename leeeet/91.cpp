class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        if (n == 0 || s[0] == '0') return 0;
        int p2 = 1;
        int p1 = 1;
        for(int i = 1; i< n; i++) {
            int curr = 0;
        if (s[i] != '0') curr += p1;
        int two = (s[i - 1] - '0') * 10 + (s[i] - '0');
        if (two >= 10 && two <= 26) curr += p2;
        p2 = p1;
        p1 = curr;
        }
        return p1;
        
    }
};