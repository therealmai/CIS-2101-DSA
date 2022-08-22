#include <stdio.h>
#include <stdlib.h>
#define SIZE 20

typedef int SET[SIZE];

// Note: Insertion should be done in its proper position to main the sorted state of the array
// Note: Elements are stored in index 1 to SIZE-1. Index 0 stores the actual number of elements.

void display(SET A);
SET* unionSet(SET A, SET B);
SET* intersection(SET A, SET B);
SET* difference(SET A, SET B);

//EXERCISE: Try solving beforehand before viewing the answer
int isSubset(SET A, SET B); /* Returns 1 if A is a subset of B and 0 otherwise */

//Answer key for the exercise: Found at line 200
int isSubsetAns(SET A, SET B);
void checkTestCases();

int main() {
	
	/*Custom test case: Feel free to modify the set information here. */
	SET A = {2, 1,4};
	SET B = {3, 1,2,3};
	
	display(A);
	display(B);

	printf("\n");	
	
	SET* U = unionSet(A,B);
	SET* I = intersection(A,B);
	SET* D = difference(A,B);
	
	display(*U);
	display(*I);
	display(*D);
	printf("\nYour result: %d", isSubset(A,B));
	printf("\nCorrect result: %d", isSubsetAns(A,B));
	
	checkTestCases();
	
	return 0;
}

int isSubset(SET A, SET B){ /* Returns 1 if A is a subset of B and 0 otherwise */
	// Write your code here!




	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
}

void display(SET A){
	int x, size=A[0];
	printf("{ ");
	for(x=1; x<=size; x++){
		printf("%d ",A[x]);
	}
	printf("}\n");
}

SET* unionSet(SET A, SET B){
	int sizeA=A[0], sizeB=B[0], x=1, y=1, count=0;
	SET* C = (SET*)calloc(1,sizeof(SET));
	if(C != NULL){

		for(; x<=sizeA && y<=sizeB;){
			if(A[x]<B[y]){
				(*C)[++count] = A[x++];
			} else if (A[x]>B[y]){
				(*C)[++count] = B[y++];
			} else {
				(*C)[++count] = A[x++];
				y++;
			}
		}

		if(x<=sizeA){
			for(; x<=sizeA; x++){
				 (*C)[++count] = A[x];
			}
		} else if (y<=sizeB){
			for(; y<=sizeB; y++){
				 (*C)[++count] = B[y];
			}
		}

	}
	(*C)[0] = count;
	return C;
}

SET* intersection(SET A, SET B){
	int sizeA=A[0], sizeB=B[0], x=1, y=1, count=0;
	SET* C = (SET*)calloc(1,sizeof(SET));
	if(C != NULL){

		for(; x<=sizeA && y<=sizeB;){
			if(A[x]<B[y]){
				x++;
			} else if (A[x]>B[y]){
				y++;
			} else {
				(*C)[++count] = A[x++];
				y++;
			}
		}

	}
	(*C)[0] = count;
	return C;
}

SET* difference(SET A, SET B){
	int sizeA=A[0], sizeB=B[0], x=1, y=1, count=0;
	SET* C = (SET*)calloc(1,sizeof(SET));
	if(C != NULL){

		for(; x<=sizeA && y<=sizeB;){
			if(A[x]<B[y]){
				(*C)[++count] = A[x++];
			} else if (A[x]>B[y]){
				y++;
			} else {
				x++;
				y++;
			}
		}

		if(x<=sizeA){
			for(; x<=sizeA; x++){
				 (*C)[++count] = A[x];
			}
		}

	}
	(*C)[0] = count;
	return C;
}





































int isSubsetAns(SET A, SET B){
	int sizeA=A[0], sizeB=B[0], x=1, y=1;
	int isSub=0;
	
	if(sizeA <= sizeB){
		isSub=1;
	}
	
	for(; x<=sizeA && isSub==1; x++){
		for(; y<=sizeB && A[x] > B[y]; y++){} //Alternate: for(; y<=sizeB && A[x] != B[y]; y++){}
		if(y>sizeB || A[x] != B[y]){          //Alternate: if(y>sizeB){
			isSub=0;
		}
	}
	
	return isSub;
}

void checkTestCases(){
	printf("\n");
	SET A = {4,2,3,4,5};
	SET B = {6,1,2,3,4,5,6};
	printf("\nTest case 1:  %s",(isSubset(A,B) == isSubsetAns(A,B)) ? "Success" : "Failed");
	
	SET C = {3,5,7,9};
	SET D = {2,5,7};
	printf("\nTest case 2:  %s",(isSubset(C,D) == isSubsetAns(C,D)) ? "Success" : "Failed");
	
	SET E = {1,1};
	SET F = {1,2};
	printf("\nTest case 3:  %s",(isSubset(E,F) == isSubsetAns(E,F)) ? "Success" : "Failed");
	
	SET G = {1,2};
	SET H = {1,1};
	printf("\nTest case 4:  %s",(isSubset(G,H) == isSubsetAns(G,H)) ? "Success" : "Failed");
	
	SET I = {3,1,2,3};
	SET J = {3,1,2,3};
	printf("\nTest case 5:  %s",(isSubset(I,J) == isSubsetAns(I,J)) ? "Success" : "Failed");
	
	SET K = {0};
	SET L = {0};
	printf("\nTest case 6:  %s",(isSubset(K,L) == isSubsetAns(K,L)) ? "Success" : "Failed");
	
	SET M = {0};
	SET N = {3,1,2,3};
	printf("\nTest case 7:  %s",(isSubset(M,N) == isSubsetAns(M,N)) ? "Success" : "Failed");
	
	SET O = {3,1,2,3};
	SET P = {0};
	printf("\nTest case 8:  %s",(isSubset(O,P) == isSubsetAns(O,P)) ? "Success" : "Failed");
	
	SET Q = {4,8,12,16,20};
	SET R = {8,3,4,7,8,10,12,14,16};
	printf("\nTest case 9:  %s",(isSubset(Q,R) == isSubsetAns(Q,R)) ? "Success" : "Failed");
	
	SET S = {5,10,20,30,40,50};
	SET T = {8,5,10,15,20,30,40,70};
	printf("\nTest case 10: %s\n",(isSubset(S,T) == isSubsetAns(S,T)) ? "Success" : "Failed");
}

