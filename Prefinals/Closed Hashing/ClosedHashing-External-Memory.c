#include <stdio.h>
#include <stdlib.h>

#define SIZE 10
#define EMPTY -2
#define DELETED -1

typedef char List;
typedef List Dictionary[SIZE];

typedef enum { FALSE,  TRUE }Boolean;

void initDictionary(Dictionary D);
void displayDictionary(Dictionary D);

int hashFunc(char elem);
void insert(Dictionary D, char elem);
void populateDic(Dictionary D);
void deleteElem(Dictionary D, char elem);

Boolean isMember(Dictionary D, char elem);

void read();
void write(Dictionary D);

int main() {
	Dictionary D;
	
	/*Task 1*/
	initDictionary(D);
	displayDictionary(D);
	
	/*Task 2*/
	populateDic(D);
	displayDictionary(D);
	
	/*Task 3*/
	deleteElem(D, 'A');
	deleteElem(D, 'B');
	displayDictionary(D);
	
	/*Task 4*/
	printf("%d ", isMember(D, 'A')); // should display 0
	printf("%d ", isMember(D, 'B')); // should display 1
	printf("%d ", isMember(D, 'E')); // should display 1
	printf("%d ", isMember(D, 'J')); // should display 0
	printf("%d ", isMember(D, 'C')); // should display 1
	printf("%d \n\n", isMember(D, 'K')); // should display 1
	
	/* Task 5 */
	write(D);
	read();
	
	return 0;
}

// initializes the closed hashing dictionary to -2 as empty
void initDictionary(Dictionary D) {
	int i;
	for( i = 0; i < SIZE; i++) {
		D[i] = EMPTY; // -2 empty, -1 deleted
	}
}

// displays the elements of the dictionary
void displayDictionary(Dictionary D) {
	int i;
	for( i = 0; i < SIZE; i++) {
		printf("%d-->", i);
		if(D[i] == EMPTY) {
			printf(" Empty\n");
		} else if(D[i] == DELETED) {
			printf(" Deleted\n");
		}else {
			printf(" %c\n", D[i]);
		}
	}
	printf("\n");
}

// returns the key value of the element to be inserted/deleted
int hashFunc(char elem) {
	return elem % SIZE;
}

// inserts the element based on the key value at a location based on conditions
void insert(Dictionary D, char elem) {
	char key; int ctr = 0;
	for (key = hashFunc(elem); D[key] != EMPTY && D[key] != DELETED && ctr < SIZE; key = (key + 1) % SIZE, ctr++) {}
	if(ctr < SIZE) {
		D[key] = elem;
	} else {
		printf("Dictionary is Full\n");
	}
}

// simply calls insert multiple times
void populateDic(Dictionary D) {
	insert(D, 'A');
	insert(D, 'B');
	insert(D, 'C');
	insert(D, 'D');
	insert(D, 'E');
	insert(D, 'F');
	insert(D, 'K');
	insert(D, 'L');
}

// deletes the element based on the key value on certain conditions
void deleteElem(Dictionary D, char elem) {
	char key; int ctr = 0;
	for (key = hashFunc(elem); D[key] != EMPTY && D[key] != elem && ctr < SIZE; key = (key + 1) % SIZE, ctr++){}
	if(ctr < SIZE) {
		D[key] = DELETED;
	} else {
		printf("Dictionary is Empty\n");
	}
}

// searches for a specific element based on key value on certain conditions
Boolean isMember(Dictionary D, char elem) {
	char key; int ctr = 0;
	for (key = hashFunc(elem); D[key] != EMPTY && D[key] != elem && ctr < SIZE; key = (key + 1) % SIZE, ctr++){}
	return (D[key] != EMPTY || ctr == SIZE) ? TRUE: FALSE;
}

void read() {
	FILE *fp;
	int ctr, i;
	char filename[20] = "Dictionary.dat";
	
	Dictionary D;
	initDictionary(D);
	
	if( (fp = fopen(filename,"r")) != NULL ){
		fseek(fp, 0, SEEK_END);
		ctr = ftell(fp)/(sizeof(Dictionary));
		rewind(fp);
		
		// if using character, it will terminate at EMPTY/DELETE
		for(i = 0; i < SIZE;  i++) {
			fread(&D[i], sizeof(int), 1, fp);
			if( D[i] == -2) {
				printf("%d--> Empty\n", i);
			} else if (D[i] == -1) {
				printf("%d--> Deleted\n", i);
			} else {
				printf("%d--> %c\n", i, D[i]);
			}
		}
		fclose(fp);
	} else {
		printf("File is empty\n");
	}
}

void write(Dictionary D) {
	FILE *fp;
	int ctr, i;
	char filename[20] = "Dictionary.dat";
		
	if( (fp = fopen(filename,"wb")) != NULL ){
		for( i = 0; i < SIZE; i++) {
			fwrite(&D[i], sizeof(int), 1, fp);
		}
		
		fclose(fp);
		
		printf("File has been created!\n");
	} 
}

