#include <stdio.h>
#include <string.h>
#define max_acc 100

struct bank {
    int acc_num;
    char name[20];
    int balance;
};
struct bank acc[max_acc];
int acc_count = 0;

// Function to add a bank account
void add_bankacc(int acc_num, char name[20], int balance) {
    if (acc_count < max_acc) {
        acc[acc_count].acc_num = acc_num;
        strcpy(acc[acc_count].name, name);
        acc[acc_count].balance = balance;
        acc_count++;
    } else {
        printf("Bank has met the maximum number of accounts.\n");
    }
}

// Function to deposit
void deposit(int acc_num, int amount) {
    int flag = -1;
    for (int i = 0; i < acc_count; i++) {
        if (acc[i].acc_num == acc_num) {
            flag = i;
            break;
        }
    }
    if (flag != -1) {
        acc[flag].balance += amount;
        printf("Current balance of account number %d is: %d\n", acc[flag].acc_num, acc[flag].balance);
    } else {
        printf("Account not found.\n");
    }
}

// Function to show balance
void deposited_value(int acc_num) {
    int hell = -1;
    for (int i = 0; i < acc_count; i++) {
        if (acc[i].acc_num == acc_num) {
            hell = i;
            break;
        }
    }
    if (hell != -1) {
        printf("The balance left on acc_num %d is: %d", acc[hell].acc_num, acc[hell].balance);
    } else {
        printf("Enter a valid acc_number!!\n");
    }
}

int main() {
    int acc_num, balance;
    char name[20];
    int amount;

    printf("Enter the bank account number: ");
    scanf("%d", &acc_num);
    printf("Enter the account holder name: ");
    scanf("%s", name);
    printf("Enter the amount to be deposited: ");
    scanf("%d", &balance);

    add_bankacc(7538, "jerome", 10);
    add_bankacc(9865, "john", 1000);
    add_bankacc(9042, "ananthi", 9000);
    printf("Enter the account number to show balance: ");
    scanf("%d", &acc_num);
    deposited_value(acc_num);
    printf("enter the acc_number:");
    scanf("%d",&acc_num);
    printf("enter the amount to be deposited:");
    scanf("%d",&amount);
    deposit(acc_num, amount);

    return 0;
}

