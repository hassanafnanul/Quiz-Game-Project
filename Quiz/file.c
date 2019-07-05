#include<stdio.h>

main()
{
    char str[100];
    FILE *fl1;

    fl1 = fopen("My File.txt", "a");
    fprintf(fl1, "Assalamualaikum\nHow are You, guyz.... :)");
    fclose(fl1);

    fl1 = fopen("My File.txt", "r");
    fscanf(fl1, "%s", &str);
    printf("%s", str);
    fclose(fl1);
}
