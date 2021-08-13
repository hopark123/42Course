#include "phonebook.hpp"

void	Contact::add(void)
{
	std::cout << "/-------------------------------------------\\\n";
	std::cout << "first name : ";
	std::getline(std::cin, first_name);
	std::cout << "last name : ";
	std::getline(std::cin, last_name);
	std::cout << "nickname : ";
	std::getline(std::cin, nickname);
	std::cout << "phone number : ";
	std::getline(std::cin, phone_number);
	std::cout << "darkest secret : ";
	std::getline(std::cin, darkest_secret);
	std::cout << "\\-------------------------------------------/" << std::endl;
	std::cout << "SUCCESS!" << std::endl;

}

void	Contact::del(void)
{
	first_name = "";
	last_name = "";
	nickname = "";
	phone_number = "";
	darkest_secret = "";
}

static std::string	get_short(std::string str)
{
	std::string	new_str;
	
	new_str = "";
	if (str.length() <= 10)
	{
		for (int i = 0; i < 10 - (int)str.length(); i++)
			new_str += ' ';
		new_str += str + '|';
	}
	else
		new_str += str.substr(0, 9) + ".|";
	return (new_str);
}

void	Contact::print(void)
{
	std::cout << "/-------------------------------------------\\\n";
	std::cout << "first name : ";
	std::cout << first_name << '\n';
	std::cout << "last name : ";
	std::cout << last_name << '\n';
	std::cout << "nickname : ";
	std::cout << nickname << '\n';
	std::cout << "phone number : ";
	std::cout << phone_number << '\n';
	std::cout << "darkest secret : ";
	std::cout << darkest_secret << std::endl;
	std::cout << "\\-------------------------------------------/" << std::endl;
}

void	Contact::print_short(int index)
{
	std::cout << "|         " << index << '|' << get_short(first_name) << get_short(last_name) << get_short(nickname) << "\n";
}

static void	ft_search(Contact *data, int cnt)
{
	if (cnt < 1)
	{
		std::cout << "Empty" << std::endl;
		return ;
	}
	std::cout << "/-------------------------------------------\\\n";
	std::cout << "|     index|first name| last name|  nickname|\n";
	std::cout << "|----------+----------+----------+----------|\n";
	for (int i = 0; i < cnt && i < 8; i++)
		data[i].print_short(i);
	std::cout << "\\----------+----------+----------+----------/" << std::endl;

	int		index;
	int		res;

	index = 0;
	res = 1;
	while (res)
	{
		std::cout << "Search by Index : ";
		std::cin >> index;
		if (std::cin.eof() || !std::cin || index >= cnt || index >= 8)
			std::cout << "Wrong index \n";
		else if (index < cnt)
		{
			data[index].print();
			res = 0;
		}
		std::cin.clear();
		std::cin.ignore(256, '\n');
	}
}

int	main(int ac, char *av[])
{
	std::string	cmd;
	Contact		data[8];
	int			index;
	int			cnt;

	(void)ac;
	(void)av;
	index = 0;
	cnt = 0;
	std::cout << "* WELCOME_MY_AWESOME_PHONE_BOOK *" << std::endl;
	while (!std::cin.eof())
	{
		std::cout << "Please Insert Command (ADD, SEARCH or EXIT) : ";
		std::getline(std::cin, cmd);
		if (!cmd.compare("ADD"))
		{
			if (cnt >= 8)
			{
				std::cout << "Data Is Full. Oldest Data Is Delete" << std::endl;
				index = 0;
			}
			cnt++;
			data[index].del();
			data[index++].add();
		}
		else if (!cmd.compare("SEARCH"))
			ft_search(data, cnt);
		else if (!cmd.compare("EXIT"))
			break ;
	}
}