#include<stdio.h>
#include<stdlib.h>
#include"doubly_linked_list.h"

int main(int argc, char *argv[]){

	PNODE HEAD = NULL;

	list_add_sorted(&HEAD, 16);
	list_add_sorted(&HEAD, 11);
	list_add_sorted(&HEAD, 12);
	list_add_sorted(&HEAD, 31);
	list_add_sorted(&HEAD, 14);
	list_add_sorted(&HEAD, 51);
	list_add_sorted(&HEAD, 77);
	print(HEAD);

	list_del_by_key(&HEAD, 11);
	list_del_by_key(&HEAD, 31);
	list_del_by_key(&HEAD, 77);
	list_del_by_key(&HEAD, 12);
	list_del_by_key(&HEAD, 16);
	list_del_by_key(&HEAD, 51);
	list_del_by_key(&HEAD, 14);
	print(HEAD);

	list_add_at_end(&HEAD, 100);
	list_add_at_end(&HEAD, 200);
	print(HEAD);

	list_delete(&HEAD);
	print(HEAD);
	return 0;
}
