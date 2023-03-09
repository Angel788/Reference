struct trie{
    bool isFinal;
    trie *children[26];
    trie(){
        isFinal=false;
        for(int i=0;i<26;i++)children[i]=nullptr;
    }
};

void inserString(string str,trie *root){
    trie *aux=root;
    for(int i=0;i<str.size();i++){
        int index=str[i]-'a';
        if(aux->children[index]==nullptr){
            aux->children[index]=new trie();
        }
        aux=aux->children[index];
    }
    aux->isFinal=true;
}
bool existInTrie(string str,trie *root){
    trie *aux=root;
    for(int i=0;i<str.size();i++){
        int index=str[i]-'a';
        if(aux->children[index]==nullptr) return false;
        aux=aux->children[index];
    }
    return aux->isFinal;
}