#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "billing.h"

void generate_bill(char *name, product* head);

customer* new_customer(customer* customer_list) 
{
    printf("\n===== New Customer =====\n");
    customer* new_cust = (customer*)malloc(sizeof(customer));
    printf("Enter customer name: ");
    scanf(" %[^\n]s", new_cust->name);
    new_cust->head = NULL; 
    printf("Adding items:\n");
    product* current = NULL;
    char flag[4] = "yes";
    while(strcmp(flag, "yes") == 0)
    {
        product* new_item = (product*)malloc(sizeof(product));
        printf("Item: ");
        scanf(" %[^\n]s", new_item->item);
        printf("Quantity: ");
        scanf("%d", &new_item->quantity);
        printf("Price: ");
        scanf("%f", &new_item->price);
        new_item->next = NULL;
        if(new_cust->head == NULL) 
        {
            new_cust->head = new_item;
            current = new_item;
        }
        else 
        {
            current->next = new_item;
            current = current->next;
        }
        printf("Add more items? (yes/no): ");
        scanf("%s", flag);
    }
    printf("Customer '%s' added successfully.\n", new_cust->name);
    generate_bill(new_cust->name, new_cust->head);
    return new_cust;
}

customer* update_product_from_bill(customer* cust) 
{
    printf("\n===== Update Customer =====\n");
    char search_name[1000];
    printf("Enter the name of the customer you want to update: ");
    scanf(" %[^\n]s", search_name);

    customer* current_customer = cust;
    while (current_customer != NULL) 
    {
        if (strcmp(current_customer->name, search_name) == 0) {
            product *original_head = current_customer->head;
            product *head = original_head;
            while (head != NULL && head->next != NULL) 
            {
                head = head->next;
            }
            
            char flag[4] = "yes";
            while(strcmp(flag, "yes") == 0) 
            {
                printf("ADD ITEM:\n");
                product *s = (product*)malloc(sizeof(product));
                scanf(" %[^\n]s", s->item); 
                printf("ENTER QUANTITY:\n");
                scanf("%d", &s->quantity); 
                printf("ENTER PRICE:\n");
                scanf("%f", &s->price); 
                s->next = NULL;
                if(head == NULL) 
                {
                    head = s;
                    original_head = s;
                } 
                else 
                {
                    head->next = s;
                    head = head->next;
                }
                printf("ADD MORE? yes/no \n");
                scanf("%s", flag);
            }

            printf("Generating Updated Bill for customer '%s'...\n", search_name);
            generate_bill(search_name, original_head);
            current_customer->head = original_head; 
            return cust; 
        }
        current_customer = current_customer->next;
    }

    printf("Customer '%s' not found.\n", search_name);
    return cust;
}

customer* delete_product_from_bill(customer* cust) 
{
    printf("\n===== Delete Product from Customer's Bill =====\n");
    char search_name[1000];
    printf("Enter the name of the customer: ");
    scanf(" %[^\n]s", search_name);

    customer* current_customer = cust;
    while (current_customer != NULL) 
    {
        if (strcmp(current_customer->name, search_name) == 0) 
        {
            char item_to_delete[1000];
            printf("Enter the item to delete from the bill: ");
            scanf(" %[^\n]s", item_to_delete);

            product *current_product = current_customer->head;
            product *prev_product = NULL;

            while (current_product != NULL) 
            {
                if (strcmp(current_product->item, item_to_delete) == 0) 
                {
                    if (prev_product == NULL) 
                    {
                        current_customer->head = current_product->next;
                    } 
                    else 
                    {
                        prev_product->next = current_product->next;
                    }
                    free(current_product);
                    printf("Item '%s' deleted from the bill of customer '%s'.\n", item_to_delete, search_name);
                    printf("Updated Bill for customer '%s' after deletion:\n", search_name);
                    generate_bill(search_name, current_customer->head);
                    return cust; 
                }
                prev_product = current_product;
                current_product = current_product->next;
            }
            printf("Item '%s' not found in the bill of customer '%s'.\n", item_to_delete, search_name);
            return cust;
        }
        current_customer = current_customer->next;
    }
    printf("Customer '%s' not found.\n", search_name);
    return cust;
}

void generate_bill(char *name, product* head) 
{
    printf("\n===== BILL =====\n");
    printf("CUSTOMER NAME: %s\n", name);
    printf("=======================================\n");
    printf("ITEM\tQUANTITY\tPRICE\tTOTAL\n");
    printf("=======================================\n");
    float total_amount = 0;
    while(head != NULL) 
    {
        float item_total = head->quantity * head->price;
        printf("%s\t%d\t%.2f\t%.2f\n", head->item, head->quantity, head->price, item_total);
        total_amount += item_total;
        head = head->next;
    }
    printf("=======================================\n");
    printf("TOTAL AMOUNT: %.2f\n", total_amount);
}