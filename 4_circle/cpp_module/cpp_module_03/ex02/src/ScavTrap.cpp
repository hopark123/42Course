# include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) : ClapTrap() {
	this->Hit_Points = 100;
	this->Energy_Points = 50;
	this->Attack_Damages = 20;
	std::cout << "ScavTrap : " << "Default constructor called" << std::endl;
}

ScavTrap::ScavTrap(const std::string name_) : ClapTrap(name_) {
	this->name = name_;
	this->Hit_Points = 100;
	this->Energy_Points = 50;
	this->Attack_Damages = 20;
	std::cout << "ScavTrap : " << this->name << " constructor called" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap &other){
	*this = other;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other){
	this->name = other.name;
	this->Hit_Points = other.Hit_Points;
	this->Energy_Points = other.Energy_Points;
	this->Attack_Damages = other.Attack_Damages;
	std::cout << "ScavTrap : " << this->name << " Assignation Constructor called" << std::endl;
	return (*this);
}

ScavTrap::~ScavTrap(void){
	std::cout << "ScavTrap : " << "Destructor called" << std::endl;
}

void	ScavTrap::attack(std::string const &target){
	std::cout << "ScavTrap : " << this->name << " attacks " << target << ", causing " << this->Attack_Damages << " points of damage!" << std::endl;
}

void ScavTrap::guardGate(){
	std::cout << "ScavTrap : Gate keeper mode!" << std::endl;
}