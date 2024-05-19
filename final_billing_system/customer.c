#include "billing_system.h"

customer* new_customer(customer* customer_list) {
    printf("\n===== New Customer =====\n");
    customer* new_cust = (customer*)malloc(sizeof(customer));
    printf("Enter customer name: ");
    scanf(" %[^\n]s", new_cust->name);
    new_cust->head = NULL; // Initialize customer's product list
    printf("Adding items:\n");
    product* current = NULL;
    char flag[4] = "yes";
    while(strcmp(flag, "yes") == 0) {
        product* new_item = (product*)malloc(sizeof(product));
        printf("Item: ");
        scanf(" %[^\n]s", new_item->item);
        printf("Quantity: ");
        scanf("%d", &new_item->quantity);
        printf("Price: ");
        scanf("%f", &new_item->price);
        new_item->next = NULL;
        if(new_cust->head == NULL) {
            new_cust->head = new_item;
            current = new_item;
        } else {
            current->next = new_item;
            current = current->next;
        }
        printf("Add more items? (yes/no): ");
        scanf("%s", flag);
    }
    printf("Customer '%s' added successfully.\n", new_cust->name);
    generate_bill(new_cust->name, new_cust->head);
    new_cust->next = customer_list;
    return new_cust;
}

customer* update_customer(customer* cust) {
    printf("\n===== Update Customer =====\n");
    char search_name[1000];
    printf("Enter the name of the customer you want to update: ");
    scanf(" %[^\n]s", search_name);

    customer* current_customer = cust;
    while (current_customer != NULL) {
        if (strcmp(current_customer->name, search_name) == 0) {
            product *original_head = current_customer->head; // Save the original product list
            product *head = original_head;
            
            while (head != NULL && head->next != NULL) {
                head = head->next;
            }
            
            char flag[4] = "yes";
            while(strcmp(flag, "yes") == 0) {
                printf("ADD ITEM:\n");
                product *s = (product*)malloc(sizeof(product));
                printf("Item: ");
                scanf(" %[^\n]s", s->item); 
                printf("Quantity: ");
                scanf("%d", &s->quantity); 
                printf("Price: ");
                scanf("%f", &s->price); 
                s->next = NULL;
                if(head == NULL) {
                    head = s;
                    original_head = s;
                } else {
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

customer* delete_product_from_bill(customer* cust) {
    printf("\n===== Delete Product from Customer's Bill =====\n");
    char search_name[1000];
    printf("Enter the name of the customer: ");
    scanf(" %[^\n]s", search_name);

    customer* current_customer = cust;
    while (current_customer != NULL) {
        if (strcmp(current_customer->name, search_name) == 0) {
            char item_to_delete[1000];
            printf("Enter the item to delete from the bill: ");
            scanf(" %[^\n]s", item_to_delete);

            product *current_product = current_customer->head;
            product *prev_product = NULL;

            while (current_product != NULL) {
                if (strcmp(current_product->item, item_to_delete) == 0) {
                    // Item found, delete it from the bill
                    if (prev_product == NULL) {
                        // Deleting the first node
                        current_customer->head = current_product->next;
                    } else {
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