#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

struct user {
    char username[1000];
    char password[1000];
    struct customer* customer_list;
    struct user* next;
};

typedef struct product product;
typedef struct customer customer;
typedef struct user user;

void generate_bill(char *name, product* head);
customer* new_customer(customer* customer_list);
customer* update_customer(customer* cust);
customer* delete_product_from_bill(customer* cust);
customer* load_data(const char* filename);
void save_data(const char* filename, customer* customer_list);
user* load_users(const char* filename);
void save_users(const char* filename, user* user_list);
int login(user* user_list);
user* register_user(user* user_list);