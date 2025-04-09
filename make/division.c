/*******************************************************************************************************************************************************************
*Title			: Division
*Description		: This function performs Division of two given large numbers and store the result in the resultant list.
*Prototype		: int division(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR);
*Input Parameters	: head1: Pointer to the first node of the first double linked list.
			: tail1: Pointer to the last node of the first double linked list.
			: head2: Pointer to the first node of the second double linked list.
			: tail2: Pointer to the last node of the second double linked list.
			: headR: Pointer to the first node of the resultant double linked list.
*Output			: Status (SUCCESS / FAILURE)
*******************************************************************************************************************************************************************/


#include "apc.h"

int division(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headQ, int sign1, int sign2)
{
    int result_sign = (sign1 == sign2) ? 1 : -1;

    if (*head2 == NULL || (*head2)->data == 0)
    {
        printf("Division by zero is not allowed.\n");
        exit(0);
    }

    // Convert linked lists to integers
    int dividend = convert_to_integer(*head1);
    int divisor = convert_to_integer(*head2);

    // Perform integer division
    int quotient = dividend / divisor;
    int remainder = dividend % divisor;

    // Convert quotient to linked list
    convert_to_linked_list(quotient, headQ, tail1); // Using tail1 to avoid declaring an extra variable

    // Handle the sign of the quotient
    if (result_sign == -1)
    {
        (*headQ)->data *= -1;
    }

    return result_sign;
}
