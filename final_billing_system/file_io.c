#include "billing_system.h"

user* load_users(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (!file) return NULL;

    user* user_list = NULL;
    user* current_user = NULL;
    char line[1024];

    while (fgets(line, sizeof(line), file)) {
        user* new_user = (user*)malloc(sizeof(user));
        sscanf(line, "%[^,],%s", new_user->username, new_user->password);
        new_user->next = NULL;
        if (!user_list) {
            user_list = new_user;
        } else {
            current_user->next = new_user;
        }
        current_user = new_user;
    }

    fclose(file);
    return user_list;
}

void save_users(const char* filename, user* user_list) {
    FILE* file = fopen(filename, "w");
    if (!file) return;

    user* current_user = user_list;
    while (current_user) {
        fprintf(file, "%s,%s\n", current_user->username, current_user->password);
        current_user = current_user->next;
    }

    fclose(file);
}

customer* load_data(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (!file) return NULL;

    customer* customer_list = NULL;
    customer* current_customer = NULL;
    char line[2000];

    while (fgets(line, sizeof(line), file)) {
        if (line[0] == 'C') {
            customer* new_cust = (customer*)malloc(sizeof(customer));
            sscanf(line, "Customer,%[^\n]", new_cust->name);
            new_cust->head = NULL;
            new_cust->next = NULL;
            if (!customer_list) {
                customer_list = new_cust;
            } else {
                if (current_customer != NULL) {
                    current_customer->next = new_cust;
                }
            }
            current_customer = new_cust;
        } else if (line[0] == 'P' && current_customer != NULL) 
        {
            product* new_prod = (product*)malloc(sizeof(product));
            sscanf(line, "Product,%[^,],%d,%f", new_prod->item, &new_prod->quantity, &new_prod->price);
            new_prod->next = NULL;
            if (!current_customer->head)
            {
                current_customer->head = new_prod;
            } else 
            {
                product* current_prod = current_customer->head;
                while (current_prod->next) {
                    current_prod = current_prod->next;
                }
                current_prod->next = new_prod;
            }
        }
    }

    fclose(file);
    return customer_list;
}

void save_data(const char* filename, customer* customer_list) {
    FILE* file = fopen(filename, "w");
    if (!file) return;

    customer* current_customer = customer_list;
    while (current_customer)
    {
        fprintf(file, "Customer,%s\n", current_customer->name);
        product* current_product = current_customer->head;
        while (current_product) 
        {
            fprintf(file, "Product,%s,%d,%.2f\n", current_product->item, current_product->quantity, current_product->price);
            current_product = current_product->next;
        }
        current_customer = current_customer->next;
    }

    fclose(file);
}