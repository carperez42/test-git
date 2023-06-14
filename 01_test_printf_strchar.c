#include "header/ft_printf.h"
#include <string.h>

void	ft_leaks()
{
	system("leaks a.out");
}

int	main()
{
	atexit(ft_leaks);
    int lon = 0;
	char letra = 90;
	ft_printf("******************01_test_printf_strchar************************\n");
	ft_printf("\n");
	printf("*************************(x<=z y<=z)*******************************\n");
    printf("(p-01) original printf	  |%%c|      :	|%c|	BASE->z (x=0 y=0)\n", letra);
	ft_printf("(p-01) personal ft_printf |%%c|      :	|%c|	BASE->z (x=0 y=0)\n", letra);
	printf("(p-02) original printf	  |%%-c|     :	|%-c|	BASE->z (x=0 y=0)\n", letra);
	ft_printf("(p-02) personal ft_printf |%%-c|     :	|%-c|	BASE->z (x=0 y=0)\n", letra);
	printf("(p-03) original printf	  |%%1c|     :	|%1c|	BASE->z (0<x<=z y=0)\n", letra);
	ft_printf("(p-03) personal ft_printf |%%1c|     :	|%1c|	BASE->z (0<x<=z y=0)\n", letra);
	printf("(p-04) original printf	  |%%-1c|    :	|%-1c|	BASE->z (0<x<=z y=0)\n", letra);
	ft_printf("(p-04) personal ft_printf |%%-1c|    :	|%-1c|	BASE->z (0<x<=z y=0)\n", letra);
	printf("*************************(x > z >= y)*******************************\n");
	printf("(p-05) original printf	  |%%5c|     :	|%5c|	BASE->x (x>z y=0)\n", letra);
	ft_printf("(p-05) personal ft_printf |%%5c|     :	|%5c|	BASE->x (x>z y=0)\n", letra);
    printf("(p-06) original printf	  |%%-5c|    :	|%-5c|	BASE->x (x>z y=0)\n", letra);
	ft_printf("(p-06) personal ft_printf |%%-5c|    :	|%-5c|	BASE->x (x>z y=0)\n", letra);
    printf("*********************************************************************\n");
    printf("\n");
	printf("*************************(ESPECIAL)*******************************\n");
	printf("(p-05) original printf	  |%%5c|     :	|%5c|	valor 0 \n", 0);
	ft_printf("(p-05) personal ft_printf |%%5c|     :	|%5c|	valor 0\n", 0);
    printf("(p-06) original printf	  |%%-5c|    :	|%-5c|	valor 0\n", 0);
	ft_printf("(p-06) personal ft_printf |%%-5c|    :	|%-5c|	valor 0\n", 0);
	printf("(p-08) original printf	  |%%5%%|     :	|%5%|\n");
	ft_printf("(p-08) personal ft_printf |%%5%%|     :	|%5%|\n");
    printf("(p-09) original printf	  |%%-5%%|    :	|%-5%|\n");
	ft_printf("(p-09) personal ft_printf |%%-5%%|    :	|%-5%|\n");	
    printf("*********************************************************************\n");
    printf("\n");
	printf("*************************LONGITUDES**********************************\n");
	printf("'%%c %%c %%c' de 0, '1', '2' es: |");
	lon = printf("%c %c %c", '0', 0, 1593940224);
	printf("| --> Longitud original printf: %d\n", lon);
	ft_printf("'%%c %%c %%c' de 0, '1', '2' es: |");
	lon = ft_printf("%c %c %c", '0', 0, 1593940224);
	ft_printf("| --> Longitud personal ft_printf: %d\n", lon);
	printf("'{%%3c}' de 0 es: |");
	lon = printf("{%3c}", 0);
	printf("| --> Longitud original printf: %d\n", lon);
	ft_printf("'{%%3c}' de 0 es: |");
	lon = ft_printf("{%3c}", 0);
	ft_printf("| --> Longitud personal ft_printf: %d\n", lon);  
	printf("*********************************************************************\n");	
    printf("\n");
	printf("*************************CASOS DE ERROR******************************\n");
	printf("CASO 1): '%%0c'\n");
	ft_printf("ERROR 1): |?%0c||\n", 90);
	printf("\nCASO 2): '%%+c'\n");
	ft_printf("ERROR 2): |?%+c|\n", 90);
	printf("\nCASO 3): '%% c'\n");
	ft_printf("ERROR 3): |?% c|\n", 90);
	printf("\nCASO 4): '%%#c'\n");
	ft_printf("ERROR 4): |?%#c|\n", 90);
	printf("\nCASO 5): '%%.c'\n");
	ft_printf("ERROR 5): |%.c|\n", 90);
	printf("\n");
	printf("*********************************************************************\n");
	ft_printf("\n");
	printf("*************************(x<=z y<=z)*******************************\n");
    printf("(s-01) original printf	  |%%s|        :	|%s|	BASE->z (x=0 y=0)\n", "12345");
	ft_printf("(s-01) personal ft_printf |%%s|        :	|%s|	BASE->z (x=0 y=0)\n", "12345");
	printf("(s-02) original printf	  |%%-s|       :	|%-s|	BASE->z (x=0 y=0)\n", "12345");
	ft_printf("(s-02) personal ft_printf |%%-s|       :	|%-s|	BASE->z (x=0 y=0)\n", "12345");
	printf("(s-03) original printf	  |%%1.1s|     :	|%1.1s|	BASE->y (x<z y<z)\n", "12345");
	ft_printf("(s-03) personal ft_printf |%%1.1s|     :	|%1.1s|	BASE->y (x<z y<z)\n", "12345");
	printf("(s-04) original printf	  |%%-1.1s|    :	|%-1.1s|	BASE->y (x<z y<z)\n", "12345");
	ft_printf("(s-04) personal ft_printf |%%-1.1s|    :	|%-1.1s|	BASE->y (x<z y<z)\n", "12345");
	printf("(s-05) original printf	  |%%5.5s|     :	|%5.5s|	BASE->y (x=z y=z)\n", "12345");
	ft_printf("(s-05) personal ft_printf |%%5.5s|     :	|%5.5s|	BASE->y (x=z y=z)\n", "12345");
	printf("********************************************************************\n"); 	
	ft_printf("\n");
	printf("*************************(x<=y z<y)*********************************\n"); 
	printf("(s-06) original printf	  |%%5.8s|      :	|%5.8s|	BASE->y (0<x<=z z<y))\n", "12345");
	ft_printf("(s-06) personal ft_printf |%%5.8s|      :	|%5.8s|	BASE->y (0<x<=z z<y))\n", "12345");
	printf("(s-07) original printf	  |%%-5.8s|     :	|%-5.8s|	BASE->y (0<x<=z z<y))\n", "12345");
	ft_printf("(s-07) personal ft_printf |%%-5.8s|     :	|%-5.8s|	BASE->y (0<x<=z z<y))\n", "12345");
    printf("********************************************************************\n");
    printf("(s-08) original printf	  |%%10.15s|    :	|%10.15s|   BASE->x (0<x<=y z<y)\n", "12345");  
	ft_printf("(s-08) personal ft_printf |%%10.15s|    :	|%10.15s|   BASE->x (0<x<=y z<y)\n", "12345");
    printf("(s-09) original printf	  |%%-10.15s|   :	|%10.15s|   BASE->x (0<x<=y z<y)\n", "12345");  
	ft_printf("(s-09) personal ft_printf |%%-10.15s|   :	|%10.15s|   BASE->x (0<x<=y z<y)\n", "12345");  
	printf("********************************************************************\n");
	printf("\n");																			
	printf("*************************(x > z >= y)*******************************\n"); 
    printf("(s-10) original printf	  |%%10s|       :	|%10s|	BASE->x (x>z y=0)\n", "12345");
	ft_printf("(s-10) personal ft_printf |%%10s|       :	|%10s|	BASE->x (x>z y=0)\n", "12345");
	printf("(s-11) original printf	  |%%-10s|      :	|%-10s|	BASE->x (x>z y=0)\n", "12345");
	ft_printf("(s-11) personal ft_printf |%%-10s|      :	|%-10s|	BASE->x (x>z y=0)\n", "12345");
    printf("(s-12) original printf	  |%%10.s|      :	|%10.s|	BASE->x (x>z y=0)\n", "12345");
	ft_printf("(s-12) personal ft_printf |%%10.s|      :	|%10.s|	BASE->x (x>z y=0)\n", "12345");
	printf("(s-13) original printf	  |%%-10.s|     :	|%-10.s|	BASE->x (x>z y=0)\n", "12345");
	ft_printf("(s-13) personal ft_printf |%%-10.s|     :	|%-10.s|	BASE->x (x>z y=0)\n", "12345");
    printf("*********************************************************************\n");
    printf("(s-12) original printf	  |%%10.3s|      :	|%10.3s|	BASE->x (x>z 0<y<z)\n", "12345");
	ft_printf("(s-12) personal ft_printf |%%10.3s|      :	|%10.3s|	BASE->x (x>z 0<y<z)\n", "12345");
	printf("(s-13) original printf	  |%%-10.3s|     :	|%-10.3s|	BASE->x (x>z 0<y<z)\n", "12345");
	ft_printf("(s-13) personal ft_printf |%%-10.3s|     :	|%-10.3s|	BASE->x (x>z 0<y<z)\n", "12345");	
    printf("*********************************************************************\n");
	printf("\n");
	printf("*************************(x > y > z)*********************************\n");
    printf("(s-12) original printf	  |%%7.7s|      :	|%7.7s|	BASE->x (x>z x=y)\n", "12345");
	ft_printf("(s-12) personal ft_printf |%%7.7s|      :	|%7.7s|	BASE->x (x>z x=y)\n", "12345");
	printf("(s-13) original printf	  |%%-7.7s|     :	|%-7.7s|	BASE->x (x>z x=y)\n", "12345");
	ft_printf("(s-13) personal ft_printf |%%-7.7s|     :	|%-7.7s|	BASE->x (x>z x=y)\n", "12345");	
    printf("*********************************************************************\n");	
    printf("\n");
	printf("*************************(ESPECIAL)**********************************\n");
	printf("(s-14) original printf |%%.s| NULL	:	|%.s|\n", NULL);
	ft_printf("(s-14) personal ft_printf |%%.s| NULL	:	|%.s|\n", NULL);
	printf("(s-15) original printf |%%.3s| NULL	:	|%.3s|\n", NULL);
	ft_printf("(s-15) personal ft_printf |%%.3s| NULL	:	|%.3s|\n", NULL);
	printf("(s-16) original printf |%%6.3s| NULL	:	|%6.3s|\n", NULL);
	ft_printf("(s-16) personal ft_printf |%%6.3s| NULL	:	|%6.3s|\n", NULL);
	printf("(s-17) original printf |%%-6.3s| NULL	:	|%-6.3s|\n", NULL);
	ft_printf("(s-17) personal ft_printf |%%-6.3s| NULL :	|%-6.3s|\n", NULL);		
	printf("(s-18) original printf |%%.6s| NULL	:	|%.6s|\n", NULL);
	ft_printf("(s-18) personal ft_printf |%%.6s| NULL	:	|%.6s|\n", NULL);
	printf("(s-19) original printf |%%6.s| NULL	:	|%6.s|\n", NULL);
	ft_printf("(s-19) personal ft_printf |%%6.s| NULL	:	|%6.s|\n", NULL);
	printf("*********************************************************************\n");	
    printf("\n");
	printf("*************************LONGITUDES**********************************\n");
	printf("'%% 1s' de \"\" es: |");
	lon = printf("% 1s", "");
	printf("| --> Longitud original printf: %d\n", lon);
	ft_printf("'%% 1s' de \"\" es: |");
	lon = ft_printf("% 1s", "");
	ft_printf("| --> Longitud personal ft_printf: %d\n", lon);   
	printf("*********************************************************************\n");
    return (0);
}