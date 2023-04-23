//Write a program to print out the elements of a singly linked list
#include<stdio.h>
#include<iostream>
#include<string.h>

//Type declarations for linked lists
typedef struct node* node_ptr;

struct node {
	char element[10];
	node_ptr next;
};
typedef node_ptr LIST;
typedef node_ptr position;

//Function to test whether a linked list is empty
int is_empty(LIST L) {
	return(L->next == NULL);
}

//Function to test whether current position is the last in a linked list
int is_last(position p, LIST L) {
	return (p->next == NULL);
}

//Find routine Return position of x in L; NULL if not found
position find(char* x, LIST L) {
	position p;
	p = L->next;
	while ((p != NULL) && (!strcmp(p->element, x))) p = p->next;
	return p;
}

//Find previous--the find toutine for use with delete
//use a header. If element is not found, then next field of returned value is NULL
position find_previous(char* x, LIST L) {
	position p;
	p = L->next;
	while ((p->next != NULL) && (!strcmp(p->next->element, x))) p = p->next;
	return p;
}

//Deletion routine for linked lists
/*Delete form a list. Cell pointed to by p->next is wiped out.
Assume yhat the position is legal
Assume use of a header node*/
void delete_x(char* x, LIST L) {
	position p, tmp_cell;
	p = find_previous(x, L);
	if (p->next != NULL) {//Implicit assumption of header use
		//x is found: delete it
		tmp_cell = p->next;
		p->next = tmp_cell->next;//bypass the cell to be deleted
		delete tmp_cell;
	}
}

//Insertion routine for linked lists
//Insert (after legeal position p)
// Header implementation assumed
void insert(char* x, LIST L, position p) {
	position tmp_cell = new node;
	if (tmp_cell == NULL) perror("Out of space!!!");
	else {
		strcpy_s(tmp_cell->element, x);
		tmp_cell->next = p->next;
		p->next = tmp_cell;
	}
}

LIST create_list() {
	node_ptr L = new node;
	L->next = new node;
	L->next = NULL;
	return L;
}

void print_list(LIST L) {
	position p = L->next;
	while (p) {
		std::cout << p->element << std::endl;
		p = p->next;
	}
}

int main() {
	LIST L = create_list();
	if (L == NULL) perror("Assignment fails!!!");
	std::cout << "Please input 3 elements:" << std::endl;
	for (int i = 0; i < 3; i++) {
		char element[10] = "";
		std::cin >> element;
		insert(element, L, L);
	}
	print_list(L);

	return 0;
}