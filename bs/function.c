#include <stdio.h>
#include "function.h"
#define n 10
#define GST_RATE 0.18 // Assuming a fixed GST rate of 18%

void addCustomer() {
    printf("Adding a new customer...\n");
    printf("Enter customer name: ");
    char name[n];
    scanf("%s", name);
    printf("Customer '%s' added successfully!\n", name);
}

void addProduct() {
    // Logic for adding a new product
    printf("Adding a new product...\n");
    
    // Prompt user for product name
    printf("Enter product name: ");
    char name[n];
    scanf("%s", name);
    
    // Prompt user for product quantity
    int quantity;
    printf("Enter product quantity: ");
    scanf("%d", &quantity);

    // You can prompt the user to enter additional product details here
    printf("Product '%s' (Quantity: %d) added successfully!\n", name, quantity);
}


void generateBill() {
    
    printf("Generating bill...\n");
    double totalAmount = 1000; // Sample total amount before discount
    double gstAmount = totalAmount * GST_RATE;
    double finalBill = totalAmount + gstAmount;

    printf("Total Amount: %.2f\n", totalAmount);
    printf("GST: %.2f\n", gstAmount);
    printf("Final Bill (including GST): %.2f\n", finalBill);
}

void updateCustomer() {
    printf("Updating customer details...\n");
    printf("Enter customer name to update: ");
    char name[n];
    scanf("%s", name);
    printf("Customer '%s' details updated successfully!\n", name);
}
