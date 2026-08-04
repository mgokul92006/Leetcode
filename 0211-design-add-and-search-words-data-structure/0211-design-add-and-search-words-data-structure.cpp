class Node {
public:
    Node* child[26];
    bool isEnd = false;
    Node() {
        for (int i = 0; i < 26; i++)
            child[i] = NULL;
    }
    bool contains(char c) { return child[c - 'a'] != NULL; }
    void put(char c, Node* n) { child[c - 'a'] = n; }
    Node* get(char c) { return child[c - 'a']; }
};
class WordDictionary {
private:
    Node* root;

public:
    WordDictionary() { root = new Node(); }

    void addWord(string word) {
        Node* k = root;
        for (int i = 0; i < word.size(); i++) {
            if (!k->contains(word[i])) {
                k->put(word[i], new Node());
            }
            k = k->get(word[i]);
        }
        k->isEnd = true;
    }
    bool search1(Node* k, int i, string word) {
        if(i==word.size())
        return k->isEnd;
        if (word[i] == '.') {
            for (int j = 0; j < 26; j++) {
                if (k->child[j] != NULL) {
                    if (search1(k->child[j], i + 1, word)) {
                        return true;
                    }
                }
            }
            return false;
        }
        if (!k->contains(word[i]))
            return false;
        k = k->get(word[i]);
        return search1(k,i+1,word);
    }
    bool search(string word) {
        return search1(root, 0, word);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */