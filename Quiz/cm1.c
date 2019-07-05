#include<stdio.h>
#include<string.h>

FILE *fl;

struct quiz
{
    int no;
    char qn[500], oa[50], ob[50], oc[50], od[50];
    int ca;
    struct quiz *next;
};
struct quiz *headislam, *headbangladesh, *headsports, *headinternational, *headiq, *head;
int marks = 0;

choice(int cho)
{
    switch(cho)
    {
    case 1:
    {
        head = headislam;
        fl = fopen("islam.txt", "r");
        break;
    }
    case 2:
    {
        head = headbangladesh;
        fl = fopen("bangladesh.txt", "r");
        break;
    }
    case 3:
    {
        head = headsports;
        fl = fopen("sports.txt", "r");
        break;
    }
    case 4:
    {
        head = headinternational;
        fl = fopen("international.txt", "r");
        break;
    }
    case 5:
    {
        head = headiq;
        fl = fopen("iq.txt", "r");
        break;
    }
    }
}

insert_after(int a, char qna[], char oaa[], char oba[], char oca[], char oda[], int caa)
{
    struct quiz *temp, *var;
    temp = (struct quiz*)malloc(sizeof(struct quiz));
    temp->ca = caa;
    strcpy(temp->qn, qna);
    strcpy(temp->oa, oaa);
    strcpy(temp->ob, oba);
    strcpy(temp->oc, oca);
    strcpy(temp->od, oda);
    temp->no = a;
    temp->next = NULL;
    if(head == NULL)
        head = temp;
    else
    {
        var = head;
        while(var->next != NULL)
            var = var->next;
        var->next = temp;
    }
}
display()
{
    system("cls");
    int ans;
    struct quiz *i = head;
    while(i != NULL)
    {
        printf("%d. ", i->no);
        printf("%s\n\n", i->qn);
        printf("  a. %s    ", i->oa);
        printf("b. %s\n", i->ob);
        printf("  c. %s    ", i->oc);
        printf("d. %s\n\n", i->od);
        printf("Your answer: ");
        scanf("%d", &ans);
        if(ans == i->ca)
        {
            printf("Right\n");
            marks++;
        }
        else
            printf("Wrong. correct ans is %c\n", i->ca+96);
        i = i->next;
    }
}
main()
{
    int i, cho, ca;
    char qn[500], oa[50], ob[50], oc[50], od[50];
    do
    {
        printf("\n\n                    Welcome here to measure your ability\n\n\n\npick your choice:\n~~~~~~~~~~~~~~~~~\n1. Islam\n2. Bangladesh\n3. Sports\n4. International\n5. I.Q. test\n\n\nYour choice:  ");
        scanf("%d", &cho);
        printf("\n\n");
        choice(cho);

        for(i=1; i<=5; i++)
        {
            fscanf(fl, "%s", &qn);
            fscanf(fl, "%s", &oa);
            fscanf(fl, "%s", &ob);
            fscanf(fl, "%s", &oc);
            fscanf(fl, "%s", &od);
            fscanf(fl, "%d", &ca);
            insert_after(i, qn, oa, ob, oc, od, ca);
        }
        display();
        fclose(fl);
        printf("Do you wanna continue? (y/n)\n");
    }
    while(getch() == 'y' || getch() == 'Y');
    printf("\n\nThank you.\nYour marks:  %d\n\n", marks);
}
