#include "../include/my_printf.h"

int my_strlen(const char* s) {
    if(s == NULL) return -1;
    int i = 0;
    while(s[i] != '\0')
        i++;
    return i;
}

void print_char(char c){
    write(1, &c, 1);
}

int absolute(int n){
    return (unsigned) (n < 0) ? -n : n;
}

void rev_string(char *begin, char *end){
    char aux;
      
    while(end>begin)
        aux=*end, *end--=*begin, *begin++=aux;
}

char* my_strcpy(char* dst, char* src){
    for(int i=0;i<my_strlen(src);i++){
        dst[i] = src[i];
    }
    return dst;
}

char handle_hex(int n){
    if(n >= 0 && n < 10) return '0' + n;
    else return 'a' + n - 10;
}

void print_pointer(void *p){
    uintptr_t p1 = (uintptr_t) p;

    print_char('0');
    print_char('x');
    for(int i=(sizeof(p) << 3)-4; i>=0; i-=4)
        print_char(handle_hex((p1 >> i) & 0xf));
}

char *my_itoa(int value, char *str, int base){
    static char chars[] = "0123456789abcdefghijklmnopqrstuvwxyz";
    char *wstr = str;
    int sign;

    if((sign=value) < 0) 
        value = -value;

    do{
        *wstr++ = chars[value % base];
    }while(value /= base);
    
    if(sign < 0) *wstr++ = '-';
    *wstr = '\0';
    rev_string(str, wstr-1);
    return wstr;
}
	
int my_printf(char * restrict format, ...){
    va_list ap;
    va_start(ap, format);
    //int args = 0;
    int ret = 0;
    char *str_arg;//, void *pointer;
    //char *buffer;
    char buffer[100] = {0}, tmp[20];

    //for(int j=0;j<my_strlen(format);j++) if(format[j] == '%') args += 1;

    //buffer = malloc(my_strlen(format) + args);

    for(int i=0;i<my_strlen(format);i++){
        if(format[i] == '%'){
            i += 1;
            if(format[i] == 'c'){
                buffer[ret] = (char)va_arg(ap, int);
                ret++;
            }else if(format[i] == 'd'){
                my_itoa(va_arg(ap, int), tmp, 10);
                my_strcpy(&buffer[ret], tmp);
                ret += my_strlen(tmp);
            }else if(format[i] == 's'){
                str_arg = va_arg(ap, char *);
                my_strcpy(&buffer[ret], str_arg);
                ret += my_strlen(str_arg);
            }else if(format[i] == 'o'){
                my_itoa(va_arg(ap, int), tmp, 8);
                my_strcpy(&buffer[ret], tmp);
                ret += my_strlen(tmp);
            }else if(format[i] == 'u'){
                my_itoa(absolute(va_arg(ap, int)), tmp, 10);
                my_strcpy(&buffer[ret], tmp);
                ret += my_strlen(tmp);
            }else if(format[i] == 'x'){
                my_itoa(va_arg(ap, int), tmp, 16);
                my_strcpy(&buffer[ret], tmp);
                ret += my_strlen(tmp);
            }else if(format[i] == 'p'){
                print_pointer(va_arg(ap, char *));
                my_strcpy(&buffer[ret], tmp);
                ret += my_strlen(tmp);
            }else break;
        }else{
            buffer[ret] = format[i];
            ret++;
        }
    }
    buffer[my_strlen(buffer)] = '\0';

    write(1, &buffer, my_strlen(buffer));
    va_end(ap);
    //free(buffer);
    return ret; 
}
