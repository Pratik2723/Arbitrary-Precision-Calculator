/*******************************************************************************************************************************************************************
*Title			: Multiplication
*Description		: This function performs Multiplication of two given large numbers and store the result in the resultant list.
*Prototype		: int multiplication(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR);
*Input Parameters	: head1: Pointer to the first node of the first double linked list.
			: tail1: Pointer to the last node of the first double linked list.
			: head2: Pointer to the first node of the second double linked list.
			: tail2: Pointer to the last node of the second double linked list.
			: headR: Pointer to the first node of the resultant double linked list.
*Output			: Status (SUCCESS / FAILURE)
*******************************************************************************************************************************************************************/


#include "apc.h"

int multiplication(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, int sign1, int sign2)
{
    int result_sign = (sign1 == sign2) ? 1 : -1;

    // Initialize result list
    Dlist *result = create_node(0);
    Dlist *tailR_result = result;

    Dlist *ptr1 = *tail1;  // Pointer to the least significant digit of num1
    Dlist *ptr2 = *tail2;  // Pointer to the least significant digit of num2
    int pos1 = 0;          // Position tracker for ptr2 digits

    while (ptr2) // Loop through digits of num2
    {
        Dlist *temp_ptr1 = ptr1; // Pointer for num1
        Dlist *temp_result = result; // Pointer to the result list
        int carry = 0;

        // Move result pointer to the correct position for this digit
        for (int i = 0; i < pos1; i++)
        {
            if (!temp_result->next)
            {
                temp_result->next = create_node(0);
                temp_result->next->prev = temp_result;
            }
            temp_result = temp_result->next;
        }

        while (temp_ptr1 || carry) // Multiply digits of num1 with the current digit of num2
        {
            int mul = (temp_ptr1 ? temp_ptr1->data : 0) * ptr2->data + temp_result->data + carry;
            carry = mul / 10;
            temp_result->data = mul % 10;

            // Move pointers
            if (temp_ptr1) temp_ptr1 = temp_ptr1->prev;
            if (temp_result->next == NULL && (temp_ptr1 || carry))
            {
                temp_result->next = create_node(0);
                temp_result->next->prev = temp_result;
            }
            temp_result = temp_result->next;
        }

        pos1++;
        ptr2 = ptr2->prev; // Move to the next digit of num2
    }

    // Update the result head pointer
    *headR = result;
    return result_sign;
}
