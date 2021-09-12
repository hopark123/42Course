# include "FragTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap(){
	Hit_Points = 100;
	Energy_Points = 100;
	Attack_Damages = 30;
	std::cout << "FragTrap : " << "Default constructor called" << std::endl;
}

FragTrap::FragTrap(const std::string name_) : ClapTrap(name_) {
	name = name_;
	Hit_Points = 100;
	Energy_Points = 100;
	Attack_Damages = 30;
	std::cout << "FragTrap : " << this->name << " constructor called" << std::endl;
}

FragTrap::FragTrap(FragTrap &other){
	*this = other;
}

FragTrap &FragTrap::operator=(const FragTrap &other){
	this->name = other.name;
	this->Hit_Points = other.Hit_Points;
	this->Energy_Points = other.Energy_Points;
	this->Attack_Damages = other.Attack_Damages;
	std::cout << "FragTrap : " << this->name << " Assignation Constructor called" << std::endl;
	return (*this);
}

FragTrap::~FragTrap(void){
	std::cout << "FragTrap : " << "Destructor called" << std::endl;
}

void FragTrap::highFivesGuys(){
	std::cout << "FragTrap : highFivesGuys" << std::endl;
}