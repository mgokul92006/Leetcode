class Node{
    public:
    Node* child[26];
    bool isEnd=false;
    Node(){
        for(int i=0;i<26;i++){
            child[i]=NULL;
        }
    }
    bool contains(char c){
        return child[c-'a']!=NULL;
    }
    void put(char c,Node* n){
        child[c-'a']=n;
    }
    Node* get(char c){
        return child[c-'a'];
    }
    bool End(){
        return isEnd=true;
    }
};
class Trie {
private:
    Node* root;
public:
    Trie() {
        root=new Node();
    }
    
    void insert(string word) {
        Node* k=root;
        for(int i=0;i<word.size();i++){
            if(!k->contains(word[i])){
                k->put(word[i],new Node());
            }
            k=k->get(word[i]);
        }
        k->isEnd=true;
    }
    
    bool search(string word) {
        Node* k=root;
        for(int i=0;i<word.size();i++){
            if(!k->contains(word[i]))
                return false;
            k=k->get(word[i]);
        }
        return k->isEnd;
    }
    
    bool startsWith(string prefix) {
        Node* k=root;
        for(int i=0;i<prefix.size();i++){
            if(!k->contains(prefix[i]))
                return false;
            k=k->get(prefix[i]);
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */