// This is the code to make login page in C language 
// Created by IG - @its_.monster._      
// https://github.com/monster-anshu
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h> 
#define a 97
#define b 98
#define ESC 27
#define admn 65

void clrscr()
{
    system("cls");
}
COORD coord = {0, 0};

void gotoxy(int x, int y)
{
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

struct login
{
    char name[20];
    char pass[20];
} user;

struct info
{
    char user[20], name[20], phone[15], email[50], course[8], add[10];
} info;

void login();
void singup();
void admin();
void information();
void ShowInfo();

int i;
char username[20], password[20];
FILE *fptr;

void main()
{
    char c;

    while (1)
    {
        clrscr();
        gotoxy(23, 5);
        printf("Loading");
        for (i = 0; i < 30; i++)
        {
            printf(".");
            Sleep(30);
        }
        gotoxy(23, 5);
        printf("_-_-_-_-_-_-_-_-_-_-_ Login Page _-_-_-_-_-_-_-_-_-_-_");
        gotoxy(23, 7);
        printf(" a for Singup ");
        gotoxy(23, 9);
        printf(" b for Login ");
        gotoxy(23, 11);
        printf(" ESC for exit ");
        gotoxy(23, 13);
        printf(" sift + a for admin page ");
        gotoxy(23, 15);
        printf("X_X_X_X_X_X_X_X_X_X_X_X_X_X_X_X");
        c = getch();
        switch (c)
        {
        case a:
            clrscr();
            gotoxy(23, 7);
            for (i = 0; i < 80; i++)
            {
                printf("_");
                Sleep(10);
            }
            singup();
            break;
        case b:
            clrscr();
            gotoxy(23, 7);
            for (i = 0; i < 80; i++)
            {
                printf("_");
                Sleep(10);
            }
            login();
            break;
        case admn:
            clrscr();
            gotoxy(23, 7);
            for (i = 0; i < 80; i++)
            {
                printf("_");
                Sleep(10);
            }
            admin();
            break;
        case ESC:
            exit(0);
        }
    }
}

void information()
{
    int i;
    char c;
    clrscr();
    gotoxy(23, 7);
    for (i = 0; i < 80; i++)
    {
        printf("_");
        Sleep(10);
    }
    clrscr();
    gotoxy(23, 3);
    printf("_-_-_-_-_-_-_-_-_-_-_-_-_-_ Fill from _-_-_-_-_-_-_-_-_-_-_-_-_-_");
    gotoxy(25, 5);
    printf(" Enter name : ");
    gets(info.name);
    fflush(stdin);
    gotoxy(25, 7);
    printf(" Enter Phone no. : ");
    gets(info.phone);
    fflush(stdin);
    gotoxy(25, 9);
    printf(" Enter email : ");
    gets(info.email);
    fflush(stdin);
    gotoxy(25, 11);
    printf(" Enter Course : ");
    fflush(stdin);
    gets(info.course);
    fflush(stdin);
    gotoxy(25, 13);
    printf(" Enter Addmission no. : ");
    gets(info.add);
    fflush(stdin);
    strcpy(info.user, user.name);
    fptr = fopen("info.bin", "a");
    fwrite(&info, sizeof(info), 1, fptr);
    fclose(fptr);
    gotoxy(25, 15);
    for (i = 0; i < 35; i++)
    {
        printf("_-");
        Sleep(20);
    }
    gotoxy(25, 17);
    printf(" Press any key to continue");
    getch();
    clrscr();
}

void ShowInfo()
{
    clrscr();
    gotoxy(23, 7);
    for (i = 0; i < 80; i++)
    {
        printf("_");
        Sleep(10);
    }
    clrscr();
    fptr = fopen("info.bin", "rb");
    gotoxy(23, 3);
    printf("_-_-_-_-_-_-_-_-_-_-_-_-_-_ Information _-_-_-_-_-_-_-_-_-_-_-_-_-_");
    while (!feof(fptr))
    {
        fread(&info, sizeof(info), 1, fptr);
        if (strcmp(info.user, user.name) == 0)
        {
            gotoxy(23, 5);
            printf(" Name = %s", info.name);
            gotoxy(23, 7);
            printf(" Phone = %s", info.phone);
            gotoxy(23, 9);
            printf(" Email = %s", info.email);
            gotoxy(23, 11);
            printf(" Course = %s", info.course);
            gotoxy(23, 13);
            printf(" Addmission  = %s", info.add);
            gotoxy(23, 15);
            printf("X_X_X_X_X_X_X_X_X_X_X_X_X_X_X_X");
        }
    }
    getch();
}
void singup()
{
    char c;
    int check;
    clrscr();
    gotoxy(23, 3);
    printf("_-_-_-_-_-_-_-_-_-_-_-_-_-_ Singup Page _-_-_-_-_-_-_-_-_-_-_-_-_-_");
    fptr = fopen("record.bin", "ab");
    gotoxy(25, 5);
    printf(" Enter username   : ");
    fflush(stdin);
    gets(username);
    fread(&user, sizeof(user), 1, fptr);
    check = strcmp(username, user.name);
    if (check == 0)
    {
        gotoxy(25, 7);
        printf(" User Alredy exist !!!!");
        getch();
        return;
    }
    strcpy(user.name, username);
    gotoxy(25, 7);
    printf(" Enter password    : ");
    fflush(stdin);
    gets(user.pass);
    fwrite(&user, sizeof(user), 1, fptr);
    gotoxy(25, 9);
    fclose(fptr);
    for (i = 0; i < 35; i++)
    {
        printf("_-");
        Sleep(20);
    }
    gotoxy(25, 11);
    printf(" Information saved ");
    gotoxy(25, 13);
    printf("Press any key to continue ");
    if (getch() == ESC)
        exit(0);
    clrscr();
    information();
}

void login()
{
    int check_user = 1, check_pass = 1, flag = 0;
    clrscr();
    gotoxy(25, 3);
    printf("_-_-_-_-_-_-_-_-_-_-_-_-_-_ Login Page _-_-_-_-_-_-_-_-_-_-_-_-_-_");
    gotoxy(25, 5);
    printf(" Enter username   : ");
    gets(username);
    gotoxy(25, 7);
    printf(" Enter password   : ");
    gets(password);
    fptr = fopen("record.bin", "r");
    gotoxy(25, 9);
    while (!feof(fptr))
    {
        fread(&user, sizeof(user), 1, fptr);
        check_user = strcmp(user.name, username);
        if (check_user == 0)
            break;
    }
    if (check_user != 0)
    {
        printf(" User Not found !!!! \t Login Again");
        getch();
        return;
    }

    while (!feof(fptr))
    {
        fread(&user, sizeof(user), 1, fptr);
        check_user = strcmp(user.name, username);
        check_pass = strcmp(user.pass, password);
        if (check_user == 0 && check_pass == 0)
            flag = 1;
    }
    if (flag == 0)
        printf(" Invalid details........");
    else
        ShowInfo();
}

void admin()
{
    gotoxy(23,5);
    printf(" Admin page is not ready.........");
    getch();
}

// https://github.com/monster-anshu
