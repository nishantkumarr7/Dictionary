#include<bits/stdc++.h>
using namespace std;

class TrieNode{
	
	public:
		char data;
		TrieNode **children;
		bool isTerminal;
		string matlab;
		
		TrieNode(char data){
			
			this->data=data;
			children = new TrieNode*[26];
			
			for(int i=0;i<26;i++){
				children[i]=NULL;
			}
			isTerminal=false;	
			matlab="NoMeaningFound";
		}
};

class Trie{
	
	TrieNode *root;
	public :
	int count;
  
	Trie() {
		this->count = 0;
		root = new TrieNode('\0');
	}
		
		bool searchWord(TrieNode* root,string word){
        
        if(word.size()==0){
            return root->isTerminal;
        }
        	int index =word[0]-'a';
			TrieNode *child;
			
			if(root->children[index]!=NULL){
				child=root->children[index];
			}
			else{
				return false;
			}
			
	return searchWord(child,word.substr(1));

    }
    
    bool searchWord(string word){
       bool ans=searchWord(root,word);
       
       if(ans){
       	cout<<root->matlab;
       	return true;
	   }
	   return false;
    }
		
	bool insertWord(TrieNode *root, string word,string meaning) {
		if(word.size() == 0) {
			if (!root->isTerminal) {
				root -> isTerminal = true;
				
				return true;	
			} else {
				return false;
			}
		
		}


		int index = word[0] - 'a';
		TrieNode *child;
		if(root -> children[index] != NULL) {
			child = root -> children[index];
		}
		else {
			child = new TrieNode(word[0]);
			root -> children[index] = child;
		}

		return insertWord(child, word.substr(1),meaning);
	}


	void insertWord(string word,string meaning){
		root->matlab=meaning;
		if (insertWord(root, word,meaning)) {
			this->count++;
		}
	}
}; 

int main(){
	
	Trie t;	
	
	t.insertWord("nishant","morning");
	
	cout<<endl;
	cout<<endl;
	cout<<"Welcome to my own Dictionary";
	cout<<endl;
	cout<<endl;
	cout<<"  ******MENU******"<<endl;
	cout<<endl;
	cout<<"Enter your choice "<<endl;
	cout<<" 1.Search meaning of words of this dictionary"<<endl;
	cout<<" 2.Add new word in the dictionary"<<endl;
	
	cout<<endl;
	
	int choice;
	string str,meaning;
	
	do{
		cout<<"Enter your choice :";
		cin>>choice;
		if(choice ==1){
			cout<<"Enter the word you want to search:"<<endl;
			cin>>str;
			cout<<endl;
			if(t.searchWord(str)){
				cout<<endl;
			}
			else{
				cout<<"  ***word not found***"<<endl;
			}	
		}
		else if(choice==2){
			
				cout<<"Enter the word you want to add:"<<endl;
				cin>>str;
				cout<<"Enter the meaning of the word:";
				cin>>meaning;
				t.insertWord(str,meaning);
				cout<<"word added succesfully";
				
		}

		cout<<endl;
		cout<<"Do you want to exit?"<<endl;
		cout<<"If yes enter -1 ,otherwise enter your choice"<<endl;
	}
	while(choice!=-1);
	return 0;	
}
