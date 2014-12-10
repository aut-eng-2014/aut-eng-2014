#include <stdio.h>
#include <stdlib.h>
#include<string.h>
char *sInsert( char *d, const char *s, int p, int n) {
if(p>strlen(d))

    return d;
    memmove(d+p+strlen (s), d+p, strlen(d)-p+1);
    strncpy(d+p,s,strlen(s));
    return d;

}


int main()
{

    char sir1[20], sir2[20];
    int n,p;
    printf("Introduceti pozitia de inceput");
    scanf("%d", &p);

    printf("Introduceti numarul de caractere:");
    scanf("%d", &n);

    printf("Introduceti sir1: ");
    scanf("%s", sir1);

   printf("Introduceti sir2: ");
    scanf("%s", sir2);

    printf("Sir obtinut este %s ", sInsert(sir2,sir1,p,n));
}
