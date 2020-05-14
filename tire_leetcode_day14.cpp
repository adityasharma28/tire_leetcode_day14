struct TrieNode {
    bool isEnd;
    TrieNode *child[26];
    TrieNode(){
        isEnd = false;
        for(int i=0;i<26;++i) 
		child[i] = NULL;
    }
};
class Trie {
public:
    /** Initialize your data structure here. */
    TrieNode *root = new TrieNode();
    
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode *curr = root;
        for(int i=0;i<word.size();++i){
            int ch = word[i]-'a';
            if(curr->child[ch]==NULL){
                curr->child[ch] = new TrieNode();
            }
            curr = curr->child[ch];
        }
        curr->isEnd = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode *curr = root;
        for(int i=0;i<word.size();++i){
            int ch = word[i]-'a';
            if(curr->child[ch]==NULL){
                return false;
            }else curr = curr->child[ch];
        }
        return ((curr->isEnd==true)?true:false);
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode *curr = root;
        for(int i=0;i<prefix.size();++i){
            int ch = prefix[i]-'a';
            if(curr->child[ch]==NULL){
                return false;
            }else curr = curr->child[ch];
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
