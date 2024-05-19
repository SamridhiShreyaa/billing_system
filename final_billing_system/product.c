#include "billing_system.h"

void generate_bill(char *name, product* head) {
    printf("\n===== BILL =====\n");
    printf("CUSTOMER NAME: %s\n", name);
    printf("=======================================\n");
    printf("ITEM\tQUANTITY\tPRICE\tTOTAL\n");
    printf("=======================================\n");
    float total_amount = 0;
    while(head != NULL) {
        float item_total = head->quantity * head->price;
        printf("%s\t%d\t%.2f\t%.2f\n", head->item, head->quantity, head->price, item_total);
        total_amount += item_total;
        head = head->next;
    }
    printf("=======================================\n");
    printf("TOTAL AMOUNT: %.2f\n", total_amount);
}
