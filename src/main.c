#include "../include/my_printf.h"

//main function, already has some options
int main(void){
    my_printf("hello world\n");
    my_printf("hello %s\n", "world");
    my_printf("%d\n", 1000);
    my_printf("%x\n", 10);
    my_printf("%u\n", -345);
    my_printf("%o\n", 100); 
    my_printf("%c, %c, %c, %c, %c", 'h', 'e', 'l', 'l', 'o');
   	my_printf("\n");
    
    return 0;
}
