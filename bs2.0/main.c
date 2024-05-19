#include <stdio.h>
#include <stdlib.h>
#include "billing.h"

int main() {
    printf("======== Welcome to the Billing System! ========\n");
    customer* customer_list = NULL;
    int choice;
    while(choice != 4) {
        printf("\n===== Main Menu =====\n");
        printf("1. New Customer\n");
        printf("2. Update Product from Customer's Bill\n");
        printf("3. Delete Product from Customer's Bill\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                customer_list = new_customer(customer_list);
                break;
            case 2:
                customer_list = update_product_from_bill(customer_list); 
                break;
            case 3:
                customer_list = delete_product_from_bill(customer_list); 
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please enter a number between 1 and 4.\n");
        }
    }

    return 0;
}
