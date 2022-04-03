#include "libft.h"

int main(){
    char *number = "-a12";
    puts("ft_atoi");
    printf("%d\n", ft_atoi(number));

    char str[] = "12345";
    puts("-----");
    puts("ft_bzero");

    ft_bzero(&str, 2);
    printf("0 %d\n", str[0]);
    printf("0 %d\n", str[1]);
    printf("51 %d\n", str[2]);
    printf("52 %d\n", str[3]);
    printf("53 %d\n", str[4]);

    puts("-----");
    puts("ascii");

    int c = 127;
    printf("alfa_num %d\n", ft_isalnum(c));
    printf("ascii %d\n", ft_isascii(c));
    printf("print %d\n", ft_isprint(c));
    printf("space %d\n", ft_isspace(c));

    puts("-----");
    puts("ft_memcpy");

    char dest[10];

    ft_memcpy(&dest[0], &str[2], 4);
    printf("0 %d\n", str[0]);
    printf("0 %d\n", str[1]);
    printf("51 %d\n", str[2]);
    printf("52 %d\n", str[3]);
    printf("53 %d\n", str[4]);

    puts("-----");
    puts("ft_strdup");

    char string[4] = "abcd";
    char *p_str = &string[0];

    char *string2 = "1234567";

    puts(ft_strdup(p_str));
    puts(ft_strdup(string2));

    puts("-----");
    puts("ft_substr");

    char *original = "abcdef";
    puts(ft_substr(original, 2, 3));

    puts("-----");
    puts("ft_strjoin");

    char *first = "abcdef";
    char *second = "ghij";
    puts(ft_strjoin(first, second));

	puts("-----");
    puts("ft_strtrim");

	char *str_trim = "abcdab";
	char *str_to_find = "ab";

	puts(ft_strtrim(str_trim, str_to_find));
	
	puts("-----");
    puts("ft_split");

	char const *split = "a1a11a11a";
	char a = 97;
	char **array;
	int i = 0;

	array = ft_split(split, a);
	while(array[i]){
		printf("array%d %s\n",i, array[i]);
		i++;
	}

	puts("-----");
    puts("ft_itoa");
	
	puts(ft_itoa(-1230));

	puts("-----");
    puts("write");
	ft_putchar_fd(97, 1);
	puts ("\n");
	ft_putendl_fd("abc\n", 1);
	ft_putstr_fd("aaa\n", 1);
}