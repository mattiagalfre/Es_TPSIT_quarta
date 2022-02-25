#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define LUNG1 50
#define LUNG2 100

/*Concatenare due stringhe senza strcat*/

void cat(char * s1, char *s2)
{
    int n1=strlen(s1);
    int n2=strlen(s2);
    for(int k=0; k< n2; k++)
    {
        *(s1+n1+k)= *(s2+k);
    }
    *(s1+n1+n2)='\0';
}

int main()
{

    char * s1 = (char *) malloc (LUNG2 * sizeof(char));
    char * s2 = (char *) malloc (LUNG1 * sizeof(char));
    printf("Dammi la prima stringa: ");
    scanf("%s", s1);
    printf("Dammi la seconda stringa: ");
    scanf("%s", s2);
    cat(s1, s2);
    printf("Nuova stringa: %s", s1);

    return 0;
}
