#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10000
typedef struct Node Node;
void makeTree();
void displayList();

int leafs = 0;
int level = 0;
char word[MAX];
int wIndex = 0;

// node of the words list tree 
struct  Node {
	char value;
	int leaf;
	int marked;
	Node* nodes[MAX];
};

// possible letters for the password 
char letters[MAX] ;
 
Node* R;

int main(){
	// initialization
	printf("== LIST GENERATOR == \nPOSSIBLE CHARACTERS : \n");
	scanf("%s",letters);

	R = malloc(sizeof(Node));
	R->value = ' ';
	R->leaf = 0;
	R->marked = 0;
	makeTree(R,letters);
	printf("POSSIBILITIES == %d\n== THE LIST OF WORDS  ==\n",leafs);
	for (int i=0 ; i<leafs ; i++){
		displayList(R);
		//printf("i==%d   avant == %s\n",i,word);
		if( level < strlen(letters) + 1) i--;
		else printf("%s\n",word);
		level =0;
		wIndex = 0;
		strcpy(word,"");
	
		//printf("\n");
	}
	
	return 0;
}

// make a sub-tree from a nonde (racine) and other letters
void makeTree(Node* R , char tab1[MAX]){
	
	char tab2[MAX];
	int index;
	Node* N ;
	for (int i=0; i< strlen(tab1) ;i++){
		N = malloc(sizeof(Node));
		N->value = tab1[i];
		N->marked = 0;
		R->nodes[i] = N;
		index = 0;
		for (int j=0; j< strlen(tab1) ; j++){
			 if (i != j){
				 tab2[index] = tab1[j];
				 index++;
			 }
			
		}
		//printf("%d==%s\n",i,tab2);
		if (strlen(tab2) != 0) {
			N->leaf = 0;
			makeTree(N,tab2);	
		}
		else {N->leaf = 1;leafs++;}

		R->nodes[i+1] = NULL;
		
	}
	
}

void displayList(Node* R){
	
	level++;
	word[wIndex] = R->value;
	wIndex++;
	if (R->leaf != 1){

		int i =0;
		Node* index = R->nodes[i];
		while(index != NULL){
		//printf("yas"); 
			if(index->marked == 1){
				 i++;
				 index = R->nodes[i];
			}
			else break;
		}
		
		if(index == NULL) {
			R->marked = 1;
			return;
		}
		else {
			
			displayList(index);
		}
	}else {
		R->marked = 1;
		return;
	}

}


