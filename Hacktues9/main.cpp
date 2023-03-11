﻿#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pch.h"
#include<iostream>
#include <cmath>
#include <iomanip>
#include <map>
#include <random>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

#define MAX_PASSWORDS 10
#define MAX_PASSWORD_LENGTH 20
#define MAX_NAME_LENGTH 30

char generate_random_character(const std::string& char_set)
{
	int random_index = rand() % char_set.length();
	return char_set[random_index];
}

string generate_password()
{
	std::string password;
	std::random_device rd;
	std::uniform_int_distribution<int> dist(0, 25); // Distribution for random lowercase letters

	for (int i = 0; i < 10; i++)
	{
		char c = 'a' + dist(rd); // Generate a random lowercase letter
		password.push_back(c);
	}

	return password;
}

int main()
{
	char master_password[MAX_PASSWORD_LENGTH]{};
	char passwords[MAX_PASSWORDS][MAX_PASSWORD_LENGTH]{};
	char name[MAX_PASSWORDS][MAX_NAME_LENGTH]{};
	char input_password[MAX_PASSWORD_LENGTH]{};
	char application_name[MAX_PASSWORD_LENGTH]{};
	char password_content[MAX_PASSWORD_LENGTH]{};
	int num_passwords = 0;
	int is_logged_in = 0;
	int attempts_left = 3;
	string pass;


	FILE* fp1, * fp2;
	char ch;

	fp2 = fopen("password_safe_key.txt", "a+");
	fseek(fp2, 0, SEEK_END);
	if (ftell(fp2) == 0)
	{
		printf("Please create the master password: \n");
		//scanf("%s", master_password);
		getline(cin, pass);

		while (pass.size() > MAX_PASSWORD_LENGTH)
		{
			printf("Max password length exceeded\nPlease try again: \n");
			getline(cin, pass);
		}

		for (int i = 0; i < pass.size(); i++)
		{
			master_password[i] = pass[i];
		}

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

	while (1)
	{
		if (!is_logged_in)
		{
			char input_password[MAX_PASSWORD_LENGTH]{};
			printf("Enter the Master Password: ");

			getline(cin, pass);

			while (pass.size() > MAX_PASSWORD_LENGTH)
			{
				printf("Max password length exceeded\nPlease try again: \n");
				getline(cin, pass);
			}

			for (int i = 0; i < pass.size(); i++)
			{
				input_password[i] = pass[i];
			}

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
			printf("3. Strong password\n");
			printf("4. Exit\n");

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

					//cin.getline(application_name, MAX_NAME_LENGTH);

					getline(cin, pass);

					while (pass.size() > MAX_NAME_LENGTH)
					{
						printf("Max name length exceeded\nPlease try again: \n");
						getline(cin, pass);
					}

					for (int i = 0; i < pass.size(); i++)
					{
						application_name[i] = pass[i];
					}

					for (int i = 0; i < strlen(application_name); i++)

					{

						fputc((char)application_name[i] + 10, fp1);

					}
					fputc((char)':' + 10, fp1);

					printf("Enter the new password:\n");
					//scanf("%s", password_content);
					num_passwords++;

					getline(cin, pass);

					while (pass.size() > MAX_PASSWORD_LENGTH)
					{
						printf("Max password length exceeded\nPlease try again: \n");
						getline(cin, pass);
					}

					for (int i = 0; i < pass.size(); i++)
					{
						password_content[i] = pass[i];
					}

					for (int j = 0; j < strlen(password_content); j++)
					{

						fputc(password_content[j] + 10, fp1);

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
			{
				string str = generate_password();

				printf("%s\n", str.c_str());
				break;
			}

			case (4):
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