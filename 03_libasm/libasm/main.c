
#include "libasm.h"

void	test_strdup(void)
{
	printf("\n\n@@@@@@@@@@@@@@@@@- Tests strdup -@@@@@@@@@@@@@@@@@\n\n");
	printf("--------------------------------------\n");
	printf("|test|\n");
	printf("|%s|\n", strdup("test"));
	printf("|%s|\n", ft_strdup("test"));
	printf("--------------------------------------\n");
	printf("||\n");
	printf("|%s|\n", strdup(""));
	printf("|%s|\n", ft_strdup(""));
	printf("--------------------------------------\n");
	printf("|123 456 789|\n");
	printf("|%s|\n", strdup("123 456 789"));
	printf("|%s|\n", ft_strdup("123 456 789"));
	printf("--------------------------------------\n");
	printf("\\0\n");
	printf("|%s|\n", strdup("\0"));
	printf("|%s|\n", ft_strdup("\0"));
	printf("--------------------------------------\n");

}

void	test_read(void)
{
	int		fd;
	char	*buff;
	char	*buff2;
	int		ret;
	char	*file = "./ft_strlen.s";
	buff = malloc(sizeof(char) * 1000);
	buff2 = malloc(sizeof(char) * 1000);
	printf("\n@@@@@@@@@@@@@@@@@- Tests read -@@@@@@@@@@@@@@@@@\n\n");
	printf("--------------------------------------\n");
	printf("file name : %s\n", file);
	printf("--------------------------------------\n");
	fd = open(file, O_RDONLY);
	ret = read(fd, buff, 500);
	if (ret == -1)
		printf("%s", strerror(errno));
	printf("%s\n", buff);
	close(fd);
	fd = 0;
	ret = 0;
	printf("--------------------------------------\n");
	fd = open(file, O_RDONLY);
	ret = ft_read(fd, buff2, 500);
	if (ret == -1)
		printf("%s", strerror(errno));
	printf("%s\n", buff2);
	close(fd);
	free(buff);
	free(buff2);
	printf("--------------------------------------\n");
}

void	test_write(void)
{
	ft_write(0, "@@@@@@@@@@@@@@@@@- Tests write -@@@@@@@@@@@@@@@@@\n\n", 52);
	printf("--------------------------------------\n");
	write(1, "|test|\n", 7);
	ft_write(1, "|test|\n", 7);
	ft_write(1, "---------------------------\n", 28);
	write(0, "|test 0 fd|\n", 12);
	ft_write(0, "|test 0 fd|\n", 12);
	ft_write(0, "---------------------------\n", 28);
	printf("--------------------------------------\n");

}

void	test_strcmp(void)
{
	printf("\n@@@@@@@@@@@@@@@@@- Tests strcmp -@@@@@@@@@@@@@@@@@\n\n");
	printf("--------------------------------------\n");
	printf("|test|testa|\n");
	printf("%d\n", strcmp("test", "testa"));
	printf("%d\n", ft_strcmp("test", "testa"));
	printf("--------------------------------------\n");
	printf("|testa|test|\n");
	printf("|%d|\n", strcmp("testa", "test"));
	printf("|%d|\n", ft_strcmp("testa", "test"));
	printf("--------------------------------------\n");
	printf("|test|test|\n");
	printf("|%d|\n", strcmp("test", "test"));
	printf("|%d|\n", ft_strcmp("test", "test"));
	printf("--------------------------------------\n");
	printf("| | |\n");
	printf("|%d|\n", strcmp("", ""));
	printf("|%d|\n", ft_strcmp("", ""));
	printf("--------------------------------------\n");
	printf("|\\xff|\\xff|\n");
	printf("|%d|\n", strcmp("\xff", "\xff"));
	printf("|%d|\n", ft_strcmp("\xff", "\xff"));
	printf("--------------------------------------\n");


}

void	test_strcpy(void)
{
	char dst[100];

	printf("\n@@@@@@@@@@@@@@@@@- Tests strcpy -@@@@@@@@@@@@@@@@@\n\n");
	printf("|test|\n");
	printf("|%s|\n", strcpy(dst, "test"));
	printf("|%s|\n", ft_strcpy(dst, "test"));
	printf("--------------------------------------\n");
	printf("|abc123|\n");
	printf("|%s|\n", strcpy(dst, "abc123"));
	printf("|%s|\n", ft_strcpy(dst, "abc123"));
	printf("--------------------------------------\n");
	printf("\\n\n");
	printf("|%s|\n", strcpy(dst, "\n"));
	printf("|%s|\n", ft_strcpy(dst, "\n"));
	printf("--------------------------------------\n");

}

void	test_strlen(void)
{
	printf("\n\n@@@@@@@@@@@@@@@@@- Tests strlen -@@@@@@@@@@@@@@@@@\n\n");
	printf("--------------------------------------\n");
	printf("|test|\n");
	printf("|%d|\n", (int)strlen("test"));
	printf("|%d|\n", (int)ft_strlen("test"));
	printf("--------------------------------------\n");
	printf("|12345abc|\n");
	printf("|%d|\n", (int)strlen("12345abc"));
	printf("|%d|\n", (int)ft_strlen("12345abc"));
	printf("--------------------------------------\n");
	printf("|\\0|\n");
	printf("|%d|\n", (int)strlen("\0"));
	printf("|%d|\n", (int)ft_strlen("\0"));
	printf("--------------------------------------\n");

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

