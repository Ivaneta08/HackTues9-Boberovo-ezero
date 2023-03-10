/******************************************************************************

							Online C Compiler.
				Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include "pch.h"
#include <iostream>

#define MAX_PASSWORDS 10
#define MAX_PASSWORD_LENGTH 20
#define MAX_NAME_LENGTH 30

int main() {
	char master_password[MAX_PASSWORD_LENGTH];
	char passwords[MAX_PASSWORDS][MAX_PASSWORD_LENGTH];
	char name[MAX_PASSWORDS][MAX_NAME_LENGTH];
	char input_password[MAX_PASSWORD_LENGTH];
	char application_name[MAX_PASSWORD_LENGTH];
	char password_content[MAX_PASSWORD_LENGTH];
	int num_passwords = 0;
	int is_logged_in = 0;
	int attempts_left = 3;
	long size;

    printf("Welcome to Password Safe\n");
    printf("Enter the master password: ");
    //scanf("%s", master_password);
    cin.getline(master_password, MAX_PASSWORD_LENGTH);

    while (1) {
        if (!is_logged_in) {
            char input_password[MAX_PASSWORD_LENGTH];
            printf("Enter the master password: ");
            //scanf("%s", input_password);
            cin.getline(input_password, MAX_PASSWORD_LENGTH);

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
            printf("2. Show password\n");
            printf("3. Exit\n");

			int choice;
			scanf("%d", &choice);

            if (choice == 1) {
                if (num_passwords == MAX_PASSWORDS) {
                    printf("No more space for passwords!\n");
                }
                else {
                    printf("Enter the new name: ");
                    //scanf("%s", name[num_passwords]);
                    getchar();

                    cin.getline(name[num_passwords], MAX_NAME_LENGTH);
                    
                    printf("Enter the new password: ");
                    //scanf("%s", passwords[num_passwords]);
                    cin.getline(passwords[num_passwords], MAX_PASSWORD_LENGTH);
                    num_passwords++;
                }
            }
            else if (choice == 2) {
                char c_name[MAX_NAME_LENGTH];
                int flag = 0;
                printf("Enter name: ");
                //scanf("%s", c_name);
                getchar();

                cin.getline(c_name, MAX_NAME_LENGTH);

			case(2):
				fp1 = fopen("password_safe.txt", "a+");
				printf("\nList of saved passwords :\n");
				while ((ch = fgetc(fp1)) != EOF)
				{
					if (ch != ':')
					{
						ch = ch - 10;
					}
					printf("%c", ch);
				}

				printf("\nEnd of file\n");
				fclose(fp1);
				break;

			case (3):
				printf("Exiting.\n");
				exit(-1);
				break;

			default:
				printf("Invalid choice!\n");
				break;
			}

		}
	}


	return 0;
}