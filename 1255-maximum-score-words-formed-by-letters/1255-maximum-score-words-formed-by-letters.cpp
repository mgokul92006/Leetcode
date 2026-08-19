class Solution {
public:
    int calculate(vector<string>& words, map<char, int> &le, vector<int>& score,
                  int i) {
        int sc = 0;
        for (int j = 0; j < words[i].size(); j++) {
            if(le[words[i][j]]>0){
            sc = sc + score[words[i][j] - 97];
            le[words[i][j]]--;
            }
            else return 0;
        }
        return sc;
    }
    int scores(vector<string>& words, map<char, int> le, vector<int>& score,
               int i) {
        if (i >= words.size())
            return 0;
        map<char,int>temp=le;
        int wordScore=calculate(words,temp,score,i);
        int take=0;
        if(wordScore!=0){
         take = wordScore + scores(words, temp, score, i + 1);
        }
        int nottake = scores(words, le, score, i + 1);
        return max(take, nottake);
    }
    int maxScoreWords(vector<string>& words, vector<char>& letters,
                      vector<int>& score) {
        map<char, int> le;
        for (auto i : letters)
            le[i]++;
        int a = scores(words, le, score, 0);
        return a;
    }
};