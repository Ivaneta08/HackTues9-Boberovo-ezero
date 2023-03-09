#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <pch.h>

#define MAX_PASSWORDS 10
#define MAX_PASSWORD_LENGTH 20
#define MAX_NAME_LENGTH 30

int main() {
    char master_password[MAX_PASSWORD_LENGTH];
    char passwords[MAX_PASSWORDS][MAX_PASSWORD_LENGTH];
    char name[MAX_PASSWORDS][MAX_NAME_LENGTH];
    int num_passwords = 0;
    int is_logged_in = 0;
    int attempts_left = 3;

    printf("Welcome to Password Safe\n");
    printf("Enter the master password: ");
    scanf("%s", master_password);

    while (1) {
        if (!is_logged_in) {
            char input_password[MAX_PASSWORD_LENGTH];
            printf("Enter the master password: ");
            scanf("%s", input_password);

            if (strcmp(input_password, master_password) == 0) {
                printf("Logged in successfully!\n");
                is_logged_in = 1;
                attempts_left = 3;
            }
            else {
                attempts_left--;
                printf("Incorrect password. %d attempts left.\n", attempts_left);
                if (attempts_left == 0) {
                    printf("Too many incorrect attempts. Exiting.\n");
                    break;
                }
            }
        }
        else {
            printf("Choose an option:\n");
            printf("1. Add password\n");
            printf("2. Show passwords\n");
            printf("3. Exit\n");

            int choice;
            scanf("%d", &choice);

            if (choice == 1) {
                if (num_passwords == MAX_PASSWORDS) {
                    printf("No more space for passwords!\n");
                }
                else {
                    printf("Enter the new name: ");
                    scanf("%s", name[num_passwords]);
                    printf("Enter the new password: ");
                    scanf("%s", passwords[num_passwords]);
                    num_passwords++;
                }
            }
            else if (choice == 2) {
                char c_name[MAX_NAME_LENGTH];
                int flag = 0;
                printf("Enter name: ");
                scanf("%s", c_name);

                for (int i = 0; i < num_passwords; i++)
                {
                    if (strcmp(c_name, name[i]) == 0)
                    {
                        printf("Password: %s\n", passwords[i]);
                        flag = 1;
                    }
                }
                if (!flag)
                {
                    printf("No such name is found!\n");
                }
            }
            else if (choice == 3) {
                printf("Exiting.\n");
                break;
            }
            else {
                printf("Invalid choice!\n");
            }
        }
    }

    return 0;
}