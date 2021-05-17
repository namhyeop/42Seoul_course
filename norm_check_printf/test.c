
#include<stdio.h>
#include "ft_printf_header.h"


int main()
{
	ft_printf("%-50c\n",'a');
	ft_printf("[%8.6d]\n",1234);
	ft_printf("%d\n", '9' & 15);
	ft_printf("%d\n", '8' & 15 );
	ft_printf("%.c\n",'B');
	ft_printf("%5d\n",-12345);
	//printf("%%");
	//printf("%-050s", "a sibal jo ga tae");
	//printf("%s\n", "end");
	//마인
}
