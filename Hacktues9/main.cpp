#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pch.h"
#include<iostream>
using namespace std;

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

	FILE* fp1, * fp2;
	char ch;

	fp2 = fopen("password_safe_key.txt", "a+");
	fseek(fp2, 0, SEEK_END);
	if (ftell(fp2) == 0)
	{
		printf("Please create the master password: \n");
		//scanf("%s", master_password);
		cin.getline(master_password, MAX_PASSWORD_LENGTH);
		fprintf(fp2, "%s", master_password);

	}
	else
	{
		//scanf("%s", master_password);
		printf("Master password exists\n");
		rewind(fp2);
		fscanf(fp2, "%s", master_password);
		//printf("Restored password is %s\n", master_password);
	}
	fclose(fp2);

	while (1) {
		if (!is_logged_in) {
			char input_password[MAX_PASSWORD_LENGTH];
			printf("Enter the Master Password: ");
			//scanf("%s", input_password);
			cin.getline(input_password, MAX_PASSWORD_LENGTH);

			if (strcmp(input_password, master_password) == 0)
			{
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

			switch (choice)
			{
			case(1):
				fp1 = fopen("password_safe.txt", "a+");
				if (num_passwords == MAX_PASSWORDS)
				{
					printf("No more space for passwords!\n");
				}
				else
				{
					printf("Enter the new application name:\n");
					//scanf("%s", application_name);

					getchar();

					cin.getline(application_name, MAX_PASSWORD_LENGTH);

					// keep reading the user input from the terminal
					// till Return (Enter) key is pressed

					for (int i = 0; i < strlen(application_name); i++)
						//while (((ch = getchar()) != EOF) && (ch != '\n')) 
					{
						// write character ch in file

						fputc((char)application_name[i] + 10, fp1);

					}
					fputc((char)':' + 10, fp1);

					printf("Enter the new password:\n");
					//scanf("%s", password_content);

					cin.getline(password_content, MAX_PASSWORD_LENGTH);
					for (int j = 0; j < strlen(password_content); j++)
					{
						//while ((ch = getchar()) != EOF && ch != '\n') {
							//scanf("%s", passwords[num_passwords]);
							//ch = ch + 100;
							// write character ch in file
						fputc(password_content[j] + 10, fp1);
						num_passwords++;
					}
					fputc((char)'\n' + 10, fp1);
					printf("END of entering passwords\n");
				}
				fclose(fp1);
				break;

			case(2):
				fp1 = fopen("password_safe.txt", "a+");
				printf("\nList of saved passwords :\n");
				while ((ch = fgetc(fp1)) != EOF)
				{
					ch = ch - 10;
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
