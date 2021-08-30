#include <iostream>
#include <fstream>
#include <string>

static	std::string		ft_replace(std::string str, std::string s1, std::string s2)
{
	std::string::size_type	pos = 0;

	while ((pos = str.find(s1)) != std::string::npos)
	{
		str.erase(pos, s1.length());
		str.insert(pos, s2);
		pos += s2.length();
	}
	return (str);
}

int main(int ac, char *av[])
{
	if (ac != 4)
	{
		std::cout << "wrong input" << std::endl;
		return (1);
	}
	
	std::string	filename = av[1];
	std::string	s1 = av[2];
	std::string	s2 = av[3];
	std::ifstream	readFile(filename.c_str());

	if (!readFile.is_open())
	{
		std::cout << "file open failed" << std::endl;
		return (1);
	}
	std::ofstream	outFile(filename.append(".replace").c_str());
	if (!outFile.is_open())
	{
		std::cout << "file open failed" << std::endl;
		return (1);
	}
	while (!readFile.eof())
	{
		std::string	line;
		std::getline(readFile, line);
		outFile << ft_replace(line, s1, s2);
		if (!readFile.eof())
			outFile << std::endl;
	}
	readFile.close();
	outFile.close();
	return (0);
}