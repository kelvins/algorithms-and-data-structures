/*
*	Example of Unordered Dynamic Linked List in C
*	Kelvin Salton do Prado - 2015
*/

#include <stdio.h>
#include <malloc.h>

#define ERROR -1

typedef int KEY_TYPE;

typedef struct node{
	KEY_TYPE key;
	struct node* next;
} RECORD, *POINTER;

POINTER createRecord(KEY_TYPE key){
	POINTER record = (POINTER) malloc( sizeof(POINTER) );
	record->key = key;
	record->next = NULL;
	return record;
}

POINTER insertRecord(KEY_TYPE key, POINTER record){
	if( record == NULL ) 
		return createRecord(key); // If there are no records in the list, create a new one
	while( record->next != NULL )
		record = record->next;
	record->next = createRecord(key);
	return NULL;
}

void showList(POINTER record){
	if( record == NULL ) return;
	printf("%d, ", record->key);
	showList(record->next);
}

POINTER sequentialSearch(KEY_TYPE key, POINTER record){
	while( record != NULL ){
		if( record->key == key )
			return record;
		record = record->next;
	}
	return NULL;
}

bool deleteRecord(KEY_TYPE key, POINTER record){
	POINTER previous;
	while( record != NULL ){
		if( record->key == key ){
			previous->next = record->next;
			free(record);
			return true;
		}
		previous = record;
		record = record->next;
	}
	printf("\nKey %d not found.\n", key);
	return false;	
}

int main(){
	POINTER RECORD = insertRecord(23, RECORD);
	insertRecord(34, RECORD);
	insertRecord(12, RECORD);
	insertRecord(63, RECORD);
	insertRecord(45, RECORD);

	showList(RECORD);

	KEY_TYPE key = 64;
	if( sequentialSearch(key, RECORD) != NULL )
		printf("\nFound key %d\n", key);
	else
		printf("\nKey %d not found\n", key);

	deleteRecord(63, RECORD);
	showList(RECORD);
	
	printf("\n");
	deleteRecord(34, RECORD);
	showList(RECORD);
	return 0;
}
