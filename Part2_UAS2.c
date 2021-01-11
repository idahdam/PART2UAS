/*
	Muhammad Hadi - 1906355623
	Part 2 bagian 2 - Tree
	Saya menangkap sebanyak-banyaknya itu tinggal diganti defined variablenya, pak 
*/
#define MAX_ORANG 1000
#define PANJANG_STRING 1000

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//declare struct
struct treeNode{
	struct treeNode *leftPtr;
	struct treeNode *rightPtr;
	float nilai;
	char nama[PANJANG_STRING];
	
};

typedef struct treeNode TreeNode;
typedef TreeNode *TreeNodePtr;

//declare methods
void insertNode(TreeNodePtr *treePtr, float value, char* string);
void inOrder(TreeNodePtr treePtr);


int i, jumlah;
float nilai[MAX_ORANG], sum;
char string[MAX_ORANG][PANJANG_STRING];

int main(){

	TreeNodePtr rootPtr = NULL;
	
	printf("Program akan menghitung nilai rata-rata max %d siswa\n", MAX_ORANG);
	printf("input berapa jumlah siswa: "), scanf("%d", &jumlah);
	
	//error input
	while(jumlah < 1 || jumlah > MAX_ORANG){
		printf("input di luar range, input kembali jumlah siswa: "), scanf("%d", &jumlah);
	}
	
	printf("Anda memasukkan %d jumlah siswa untuk dihitung nilainya.\n\n", jumlah);
	
	for(i = 0; i<jumlah; i++){
		printf("Masukkan nama untuk siswa ke-%d: ", i+1), scanf("%s", string[i]);
		printf("Untuk nilai siswa ke-%d adalah: ", i+1), scanf("%f", &nilai[i]);
		sum+=nilai[i];
		insertNode(&rootPtr, nilai[i], string[i]);
	}
	
	printf("\n\nMaka urutannya adalah....\n");
	inOrder(rootPtr);
	
	//average
	sum /= jumlah;

	printf("\nRata-ratanya adalah: %.2f", sum);	
	
	return 0;
}

void insertNode(TreeNodePtr *treePtr, float value, char string[]){
	if(*treePtr == NULL){
		*treePtr = malloc(sizeof(TreeNode));
		
		if(*treePtr != NULL){
			(*treePtr)->nilai = value;
			strcpy((*treePtr)->nama, string);
			(*treePtr)->leftPtr = NULL;
			(*treePtr)->rightPtr = NULL;
		}
		else{
			printf("%.2f not inserted. No memory available.\n", value);
		}
	}
	else{
		if(value < (*treePtr)->nilai){
			insertNode( &( ( *treePtr )->leftPtr ), value, string);
		}
		else if(value > (*treePtr)->nilai){
			insertNode( &( ( *treePtr )->rightPtr ), value, string);
		}
		else{
			printf("Ducpliate detected. Duplicate wont be printed...\n");
		}
	}
}

void inOrder(TreeNodePtr treePtr){
	if(treePtr != NULL){
		inOrder(treePtr->leftPtr);
		printf("%s-%.2f\n", treePtr->nama, treePtr->nilai);
		inOrder(treePtr->rightPtr);
	}
}
