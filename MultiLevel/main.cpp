#include <iostream>
#include <stdlib.h>


class Weapon {
private:
	int damage;
	int rate_of_fire;
	int ammo;
public:
	Weapon(int ammo, int damage, int rate_of_fire) 
		: ammo{ ammo }, rate_of_fire{ rate_of_fire }, damage{ damage } {}

	void shoot() {
		--ammo;
	}

	int getAmmo() {
		return ammo;
	}
};


class Inventory {
private:
	int selectedWeapon;
	Weapon* primaryWeapon;
	Weapon* secondaryWeapon;
	int grenadecount;
public:
	Inventory() : selectedWeapon{ 0 }, grenadecount{ 2 } {
		primaryWeapon = new Weapon(50,1,30);
		secondaryWeapon = new Weapon(50, 5, 90);
	}

	~Inventory() {
		delete primaryWeapon;
		delete secondaryWeapon;
	}

	void switchWeapon() {
		selectedWeapon = selectedWeapon == 0 ? 1 : 0;
	}

	void fire_one_shot() {
		if (selectedWeapon == 0) {
			primaryWeapon->shoot();
		}
		else {
			secondaryWeapon->shoot();
		}
	}

	void throwGrenade() {
		--grenadecount;
	}

	int getSelected() {
		return selectedWeapon;
	}

	int getGrenade() {
		return grenadecount;
	}

	int getAmmo() {
		if (selectedWeapon == 0) {
			return primaryWeapon->getAmmo();
		}
		else {
			return secondaryWeapon->getAmmo();
		}
	}

};

class Player {
private:
	int mana;
	int health;
	Inventory* inventory;
public:
	Player(int health = 100, int mana = 100) : mana{ mana }, health{health
	} {
		inventory = new Inventory();
	}

	~Player() {
		delete inventory;
	}
	int getMana() {
		return this->mana;
	}

	int getHealth() {
		return this->health;
	}

	void castSpell() {
		this->mana -= 5;
	}

	void applyDamage(int damage) {
		this->health -= damage;
	}

	void switchWeapon() {
		inventory->switchWeapon();
	}

	void fire_one_shot() {
		inventory->fire_one_shot();
	}

	void throwGrenade() {
		inventory->throwGrenade();
	}

	void printInfo() {
		std::cout
			<< "\n\n\n------------------PLAYER-----------------"
			<< "\nMANA: " << mana
			<< "\nHEALTH: " << health
			<< "\nGRENADE: " << inventory->getGrenade()
			<< "\nSELECT WEAPON: "
			<< ((inventory->getSelected() == 0) ? "PRIMARY" : "SECONDARY")
			<< "\nAMMO: " << inventory->getAmmo()
			<< "\n----------------------------------------------" << std::endl;
	}

};


int main() {

	static Player* myPlayer = new Player();
	while (myPlayer->getMana() < 200 && myPlayer->getHealth() < 200)
	{
		myPlayer->printInfo();
		std::cout << "1 - FIRE WEAPON | 2 - SWITCH WEAPON | 3 - THROW GRENADE | 4 - CAST SPELL | 5 - HIT YOURSELF" << std::endl;
		std::cout << "SELECT: ";
		int selection;
		std::cin >> selection;
		switch (selection)
		{
		case 1:
			myPlayer->fire_one_shot();
			std::cout << "YOU FIRED YOUR WEAPON!" << std::endl;
			break;
		case 2:
			myPlayer->switchWeapon();
			std::cout << "YOU SWITCHED YOUR WEAPON!" << std::endl;
			break;
		case 3:
			myPlayer->throwGrenade();
			std::cout << "YOU HAVE TRHOWN A GRENADE!" << std::endl;
			break;
		case 4:
			myPlayer->castSpell();
			std::cout << "YOU DID CAST A SPELL!" << std::endl;
			break;
		case 5:
			myPlayer->applyDamage(5);
			std::cout << "STOP HITTING YOURSELF!" << std::endl;
			break;
		}
	}

	delete myPlayer;
	std::cout << "You have made it!" << std::endl;
	system("pause");
	return 0;
}