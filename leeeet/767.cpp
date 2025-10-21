class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char, int> freq;
        for(char c : s) freq[c]++;
        priority_queue<pair<int, char>> pq;
        for(auto &p : freq) pq.push({p.second, p.first});
        string result = "";
        while (pq.size() > 1) {
            auto [count1, char1] = pq.top();
            pq.pop();
            auto [count2, char2] = pq.top();
            pq.pop();
            result += char1;
            result += char2;
            if (--count1 > 0) pq.push({count1, char1});
             if (--count2 > 0) pq.push({count2, char2});
        }
        if (!pq.empty()){
            auto [count, ch] = pq.top();
            if(count > 1) return "";
            result += ch;
        }
        return result;
    }
};