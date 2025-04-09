/**************************************************************************************************************************************************************
*Title		: main function(Driver function)
*Description	: This function is used as the driver function for the all the functions
***************************************************************************************************************************************************************/
/* 
Name - Pratik Jadhav
Date - 29 / 12 / 2024
Roll no. - 24021_332
Batch - 24021G
Description - Arbitrary-precision arithmetic, also called big-num arithmetic, multiple precision arithmetic, or sometimes infinite-precision arithmetic, indicates that calculations are performed on numbers whose digits of precision are limited only by the available memory of the host system. This contrasts with the faster fixed-precision arithmetic found in most arithmetic logic unit (ALU) hardware, which typically offers between 8 and 64 bits of precision.
*/


#include "apc.h"

int main(int argc, char *argv[])
{
    // // Printing the argument count and the arguments
    // printf("Argument count: %d\n", argc);
    // for (int i = 0; i < argc; i++) {
    //     printf("argv[%d]: %s\n", i, argv[i]);
    // }

    if (argc != 4)
    {
        printf("Please give the input like: %s num1 operator(For multiplication pass the operator inside the single quote) num2\n", argv[0]);
        return FAILURE;
    }

    Dlist *head1 = NULL, *tail1 = NULL;
    Dlist *head2 = NULL, *tail2 = NULL;
    Dlist *headR = NULL, *tailR = NULL;
    
    char operator;
    int sign1 = 1, sign2 = 1;

    // Parsing the first number and sign
    if (argv[1][0] == '-')  // Here why we are collecting like this means, we are taking operand 1 as the first element and then the operand 1's first element we are collecting
    {
        sign1 = -1;
        parse_number(&head1, &tail1, argv[1] + 1); // Skip the '-' sign
    }
    else
    {
        parse_number(&head1, &tail1, argv[1]);      // Parsing the number to convert them to integer and store them 
    }

    // Parsing the operator
    operator = argv[2][0];

    // Parse second number and sign
    if (argv[3][0] == '-')
    {
        sign2 = -1;
        parse_number(&head2, &tail2, argv[3] + 1); // Skip the '-' sign
    }
    else
    {
        parse_number(&head2, &tail2, argv[3]);      // Parsing the number to convert them to integer and store them 
    }
    
    int result_sign;
    switch (operator)
    {
        case '+':
            result_sign = addition(&head1, &tail1, &head2, &tail2, &headR, sign1, sign2);
            printf("Addition is : ");
            break;
        case '-':
            result_sign = subtraction(&head1, &tail1, &head2, &tail2, &headR, sign1, sign2);
            printf("Substraction is : ");
            break;
        case '*':
            result_sign = multiplication(&head1, &tail1, &head2, &tail2, &headR, sign1, sign2);
            printf("Multiplication is : ");
            break;
        case '/':
            result_sign = division(&head1, &tail1, &head2, &tail2, &headR, sign1, sign2);
            printf("Division is : ");
            break;
        default:
            printf("Invalid Input: Try again...\n");
            return FAILURE;
    }

    // Print the result
    if(operator == '/'){
       // printf("Quotient: ");
        print(headR, result_sign);

    }
    else{
        print_result(headR, result_sign);
    }

    return SUCCESS;
}

void parse_number(Dlist** head, Dlist** tail, const char* str)
{
    for (int i = 0; str[i] != '\0'; i++)
    {
        insert_at_end(head, tail, str[i] - '0'); // Converting char to integer and then inserting
    }
}

void print_result(Dlist* head, int sign)
{
    // Reverse the list before printing
    Dlist* prev = NULL;
    Dlist* current = head;
    Dlist* next = NULL;
    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;

    // Skip leading zeros
    while (head && head->data == 0)
    {
        head = head->next;
    }

    // case where result is zero
    if (!head)
    {
        printf("0\n");
        return;
    }

    if (sign == -1)
    {
        printf("-");
    }

    // Print the result
    Dlist* curr = head;
    while (curr)
    {
        printf("%d", curr->data);
        curr = curr->next;
    }
    printf("\n");
}

void print(Dlist *head, int sign){
    while(head){
        printf("%d",head->data);
        head = head->next;
    }
    printf("\n");
}