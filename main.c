#include "libft_printf.h"

int main()
{
    char *p = NULL;
     int i1 =   printf("our:%1.6s|",p);printf("\n");
    int i2 = ft_printf(" my:%1.6s|",p);printf("\n");
     printf("%d\t",i1);
    printf("%d\n",i2);
}
