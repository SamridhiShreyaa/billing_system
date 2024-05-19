#ifndef BILLING_H
#define BILLING_H

struct product {
    char item[1000];
    int quantity;
    float price;
    struct product* next;
};

struct customer {
    char name[1000];
    struct product* head;
    struct customer* next;
};

typedef struct product product;
typedef struct customer customer;

void generate_bill(char *name, product* head);
customer* new_customer(customer* customer_list);
customer* update_product_from_bill(customer* cust);
customer* delete_product_from_bill(customer* cust);

#endif /* BILLING_H */
