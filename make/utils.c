#include "apc.h"


Dlist* create_node(data_t data)
{
    Dlist* new_node = (Dlist*)malloc(sizeof(Dlist));
    if (!new_node)
    {
        return NULL;
    }
    new_node->data = data;
    new_node->prev = new_node->next = NULL;
    return new_node;
}

void insert_at_end(Dlist** head, Dlist** tail, data_t data)
{
    Dlist* new_node = create_node(data);
    if (!new_node)
    {
        printf("FAILED MEMORY ALLOCATION ..!!\n");
        return;
    }
    if (!*head)
    {
        *head = *tail = new_node;
    }
    else
    {
        (*tail)->next = new_node;
        new_node->prev = *tail;
        *tail = new_node;
    }
}


void subtract_lists(Dlist* head1, Dlist* head2, Dlist** headR, int* borrow)
{
    Dlist* tailR = NULL; // Tail for the result list

    while (head1 || head2)
    {
        int diff = (head1 ? head1->data : 0) - (head2 ? head2->data : 0) - *borrow;
        if (diff < 0)
        {
            diff += 10; // Borrow for next digit
            *borrow = 1;
        }
        else
        {
            *borrow = 0;
        }
        if (head1)
        {
            head1 = head1->prev;
        }
        if (head2)
        {
            head2 = head2->prev;
        }
        insert_at_end(headR, &tailR, diff);
    }
}


void add_lists(Dlist* head1, Dlist* head2, Dlist** headR, int* carry)
{
    Dlist* tailR = NULL; // Tail for the result list

    while (head1 || head2 || *carry)
    {
        int sum = *carry;
        if (head1)
        {
            sum += head1->data;
            head1 = head1->prev;
        }
        if (head2)
        {
            sum += head2->data;
            head2 = head2->prev;
        }
        *carry = sum / 10; // Carry for next digit
        int digit = sum % 10;
        insert_at_end(headR, &tailR, digit);
    }
}


int compare_lists(Dlist* head1, Dlist* head2)
{
    // Getting lengths of both lists
    int len1 = 0, len2 = 0;
    Dlist* temp1 = head1;
    Dlist* temp2 = head2;

    while (temp1)
    {
        len1++;
        temp1 = temp1->next;
    }

    while (temp2)
    {
        len2++;
        temp2 = temp2->next;
    }

    // Compare lengths first
    if (len1 > len2) return 1;
    if (len1 < len2) return -1;

    // If lengths are equal, compare digit by digit
    while (head1 && head2)
    {
        if (head1->data > head2->data)
        {
            return 1;
        }
        else if (head1->data < head2->data)
        {
            return -1;
        }
        head1 = head1->next;
        head2 = head2->next;
    }

    // If both are equal
    return 0;
}




void insert_at_beginning(Dlist **head, Dlist **tail, int data)
{
    Dlist *new_node = (Dlist *)malloc(sizeof(Dlist));
    if (!new_node)
    {
        printf("Memory allocation failed\n");
        return;
    }
    new_node->data = data;
    new_node->next = *head;
    new_node->prev = NULL;

    if (*head)
    {
        (*head)->prev = new_node;
    }
    else
    {
        *tail = new_node;
    }
    *head = new_node;
}


int convert_to_integer(Dlist *head)
{
    int result = 0;
    while (head)
    {
        result = result * 10 + head->data;
        head = head->next;
    }
    return result;
}

void convert_to_linked_list(int number, Dlist **head, Dlist **tail)
{
    if (number == 0)
    {
        insert_at_end(head, tail, 0);
        return;
    }

    // Insert digits at beginning to construct the number correctly
    while (number > 0)
    {
        insert_at_beginning(head, tail, number % 10);
        number /= 10;
    }
}
