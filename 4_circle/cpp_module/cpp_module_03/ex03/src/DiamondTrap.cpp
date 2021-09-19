# include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("Default_clap_name"), ScavTrap("Default_clap_name"), FragTrap("Default_clap_name"){
	std::cout << "DiamondTrap : " << "Default constructor called" << std::endl;
	this->name = "Default";
	this->Hit_Points = FragTrap::Hit_Points;
	this->Energy_Points = ScavTrap::Energy_Points;
	this->Attack_Damages = FragTrap::Attack_Damages;
}

DiamondTrap::DiamondTrap(std::string const &name_) : ClapTrap(name_ + "_clap_name"), ScavTrap(name_ + "_clap_name"), FragTrap(name_ + "_clap_name"){
	this->name = name_;
	this->Hit_Points = FragTrap::Hit_Points;
	this->Energy_Points = ScavTrap::Energy_Points;
	this->Attack_Damages = FragTrap::Attack_Damages;
	std::cout << "DiamondTrap : " << this->name << " Constructor called"  << std::endl;
}

DiamondTrap::DiamondTrap(DiamondTrap &other){
	*this = other;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other){
	this->name = other.name;
	this->Hit_Points = other.Hit_Points;
	this->Energy_Points = other.Energy_Points;
	this->Attack_Damages = other.Attack_Damages;
	std::cout << "DiamondTrap : " << this->name << " Assignation Constructor called" << std::endl;
	return (*this);
}

DiamondTrap::~DiamondTrap(void){
	std::cout << "DiamondTrap : " << "Destructor called" << std::endl;
}

void	DiamondTrap::whoAmI(void){
	std::cout << "My name is " << this->name << " && ClapTrap name is " << ClapTrap::getName() << std::endl;
}