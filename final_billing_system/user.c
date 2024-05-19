#include "billing_system.h"

int login(user* user_list) {
    char username[1000];
    char password[1000];
    printf("Enter username: ");
    scanf(" %[^\n]s", username);
    printf("Enter password: ");
    scanf(" %[^\n]s", password);

    user* current_user = user_list;
    while (current_user) {
        if (strcmp(current_user->username, username) == 0 && strcmp(current_user->password, password) == 0) 
        {
            printf("Login successful!\n");
            return 1;
        }
        current_user = current_user->next;
    }

    printf("Invalid username or password.\n");
    return 0;
}

user* register_user(user* user_list) {
    char username[1000];
    char password[1000];
    printf("Enter new username: ");
    scanf(" %[^\n]s", username);
    printf("Enter new password: ");
    scanf(" %[^\n]s", password);

    user* new_user = (user*)malloc(sizeof(user));
    strcpy(new_user->username, username);
    strcpy(new_user->password, password);
    new_user->next = user_list;
    printf("User registered successfully! Please log in with your new credentials.\n");
    return new_user;
}