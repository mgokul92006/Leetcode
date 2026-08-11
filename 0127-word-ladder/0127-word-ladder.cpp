class Solution {
public:
    int path(set<string>& s, string beginWord, string endWord) {
        queue<tuple<int, string>> q;
        q.push({0, beginWord});
        map<string,int>mp;
        mp[beginWord]=0;
        while(!q.empty()){
            auto [st,word]=q.front();
            q.pop();
            if(word==endWord)
            return st+1;
            for(int i=0;i<word.size();i++){
                string k=word;
                for(int j=0;j<26;j++){
                    k[i]=j+97;
                    if(s.find(k)!=s.end() && mp[k]==0){
                        q.push({st+1,k});
                        mp[k]=1;
                    }
                }
            }
        }
        return 0;
    }
    int ladderLength(string beginWord, string endWord,
                     vector<string>& wordList) {
        set<string> s;
        for (auto i : wordList)
            s.insert(i);
        return path(s, beginWord, endWord);
    }
};