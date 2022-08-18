## my_printf  

A reimplementation of the printf() function in C

## Description  

The my_printf() function produces output according to a format, as described below. The my_printf() functions writes output to stdout  

This function writes the output under the control of a format string that specifies how subsequent arguments (or arguments accessed via the variable-length argument facilities of stdarg(3)) are converted for output.  

The format string is composed of zero or more directives: ordinary characters (which don't include "%"), which are copied unchanged to the output stream, and conversion specifications, each of which results in fetching zero or more subsequent arguments.  

Each conversion specification is introduced by the percentage character. The arguments must correspond properly (after type promotion) with the conversion specifier. After the percentage, the following appear in sequence:  

    d, o, u, x The int (or appropriate variant) argument is converted to signed decimal (d). unsigned octal (o), unsigned decimal (u), unsigned hexadecimal (x).  
    
    c The int argument is converted to an unsigned char, and the resulting character is written.  
    
    s The char * argument is expected to be a pointer to an array of character type (pointer to a string). Characters from the array are written up to (but not including) a terminating NUL character.  
    
    p The void * pointer argument is printed in hexadecimal.  

## Authorized function(s)  

  write(2)  
  malloc  
  free  
  va_start, va_arg, va_copy, va_end  
    
## (Obvious) unauthorized functions  

printf and co. (fprintf, sprintf, snprintf, asprintf, dprintf, vprintf, vfprintf, vsprintf, vsnprintf, vasprintf, vdprintf)  

## Requirements  

Your code must be compiled with the flags -Wall -Wextra -Werror -g3 -fsanitize=address

## Usage

Go to the main.c file in the src/ directory, and try giving it different options among the ones available:  
	
    %d - decimal  
    %o - octal  
    %u - unsigned decimal  
    %x - hexadecimal  
    %c - character  
    %s - string  
    %p - void pointer  

run "make" :)  
then ./my_printf  
you can clean up using "make clean"  

Enjoy!
