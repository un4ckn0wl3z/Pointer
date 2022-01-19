#include <iostream>

int globalMana = 100;

int main(){

	static int staticHealth = 100;
	while (globalMana < 200 && staticHealth < 200)
	{
		std::cout << "Mana: " << globalMana << std::endl;
		std::cout << "Health: " << staticHealth << std::endl;
		int damage;
		std::cin >> damage;
		staticHealth -= damage;
		globalMana -= 5;
	}
	std::cout << "You have made it!"<< std::endl;
	system("pause");
	return 0;
}