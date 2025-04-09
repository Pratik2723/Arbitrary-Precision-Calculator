/*******************************************************************************************************************************************************************
*Title			: Subtraction
*Description		: This function performs subtraction of two given large numbers and store the result in the resultant list.
*Prototype		: int subtraction(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR);
*Input Parameters	: head1: Pointer to the first node of the first double linked list.
			: tail1: Pointer to the last node of the first double linked list.
			: head2: Pointer to the first node of the second double linked list.
			: tail2: Pointer to the last node of the second double linked list.
			: headR: Pointer to the first node of the resultant double linked list.
*Output			: Status (SUCCESS / FAILURE)
*******************************************************************************************************************************************************************/
#include "apc.h"

int subtraction(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, int sign1, int sign2)
{
    int borrow = 0, carry = 0;

    if (sign1 == sign2)
    {
        int comp = compare_lists(*head1, *head2);
        if (comp >= 0) // head1 >= head2
        {
            subtract_lists(*tail1, *tail2, headR, &borrow);
            return sign1;
        }
        else // head2 > head1
        {
            subtract_lists(*tail2, *tail1, headR, &borrow);
            return -sign1; // Flip the sign
        }
    }
    else
    {
        add_lists(*tail1, *tail2, headR, &carry);
        return sign1; // Return the sign of the first operand
    }
}
