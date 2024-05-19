#include "billing_system.h"

int main() {
    printf("===== WELCOME TO THE BILLING SYSTEM! =====\n");
    const char* customer_filename = "customers.csv";
    const char* user_filename = "users.csv";

    user* user_list = load_users(user_filename);
    if (!user_list) {
        printf("No previous user data found, starting a new user list.\n");
    }

    int authenticated = 0;
    while (!authenticated) {
        printf("\n========= EMPLOYEE LOGIN MENU =========\n");
        printf("1. Login\n");
        printf("2. Register\n");
        printf("Enter your choice: ");
        int login_choice;
        scanf("%d", &login_choice);

        switch(login_choice) {
            case 1:
                authenticated = login(user_list);
                break;
            case 2:
                user_list = register_user(user_list);
                save_users(user_filename, user_list);
                authenticated = 0; // Set authenticated to 0 to prompt login after registration
                break;
            default:
                printf("Invalid choice! Please enter a number between 1 and 2.\n");
        }
    }

    customer* customer_list = load_data(customer_filename);
    if (!customer_list) {
        printf("No previous data found, starting a new list.\n");
    }

    int choice;
    while(choice != 4) {
        printf("\n======= MAIN MENU =======\n");
        printf("1. New Customer\n");
        printf("2. Update Customer\n");
        printf("3. Delete Product from Customer's Bill\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                customer_list = new_customer(customer_list); 
                break;
            case 2:
                customer_list = update_customer(customer_list); 
                break;
            case 3:
                customer_list = delete_product_from_bill(customer_list); 
                break;
            case 4:
                printf("Saving data and exiting...\n");
                save_data(customer_filename, customer_list); 
                save_users(user_filename, user_list); 
                break;
            default:
                printf("Invalid choice! Please enter a number between 1 and 4.\n");
        }
    }

    return 0;
}