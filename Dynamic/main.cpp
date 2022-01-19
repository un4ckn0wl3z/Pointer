#include <iostream>


class Player {
private:
	int mana;
	int health;

public:
	Player(int health = 100, int mana = 100) : mana{ mana }, health{ health } {}

	int getMana()
	{
		return this->mana;
	}

	int getHealth()
	{
		return this->health;
	}

	void castSpell()
	{
		this->mana -= 5;
	}

	void applyDamage(int damage)
	{
		this->health -= damage;
	}

};




int main() {

	static Player* myPlayer = new Player();
	while (myPlayer->getMana() < 200 && myPlayer->getHealth() < 200)
	{
		std::cout << "Mana: " << myPlayer->getMana() << std::endl;
		std::cout << "Health: " << myPlayer->getHealth() << std::endl;
		int damage;
		std::cin >> damage;
		myPlayer->applyDamage(damage);
		myPlayer->castSpell();
	}

	delete myPlayer;
	std::cout << "You have made it!" << std::endl;
	system("pause");
	return 0;
}