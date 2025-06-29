class TrieNode{
    public:
    bool flag;
    TrieNode* children[26];
    public:
    TrieNode(){
        flag=false;
        for(int i=0;i<26;i++){
            children[i]=NULL;
        }
    }
};


class Trie {
      TrieNode* root;
public:
    Trie() {
       root=new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* head=root;
        for(int i=0;i<word.size();i++){
            int index=word[i]-'a';
            if(head->children[index]==NULL){
                head->children[index]=new TrieNode();
            }
            head=head->children[index];
        }
        head->flag=true;
    }
    
    bool search(string word) {
        TrieNode* head=root;
        for(int i=0;i<word.size();i++){
            int index=word[i]-'a';
            if(head->children[index]==NULL){
                return false;
            }
            head=head->children[index];
        }
        if(head->flag==false){
            return false;
        }
        return true;
    }
    
    bool startsWith(string prefix) {
        TrieNode* head=root;
        for(int i=0;i<prefix.size();i++){
            int index=prefix[i]-'a';
            if(head->children[index]==NULL){
                return false;
            }
          head=head->children[index];  
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