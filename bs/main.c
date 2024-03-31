#include <stdio.h>
#include "function.h"

int main() {
    int choice;

    printf("Welcome to the Billing System!\n");

    do {
        // Display menu options
        printf("\n===== Main Menu =====\n");
        printf("1. Add Customer\n");
        printf("2. Add Product\n");
        printf("3. Generate Bill\n");
        printf("4. Update Customer\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Process user's choice
        switch(choice) {
            case 1:
                addCustomer();
                break;
            case 2:
                addProduct();
                break;
            case 3:
                generateBill();
                break;
            case 4:
                updateCustomer();
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please enter a number between 1 and 5.\n");
        }
    } while(choice != 5);

    return 0;
}
