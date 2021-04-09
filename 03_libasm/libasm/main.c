
#include "libasm.h"

void	test_strdup(void)
{
	printf("\n\n=-=-=-=-=- Tests strdup -=-=-=-=-=\n");
	printf("%s\n", strdup("test"));
	printf("%s\n", ft_strdup("test"));
	printf("---------------------------\n");
	printf("%s\n", strdup(""));
	printf("%s\n", ft_strdup(""));
	printf("---------------------------\n");
	printf("%s\n", strdup("123 456 789       oui"));
	printf("%s\n", ft_strdup("123 456 789       oui"));
	printf("---------------------------\n");
	printf("%s\n", strdup("	oui		\n"));
	printf("%s\n", ft_strdup("	oui		\n"));
	printf("---------------------------\n");
	printf("%s\n", strdup("\0"));
	printf("%s\n", ft_strdup("\0"));
}

void	test_read(void)
{
	int		fd;
	char	*buff;
	char	*buff2;
	int		ret;

	buff = malloc(sizeof(char) * 1000);
	buff2 = malloc(sizeof(char) * 1000);
	printf("\n\n=-=-=-=-=- Tests read -=-=-=-=-=\n");
	fd = open("./ft_strlen.s", O_RDONLY);
	ret = read(fd, buff, 500);
	if (ret == -1)
		printf("%s", strerror(errno));
	printf("%s\n", buff);
	close(fd);
	fd = 0;
	ret = 0;
	printf("---------------------------\n");
	fd = open("./ft_strlen.s", O_RDONLY);
	ret = ft_read(fd, buff2, 500);
	if (ret == -1)
		printf("%s", strerror(errno));
	printf("%s", buff2);
	close(fd);
	free(buff);
	free(buff2);
}

void	test_write(void)
{
	ft_write(0, "=-=-=-=-=- Tests write -=-=-=-=-=\n", 34);
	write(1, "test\n", 5);
	ft_write(1, "test\n", 5);
	ft_write(1, "---------------------------\n", 28);
	write(0, "test 0 fd\n", 10);
	ft_write(0, "test 0 fd\n", 10);
	ft_write(0, "---------------------------\n", 28);
	write(1, "\n", 1);
	ft_write(1, "\n", 1);
	ft_write(1, "---------------------------\n", 28);
	write(1, "\n", 0);
	ft_write(1, "\n", 0);
	ft_write(1, "---------------------------\n", 28);
	write(100, "\n", 1);
	ft_write(100, "\n", 1);
}

void	test_strcmp(void)
{
	printf("\n\n=-=-=-=-=- Tests strcmp -=-=-=-=-=\n");
	printf("%d\n", strcmp("test", "tes"));
	printf("%d\n", ft_strcmp("test", "tes"));
	printf("---------------------------\n");
	printf("%d\n", strcmp("tes", "test"));
	printf("%d\n", ft_strcmp("tes", "test"));
	printf("---------------------------\n");
	printf("%d\n", strcmp("oui", "oui"));
	printf("%d\n", ft_strcmp("oui", "oui"));
	printf("---------------------------\n");
	printf("%d\n", strcmp("", ""));
	printf("%d\n", ft_strcmp("", ""));
	printf("---------------------------\n");
	printf("%d\n", strcmp("12345", "1234"));
	printf("%d\n", ft_strcmp("12345", "1234"));
}

void	test_strcpy(void)
{
	char dst[100];

	printf("\n\n=-=-=-=-=- Tests strcpy -=-=-=-=-=\n");
	printf("%s\n", strcpy(dst, "sample text"));
	printf("%s\n", ft_strcpy(dst, "sample text"));
	printf("---------------------------\n");
	printf("%s\n", strcpy(dst, "Oui 123"));
	printf("%s\n", ft_strcpy(dst, "Oui 123"));
	printf("---------------------------\n");
	printf("%s\n", strcpy(dst, "\noui"));
	printf("%s\n", ft_strcpy(dst, "\noui"));
}

void	test_strlen(void)
{
	printf("\n\n=-=-=-=-=- Tests strlen -=-=-=-=-=\n");
	printf("%d\n", (int)strlen("TEST"));
	printf("%d\n", (int)ft_strlen("TEST"));
	printf("---------------------------\n");
	printf("%d\n", (int)strlen("La reponses est 18"));
	printf("%d\n", (int)ft_strlen("La reponses est 18"));
	printf("---------------------------\n");
	printf("%d\n", (int)strlen("\0"));
	printf("%d\n", (int)ft_strlen("\0"));
}

int		main(void)
{
	test_strlen();
	test_strcpy();
	test_strcmp();
	test_write();
	test_read();
	test_strdup();
}

