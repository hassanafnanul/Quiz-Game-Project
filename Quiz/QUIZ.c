#include<stdio.h>
#include<string.h>

struct quiz
{
    int no;
    char qn[500], oa[50], ob[50], oc[50], od[50], ca[2];
    struct quiz *next;
};

FILE *fl, *hm;
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
    default:
        {
            printf("Please enter from 1 to 5\n\nYour Chose: ");
            scanf("%d", &cho);
            printf("\n\n");
            choice(cho);
        }
    }
}

insert_after(int a, char qna[], char oaa[], char oba[], char oca[], char oda[], char caa[])
{
    struct quiz *temp, *var;

    temp = (struct quiz*)malloc(sizeof(struct quiz));

    temp->no = a;
    strcpy(temp->qn, qna);
    strcpy(temp->oa, oaa);
    strcpy(temp->ob, oba);
    strcpy(temp->oc, oca);
    strcpy(temp->od, oda);
    strcpy(temp->ca, caa);
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
    char ans[2];
    struct quiz *i = head;

    while(i != NULL)
    {
        printf("\n%d. ", i->no);
        printf("%s\n\n", i->qn);
        printf("  a. %s    ", i->oa);
        printf("b. %s\n", i->ob);
        printf("  c. %s    ", i->oc);
        printf("d. %s\n\n", i->od);
        printf("Your answer: ");
        scanf("%s", &ans);

        if(strcmp(i->ca, ans) == 0)
        {
            printf("\nRight\n");
            marks++;
        }
        else
            printf("\nWrong. correct ans is %s\n", i->ca);
        i = i->next;
    }
}

main()
{
    int i, cho, j, hmm, sc;
    char qn[500], oa[50], ob[50], oc[50], od[50],  ca[2], name[100], nm[100];

    printf("\n\n                    Welcome here to measure your ability\n                    ====================================\n\n\n\nYou have to answer some questions.\nYou are giver 6 different topic to choose any 3 one after another.\nFind out the correct answer and submit your answer.\nLastly get your obtained marks\nAnd compare with the high scorer\nBut try to be the High Scorer.\n\n      Best Of Luck...... :)\n\n\n\nYour Name (First Name):   ");

    scanf("%s", &name);

    for(j=0; j<3; j++)
    {
        printf("\n\n\npick your choice:\n~~~~~~~~~~~~~~~~~\n1. Islam\n2. Bangladesh\n3. Sports\n4. International\n5. I.Q. test\n\n\nYour choice:  ");
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
            fscanf(fl, "%s", &ca);
            insert_after(i, qn, oa, ob, oc, od, ca);
        }

        display();

        fclose(fl);
    }

    printf("\n\nThank you.\nYour marks:  %d\n\n", marks);

    hm=fopen("marks.txt","r");
    fscanf(hm, "%s%d",&nm,&sc);

    if (marks>sc)
    {
        fclose(hm);
        hm=fopen("marks.txt","w");
        fprintf(hm,"%s\n%d",name,marks);
        fclose(hm);
        printf("\n    Congratulation..... You are the High scorer.\n\n");
    }
    else
    {
        printf("High Scorer : %s\n\nHigh Score: %d\n\n", nm, sc);
        fclose(hm);
    }
}
