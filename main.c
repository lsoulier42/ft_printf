/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louise <lsoulier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 19:23:29 by louise            #+#    #+#             */
/*   Updated: 2020/11/17 13:15:21 by louise           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include "libft/libft.h"
#include <stdio.h>
#include <locale.h>
#include <wchar.h>

void	print_check(int rl, int ft)
{
	printf("Real printf: %d - ft_printf: %d ", rl, ft);
	if (rl == ft)
		printf("\xE2\x9C\x85\n");
	else
		printf("\xE2\x9D\x8C\n");
}

void	print_yellow(char *str)
{
	printf("\033[33;01m%s:\033[32;01m\n", str);
}

void	print_blue(char *str)
{
	printf("\033[34;01m%s:\033[32;01m\n", str);
}

void	test_first_tests(void)
{
	char c = 'a';
	char *ptr = &c;
	int	ret_rl;
	int	ret_ft;
	unsigned int supermax = 2147483664;

	print_blue("Premiers tests");
	ret_rl = printf("test %.*s - %09d - %p - %c\n - %i - %-30u - %x - %X - %% \n", 2, "bla", 14, ptr, c, 16, supermax, supermax, supermax);
	ret_ft = ft_printf("test %.*s - %09d - %p - %c\n - %i - %-30u - %x - %X - %% \n", 2, "bla", 14, ptr, c, 16, supermax, supermax, supermax);
	print_check(ret_rl, ret_ft);
}

void	test_char_unit(char *fmt, char c)
{
	int ret_rl;
	int ret_ft;

	ret_rl = printf(fmt, c);
	ret_ft = ft_printf(fmt, c);
	print_check(ret_rl, ret_ft);
}

void	test_chars(void)
{
	int	ret_rl;
	int	ret_ft;
	char *str;

	print_blue("\nDeuxieme test - les chars");
	///////test du format vide
	print_yellow("Chaine vide sans parametre");
	ret_rl = printf("");
	ret_ft = ft_printf("");
	print_check(ret_rl, ret_ft);
	//////test pour un char
	print_yellow("Chaine avec modulo(c), char 0");
	test_char_unit("|%c|\n", (char)0);
	print_yellow("Chaine avec 5modulo(c), char 0");
	test_char_unit("|%5c|\n", (char)0);
	print_yellow("Chaine avec (moins)5modulo(c), char 0");
	test_char_unit("|%-5c|\n", (char)0);
	print_yellow("Chaine avec espace puis modulo(c), char 0");
	test_char_unit("| %c|\n", (char)0);
	print_yellow("Chaine avec 34modulo(c), char 0");
	test_char_unit("|%34c|\n", (char)0);
	print_yellow("Chaine avec moins32modulo(c), char 0");
	test_char_unit("|%-32c|\n", (char)0);
	print_yellow("Chaine avec modulo(c), char 155");
	test_char_unit("|%c|\n", (char)155);
	print_yellow("Chaine avec modulo(c), char -19");
	test_char_unit("|%c|\n", (char)-19);
	print_yellow("Chaine avec modulo(c), char 55");
	test_char_unit("|%c|\n", (char)55);
	print_yellow("Chaine avec modulo(c), char 988");
	test_char_unit("|%c|\n", (char)988);
	print_yellow("Chaine avec 54modulo(c), char 99");
	test_char_unit("|%54c|\n", (char)99);
	////tests char et etoile
	print_yellow("Chaine etoilemodulo(c), int 0, char 0");
	str = "|%*c|\n";
	ret_rl = printf(str, 0, (char)0);
	ret_ft = ft_printf(str, 0, (char)0);
	print_check(ret_rl, ret_ft);
	print_yellow("Chaine etoilemodulo(c), int 50, char 0");
	str = "|%*c|\n";
	ret_rl = printf(str, 50, (char)0);
	ret_ft = ft_printf(str, 50, (char)0);
	print_check(ret_rl, ret_ft);
	print_yellow("Chaine etoilemodulo(c), int 50, char 66");
	str = "|%*c|\n";
	ret_rl = printf(str, 50, (char)66);
	ret_ft = ft_printf(str, 50, (char)66);
	print_check(ret_rl, ret_ft);
	print_yellow("Chaine etoilemodulo(c), int -33, char 66");
	str = "|%*c|\n";
	ret_rl = printf(str, -33, (char)66);
	ret_ft = ft_printf(str, -33, (char)66);
	print_check(ret_rl, ret_ft);
	print_yellow("Chaine etoilemodulo(c), int -33, char 66");
	str = "|%*c|\n";
	ret_rl = printf(str, -33, (char)66);
	ret_ft = ft_printf(str, -33, (char)66);
	print_check(ret_rl, ret_ft);
	print_yellow("Chaine etoilemodulo(c) etoilemodulo(c), int -33, char 66, int 88, c78");
	str = "|%*c%*c|\n";
	ret_rl = printf(str, -33, (char)66, 88, (char)78);
	ret_ft = ft_printf(str, -33, (char)66, 88, (char)78);
	print_check(ret_rl, ret_ft);
	// test avec modulo(lc)
	print_yellow("Chaine avec modulo(lc), int 536");
	str = "|%lc|\n";
	setlocale(LC_ALL, "");
	ret_rl = printf(str, (wint_t)536);
	ret_ft = ft_printf(str, 536);
	print_check(ret_rl, ret_ft);
}

void	test_str_unit(char *fmt, char *str)
{
	int ret_rl;
	int ret_ft;

	ret_rl = printf(fmt, str);
	ret_ft = ft_printf(fmt, str);
	print_check(ret_rl, ret_ft);
}

void	test_strs(void)
{
	int	ret_rl;
	int	ret_ft;
	char *str1;
	char *str2;
	int d;
	int strunicode[5];

	print_blue("\nTroisieme test - les str");
	//unit test avec un seul argument
	print_yellow("Chaine modulo(s) avec str vide");
	test_str_unit("|%s|\n", "");
	print_yellow("Chaine modulo(s) avec str (Batman)");
	test_str_unit("|%s|\n", "Batman");
	print_yellow("Chaine 50modulo(s) avec str (Batman)");
	test_str_unit("|%50s|\n", "Batman");
	print_yellow("Chaine 5modulo(s) avec str (Batman)");
	test_str_unit("|%5s|\n", "Batman");
	print_yellow("Chaine 5modulo(s) avec str vide");
	test_str_unit("|%5s|\n", "");
	print_yellow("Chaine point2modulo(s) avec str (Batman)");
	test_str_unit("|%.2s|\n", "Batman");
	print_yellow("Chaine point19modulo(s) avec str (Batman)");
	test_str_unit("|%.19s|\n", "Batman");
	print_yellow("Chaine 4point2modulo(s) avec str (Batman)");
	test_str_unit("|%4.2s|\n", "Batman");
	print_yellow("Chaine 2point4modulo(s) avec str (Batman)");
	test_str_unit("|%2.4s|\n", "Batman");
	print_yellow("Chaine 55point19modulo(s) avec str (Batman)");
	test_str_unit("|%55.19s|\n", "Batman");
	print_yellow("Chaine 1point19modulo(s) avec str (Batman)");
	test_str_unit("|%1.19s|\n", "Batman");
	print_yellow("Chaine 1point19modulo(s) avec str vide");
	test_str_unit("|%1.19s|\n", "");
	print_yellow("Chaine moins17point19modulo(s) avec str (Batman)");
	test_str_unit("|%-17.19s|\n", "Batman");
	//unit test avec les etoiles
	print_yellow("Chaine point(etoile)modulo(s) avec int 5, str (Batman)");
	str1 = "|%.*s|\n";
	str2 = "Batman";
	d = 5;
	ret_rl = printf(str1, d, str2);
	ret_ft = ft_printf(str1, d, str2);
	print_check(ret_rl, ret_ft);
	print_yellow("Chaine point(etoile)modulo(s) avec int -125, str (Batman)");
	str1 = "|%.*s|\n";
	str2 = "Batman";
	d = -125;
	ret_rl = printf(str1, d, str2);
	ret_ft = ft_printf(str1, d, str2);
	print_check(ret_rl, ret_ft);
	print_yellow("Chaine (etoile)point(etoile)modulo(s) avec int -12, int 25, str (Batman)");
	str1 = "|%*.*s|\n";
	str2 = "Batman";
	d = -12;
	ret_rl = printf(str1, d, 25, str2);
	ret_ft = ft_printf(str1, d, 25, str2);
	print_check(ret_rl, ret_ft);
	//Test avec str NULL
	print_yellow("Chaine modulo(s) avec str NULL");
	test_str_unit("%s\n", NULL);
	print_yellow("Chaine 18modulo(s) avec str NULL");
	test_str_unit("%18s\n", NULL);
	print_yellow("Chaine this is a modulo(s) string! avec str NULL");
	test_str_unit("This is a %s string !\n", NULL);
	//test avec modulo(ls)
	print_yellow("Chaine modulo(ls) avec un caractere unicode");
	str1 = "|%ls|\n";
	setlocale(LC_ALL, "");
	strunicode[0] = 233;
	strunicode[1] = 'l';
	strunicode[2] = 233;
	strunicode[3] = 'p';
	strunicode[4] = '\0';
	ret_rl = printf(str1, strunicode);
	ret_ft = ft_printf(str1, strunicode);
	print_check(ret_rl, ret_ft);
}

void	test_ptr_unit(char *fmt, void *ptr)
{
	int ret_rl;
	int ret_ft;

	ret_rl = printf(fmt, ptr);
	ret_ft = ft_printf(fmt, ptr);
	print_check(ret_rl, ret_ft);
}

void	test_ptrs(void)
{
	int	ret_rl;
	int	ret_ft;
	char *str = "Batman";

	print_blue("\nQuatrieme test - les pointeurs");
	////////unit test avec un seul argument
	print_yellow("Chaine avec modulo(p), pointeur d'une str (Batman)");
	test_ptr_unit("|%p|\n", str);
	print_yellow("Chaine avec modulo(p), pointeur d'un int*");
	test_ptr_unit("|%p|\n", &ret_ft);
	print_yellow("Chaine avec modulo(p), pointeur NULL");
	test_ptr_unit("|%p|\n", NULL);
	print_yellow("Chaine avec 22modulo(p), pointeur d'une str (Batman)");
	test_ptr_unit("|%22p|\n", str);
	print_yellow("Chaine avec (moins)22modulo(p), pointeur d'une str (Batman)");
	test_ptr_unit("|%-22p|\n", str);
	print_yellow("Chaine avec (moins)3modulo(p), pointeur d'une str (Batman)");
	test_ptr_unit("|%-3p|\n", str);
	print_yellow("Chaine avec (moins)3(point)7modulo(p), pointeur d'une str (Batman)");
	test_ptr_unit("|%-3.7p|\n", str);
	print_yellow("Chaine avec (moins)3(point)90modulo(p), pointeur d'une str (Batman)");
	test_ptr_unit("|%-3.90p|\n", str);
	//////unit test avec etoiles
	print_yellow("Chaine avec (etoile)modulo(p), int 14, pointeur d'une str (Batman)");
	ret_rl = printf("|%*p|\n", 14, str);
	ret_ft = ft_printf("|%*p|\n", 14, str);
	print_check(ret_rl, ret_ft);
	print_yellow("Chaine avec (etoile)modulo(p), int -14, pointeur d'une str (Batman)");
	ret_rl = printf("|%*p|\n", -14, str);
	ret_ft = ft_printf("|%*p|\n", -14, str);
	print_check(ret_rl, ret_ft);
	print_yellow("Chaine avec moins(etoile)modulo(p), int -14, pointeur d'une str (Batman)");
	ret_rl = printf("|%-*p|\n", 14, str);
	ret_ft = ft_printf("|%-*p|\n", 14, str);
	print_check(ret_rl, ret_ft);
	print_yellow("Chaine avec moins(etoile)modulo(p), int -14, pointeur d'une str (Batman)");
	ret_rl = printf("|%-*p|\n", -14, str);
	ret_ft = ft_printf("|%-*p|\n", -14, str);
	print_check(ret_rl, ret_ft);
}

void test_int_unit(char *fmt, int d)
{
	int ret_rl;
	int ret_ft;

	ret_rl = printf(fmt, d);
	ret_ft = ft_printf(fmt, d);
	print_check(ret_rl, ret_ft);
}

void	test_ints(void)
{
	int	ret_rl;
	int	ret_ft;
	char *str;
	long long int min_val;
	long long int max_val;

	print_blue("\nCinquieme test - les int");
	////////////unit test avec un argument
	print_yellow("Chaine modulo(d) avec int 14");
	test_int_unit("|%d|\n", 14);
	print_yellow("Chaine modulo(d) avec int -41679");
	test_int_unit("|%d|\n", -41679);
	print_yellow("Chaine modulo(d) avec int -2147483648");
	test_int_unit("|%d|\n", -2147483648);
	print_yellow("Chaine modulo(d) avec int 2147483647");
	test_int_unit("|%d|\n", 2147483647);
	print_yellow("Chaine 33modulo(d) avec int 8367");
	test_int_unit("|%33d|\n", 8367);
	print_yellow("Chaine moins21modulo(d) avec int 8367");
	test_int_unit("|%-21d|\n", 8367);
	print_yellow("Chaine 0moins21modulo(d) avec int 8367");
	test_int_unit("|%0-21d|\n", 8367);
	print_yellow("Chaine moins(zero)21modulo(d) avec int 8367");
	test_int_unit("|%-021d|\n", 8367);
	print_yellow("Chaine (zero)21modulo(d) avec int 8367");
	test_int_unit("|%021d|\n", 8367);
	print_yellow("Chaine point44modulo(d) avec int 8367");
	test_int_unit("|%.44d|\n", 8367);
	print_yellow("Chaine 66point44modulo(d) avec int 8367");
	test_int_unit("|%66.44d|\n", 8367);
	print_yellow("Chaine zero66point44modulo(d) avec int 8367");
	test_int_unit("|%066.44d|\n", 8367);
	print_yellow("Chaine (point)modulo(d) avec int 8367");
	test_int_unit("|%.d|\n", 8367);
	print_yellow("Chaine (moins)modulo(d) avec int 8367");
	test_int_unit("|%-d|\n", 8367);
	print_yellow("Chaine (zero)modulo(d) avec int 8367");
	test_int_unit("|%0d|\n", 8367);
	print_yellow("Chaine (zero)pointmodulo(d) avec int 8367");
	test_int_unit("|%0.d|\n", 8367);
	print_yellow("Chaine point(zero)modulo(d) avec int 8367");
	test_int_unit("|%.0d|\n", 8367);
	print_yellow("Chaine (zero)point(zero)modulo(d) avec int 8367");
	test_int_unit("|%0.0d|\n", 8367);
	print_yellow("Chaine moins(zero)point(zero)modulo(d) avec int 8367");
	test_int_unit("|%-0.0d|\n", 8367);
	print_yellow("Chaine moins(zero)point(zero)(moins)modulo(d) avec int 8367");
	test_int_unit("|%-0.-0d|\n", 8367);
	print_yellow("Chaine modulo(d) avec int 0");
	test_int_unit("|%d|\n", 0);
	print_yellow("Chaine 0modulo(d) avec int 0");
	test_int_unit("|%0d|\n", 0);
	print_yellow("Chaine point(0)modulo(d) avec int 0");
	test_int_unit("|%.0d|\n", 0);
	print_yellow("Chaine (point)modulo(d) avec int 0");
	test_int_unit("|%.d|\n", 0);
	print_yellow("Chaine 54(point)modulo(d) avec int 0");
	test_int_unit("|%54.d|\n", 0);
	print_yellow("Chaine 54modulo(d) avec int -23");
	test_int_unit("|%54d|\n", -23);
	print_yellow("Chaine (zero)54modulo(d) avec int -23");
	test_int_unit("|%054d|\n", -23);
	print_yellow("Chaine (point)54modulo(d) avec int -23");
	test_int_unit("|%.54d|\n", -23);
	///////unit test avec les arguments etoiles
	print_yellow("Chaine (etoile)modulo(d) avec int 0, int 8367");
	str = "|%*d|\n";
	ret_rl = printf(str, 0, 8367);
	ret_ft = ft_printf(str, 0, 8367);
	print_check(ret_rl, ret_ft);
	print_yellow("Chaine (etoile)modulo(d) avec int 88, int 8367");
	str = "|%*d|\n";
	ret_rl = printf(str, 88, 8367);
	ret_ft = ft_printf(str, 88, 8367);
	print_check(ret_rl, ret_ft);
	print_yellow("Chaine (etoile)modulo(d) avec int -12, int 8367");
	str = "|%*d|\n";
	ret_rl = printf(str, -12, 8367);
	ret_ft = ft_printf(str, -12, 8367);
	print_check(ret_rl, ret_ft);
	print_yellow("Chaine (etoile)point.modulo(d) avec int -12, int 8367");
	str = "|%*.d|\n";
	ret_rl = printf(str, -12, 8367);
	ret_ft = ft_printf(str, -12, 8367);
	print_yellow("Chaine (etoile)point(etoile)modulo(d) avec int -12, int 55, int 8367");
	str = "|%*.*d|\n";
	ret_rl = printf(str, -12, 55, 8367);
	ret_ft = ft_printf(str, -12, 55, 8367);
	print_check(ret_rl, ret_ft);
	print_yellow("Chaine (etoile)point(etoile)modulo(d) avec int -12, int -55, int 8367");
	str = "|%*.*d|\n";
	ret_rl = printf(str, -12, -55, 8367);
	ret_ft = ft_printf(str, -12, -55, 8367);
	print_check(ret_rl, ret_ft);
	print_yellow("Chaine (etoile)point(etoile)modulo(d) avec int -12, int 0, int 8367");
	str = "|%*.*d|\n";
	ret_rl = printf(str, -12, 0, 8367);
	ret_ft = ft_printf(str, -12, 0, 8367);
	print_check(ret_rl, ret_ft);
	print_yellow("Chaine (etoile)point(etoile)modulo(d) avec int 0, int 0, int 8367");
	str = "|%*.*d|\n";
	ret_rl = printf(str, 0, 0, 8367);
	ret_ft = ft_printf(str, 0, 0, 8367);
	print_check(ret_rl, ret_ft);
	print_yellow("Chaine (etoile)point(etoile)modulo(d) avec int 0, int 88, int 8367");
	str = "|%*.*d|\n";
	ret_rl = printf(str, 0, 88, 8367);
	ret_ft = ft_printf(str, 0, 88, 8367);
	print_check(ret_rl, ret_ft);
	print_yellow("Chaine point(etoile)modulo(d) avec int 0, int 0");
	str = "|%.*d|\n";
	ret_rl = printf(str, 0, 0);
	ret_ft = ft_printf(str, 0, 0);
	print_check(ret_rl, ret_ft);
	print_yellow("Chaine (etoile)modulo(d) avec int 0, int 0");
	str = "|%*d|\n";
	ret_rl = printf(str, 0, 0);
	ret_ft = ft_printf(str, 0, 0);
	print_check(ret_rl, ret_ft);
	//test avec les long long int
	print_yellow("Chaine modulo(lld) avec 9223372036854775807");
	str = "|%lld|\n";
	max_val = 9223372036854775807;
	ret_rl = printf(str, max_val);
	ret_ft = ft_printf(str, max_val);
	print_check(ret_rl, ret_ft);
	print_yellow("Chaine (plus)modulo(lld) avec 9223372036854775807");
	str = "|%+lld|\n";
	max_val = 9223372036854775807;
	ret_rl = printf(str, max_val);
	ret_ft = ft_printf(str, max_val);
	print_yellow("Chaine (plus)80modulo(lld) avec 9223372036854775807");
	str = "|%+80lld|\n";
	max_val = 9223372036854775807;
	ret_rl = printf(str, max_val);
	ret_ft = ft_printf(str, max_val);
	print_yellow("Chaine (space)80modulo(lld) avec 9223372036854775807");
	str = "|% .80lld|\n";
	max_val = 9223372036854775807;
	ret_rl = printf(str, max_val);
	ret_ft = ft_printf(str, max_val);
	print_check(ret_rl, ret_ft);
	print_yellow("Chaine (space)80modulo(lld) avec 9223372036854775807");
	str = "|% 080lld|\n";
	max_val = 9223372036854775807;
	ret_rl = printf(str, max_val);
	ret_ft = ft_printf(str, max_val);
	print_check(ret_rl, ret_ft);
	print_yellow("Chaine modulo(lld) avec -9223372036854775808");
	str = "|%lld|\n";
	min_val = -9223372036854775807 - 1;
	ret_rl = printf(str, min_val);
	ret_ft = ft_printf(str, min_val);
	print_check(ret_rl, ret_ft);
}

void test_uint_unit(char *fmt, unsigned int u)
{
	int ret_rl;
	int ret_ft;

	ret_rl = printf(fmt, u);
	ret_ft = ft_printf(fmt, u);
	print_check(ret_rl, ret_ft);
}

void test_uints(void)
{
	char *str;
	int ret_rl;
	int ret_ft;
	unsigned long long int llud = 9223372036854775807;
	llud *= 2;

	print_blue("\nSizieme test - les unsigned int");
	////////////unit test avec un argument
	print_yellow("Chaine modulo(u) avec arg 14");
	test_uint_unit("|%u|\n", 14);
	print_yellow("Chaine modulo(u) avec arg -41679");
	test_uint_unit("|%u|\n", (unsigned int)-41679);
	print_yellow("Chaine 77modulo(u) avec arg -41679");
	test_uint_unit("|%77u|\n", (unsigned int)-41679);
	print_yellow("Chaine point77modulo(u) avec arg -41679");
	test_uint_unit("|%.77u|\n", (unsigned int)-41679);
	print_yellow("Chaine zero77modulo(u) avec arg -41679");
	test_uint_unit("|%077u|\n", (unsigned int)-41679);
	print_yellow("Chaine 77(point)6modulo(u) avec arg -41679");
	test_uint_unit("|%77.60u|\n", (unsigned int)-41679);
	//test avec les unsigned long long int
	print_yellow("Chaine modulo(llu) avec 18446744073709551614");
	str = "|%llu|\n";
	ret_rl = printf(str, llud);
	ret_ft = ft_printf(str, llud);
	print_check(ret_rl, ret_ft);
}

void test_hexint_unit(char *fmt, unsigned int u)
{
	int ret_rl;
	int ret_ft;

	ret_rl = printf(fmt, u);
	ret_ft = ft_printf(fmt, u);
	print_check(ret_rl, ret_ft);
}

void test_hexints(void)
{
	int ret_rl;
	int ret_ft;

	print_blue("\nSeptieme test - les int en hexa");
	////////////unit test avec un argument
	print_yellow("Chaine modulo(x) avec arg 14");
	test_uint_unit("|%x|\n", 14);
	print_yellow("Chaine modulo(x) avec arg -41679");
	test_uint_unit("|%x|\n", (unsigned int)-41679);
	print_yellow("Chaine 77modulo(x) avec arg -41679");
	test_uint_unit("|%77x|\n", (unsigned int)-41679);
	print_yellow("Chaine point77modulo(x) avec arg -41679");
	test_uint_unit("|%.77x|\n", (unsigned int)-41679);
	print_yellow("Chaine zero77modulo(x) avec arg -41679");
	test_uint_unit("|%077x|\n", (unsigned int)-41679);
	print_yellow("Chaine 77(point)6modulo(x) avec arg -41679");
	test_uint_unit("|%77.60x|\n", (unsigned int)-41679);
	print_yellow("Chaine (padding)77(point)6modulo(x) avec arg -41679");
	test_uint_unit("|%#77.60x|\n", (unsigned int)-41679);
	print_yellow("Chaine (padding)77(point)6modulo(X) avec arg -41679");
	test_uint_unit("|%#77.60X|\n", (unsigned int)-41679);
	print_yellow("Chaine (padding)zero(10)modulo(x) | (padding)zero(10)modulo(X) avec 42 et 42");
	ret_rl = printf("|%#010x | %#010X|\n", 42, 42);
	ret_ft = ft_printf("|%#010x | %#010X|\n", 42, 42);
	print_check(ret_rl, ret_ft);
	print_yellow("Chaine (padding)zero(10)point(6)modulo(x) | (padding)zero(10)point(6)modulo(X) | (padding)zero(10)point(vide)modulo(x) avec 42, 42 et 0");
	ret_rl = printf("|%#010.6x | %#010.6X | %#010.X|\n", 42, 42, 0);
	ret_ft = ft_printf("|%#010.6x | %#010.6X | %#010.X|\n", 42, 42, 0);
	print_check(ret_rl, ret_ft);
}

void	test_nspec_unit(char *fmt)
{
	int ret_rl;
	int ret_ft;
	int val = 0;
	int	*val_ptr = &val;

	ret_rl = printf(fmt, val_ptr);
	printf("value real : %d\n", val);
	val = 0;
	ret_ft = ft_printf(fmt, val_ptr);
	printf("value mine : %d\n", val);
	print_check(ret_rl, ret_ft);
}

void	test_nspec(void)
{
	int ret_rl;
	int ret_ft;
	long int val = 0;
	long int	*val_ptr = &val;
	char *fmt;

	print_blue("\nHuitieme test - le specifier modulo(n)");
	////////////unit test
	print_yellow("Chaine \"blabla modulo(n)\"");
	test_nspec_unit("blabla %n\n");
	print_yellow("Chaine \"blabla modulo(n) blabla \"");
	test_nspec_unit("|blabla %n blabla|\n");
	print_yellow("Chaine \"bla (space)modulo(n)bla\"");
	test_nspec_unit("|bla% nbla|\n");
	print_yellow("Chaine \"bla (space)modulo(n)bla\"");
	test_nspec_unit("|bla%+nbla|\n");
	print_yellow("Chaine \"blabla modulo(ln) blabla \"");
	fmt = "iajfidsfjia %lngdfsfsgdfgs\n";
	ret_rl = printf(fmt, val_ptr);
	printf("value real : %ld\n", val);
	val = 0;
	ret_ft = ft_printf(fmt, val_ptr);
	printf("value mine : %ld\n", val);
	print_check(ret_rl, ret_ft);


}

void 	test_flags(void)
{
	int ret_rl;
	int ret_ft;
	char *fmt;
	print_blue("\nNeuvieme test : tests specifiques des flags\n");
	print_yellow("Chaine avec des plus\n");
	fmt = "%+5.5d %+.d %+5u %+.3x\n";
	ret_rl = printf(fmt, 6, 0, 42, 42);
	ret_ft = ft_printf(fmt, 6, 0, 42, 42);
	print_check(ret_rl, ret_ft);
	print_yellow("Chaine avec des espaces\n");
	fmt = "\"% 5.5d % .d % 5u % .3x\"\n";
	ret_rl = printf(fmt, 6, 0, 42, 42);
	ret_ft = ft_printf(fmt, 6, 0, 42, 42);
	print_check(ret_rl, ret_ft);
	print_yellow("Chaine avec des plus et des espaces\n");
	fmt = "% +5.5d % +.d % +5u % +.3x\n";
	ret_rl = printf(fmt, 6, 0, 42, 42);
	ret_ft = ft_printf(fmt, 6, 0, 42, 42);
	print_check(ret_rl, ret_ft);
	print_yellow("Chaine avec precision 0\n");
	fmt = "|%.1d|\n";
	ret_rl = printf(fmt, 0);
	ret_ft = ft_printf(fmt, 0);
	print_check(ret_rl, ret_ft);
	print_yellow("Chaine avec (zero)etoile-Modulo(d), int -8, int -43\n");
	fmt = "|%0*d|\n";
	ret_rl = printf(fmt, -8, -43);
	ret_ft = ft_printf(fmt, -8, -43);
	print_check(ret_rl, ret_ft);
	print_yellow("Chaine avec (diese)3modulo(x), int 0\n");
	fmt = "|%#3x|\n";
	ret_rl = printf(fmt, 0);
	ret_ft = ft_printf(fmt, 0);
	print_check(ret_rl, ret_ft);
	print_yellow("Chaine avec (espace)plus(zero)modulo(d), int 455\n");
	fmt = "|% +05d|\n";
	ret_rl = printf(fmt, 455);
	ret_ft = ft_printf(fmt, 455);
	print_check(ret_rl, ret_ft);
	print_yellow("Chaine avec (zero)plus(zero)4modulo(d), int 18\n");
	fmt = "|%0+04d|\n";
	ret_rl = printf(fmt, 18);
	ret_ft = ft_printf(fmt, 18);
	print_check(ret_rl, ret_ft);
	print_yellow("Chaine avec (zero)etoile(point)etoile(modulo-d), int 4, int -4, int 8\n");
	fmt = "|%0*.*d|\n";
	ret_rl = printf(fmt, 4, -4, 18);
	ret_ft = ft_printf(fmt, 4, -4, 18);
	print_check(ret_rl, ret_ft);
	print_yellow("Chaine avec (zero)etoile(point)etoile(modulo-d), int -2, int -4, int 8\n");
	fmt = "|%0*.*d|\n";
	ret_rl = printf(fmt, -2, -2, 8);
	ret_ft = ft_printf(fmt, -2, -2, 8);
	print_check(ret_rl, ret_ft);
	print_yellow("Chaine avec modulo(null)\n");
	fmt = "|%10w|\n";
	ret_rl = printf(fmt, NULL);
	ret_ft = ft_printf(fmt, NULL);
	print_check(ret_rl, ret_ft);
}

int main()
{
	test_first_tests();
	test_chars();
	test_strs();
	test_ptrs();
	test_ints();
	test_uints();
	test_hexints();
	test_nspec();
	test_flags();
	
	return (0);
}
