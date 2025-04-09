/* 
Name - Harshvardhan Patil
Date - 29 / 12 / 2024
Roll no. - 24021_160
Batch - 24021G
Description - Arbitrary-precision arithmetic, also called big-num arithmetic, multiple precision arithmetic, or sometimes infinite-precision arithmetic, indicates that calculations are performed on numbers whose digits of precision are limited only by the available memory of the host system. This contrasts with the faster fixed-precision arithmetic found in most arithmetic logic unit (ALU) hardware, which typically offers between 8 and 64 bits of precision.
*/


#ifndef APC_H
#define APC_H
#define SUCCESS 0
#define FAILURE -1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef int data_t;
typedef struct node
{
	struct node *prev;
	data_t data;
	struct node *next;
}Dlist;

/* prototypes */

int addition(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, int sign1, int sign2);

int subtraction(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, int sign1, int sign2);

int multiplication(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, int sign1, int sign2);

int division(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headQ, int sign1, int sign2);



Dlist* create_node(data_t data);
void subtract_lists(Dlist* head1, Dlist* head2, Dlist** headR, int* borrow);
void add_lists(Dlist* head1, Dlist* head2, Dlist** headR, int* carry);
int compare_lists(Dlist* head1, Dlist* head2);
void insert_at_end(Dlist** head, Dlist** tail, data_t data);


void parse_number(Dlist** head, Dlist** tail, const char* str);
void print_result(Dlist* head, int sign);
void print(Dlist *head, int sign);


void insert_at_beginning(Dlist **head, Dlist **tail, int data);
int convert_to_integer(Dlist *head);
void printresult(Dlist *head, int sign);
void convert_to_linked_list(int number, Dlist **head, Dlist **tail);

#endif
