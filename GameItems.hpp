#pragma once
#include <string>
#include <iostream>
using namespace std;
class Item {
protected:
	int Damage;//Damage of the weapon
	std::string Type;//Type of item (In case it was armour)
	bool Equipped;//Finding what's equipped in an inventory list.
public:
	std::string Name;
	//Setters
	void SetEquipped(bool i) {
		Equipped = i;
	}
	//Getters
	bool ReturnEquipped() { return Equipped; }
	int ReturnDamage() { return Damage; }

	void OutputStats() {
		std::cout << Name << std::endl;
		std::cout << "Damage: "<< Damage << std::endl;
	}
};
class Fist : public Item {
public:
	Fist() {
		//std::cout << "Fist Added" << std::endl;
		Damage = 1;
		Name = "Fist";
		Equipped = true;
	}
	~Fist() {
		std::cout << "Fist Removed" << std::endl;
	}
};

class Sword : public Item {
public:
	Sword() {//Constructor
		//std::cout << "Sword Added" << std::endl;
		Damage = 5;//Set Damage
		Name = "Sword";//Set Name
		//Equipped = true;
	}
	~Sword() {//std::cout << "Sword Removed" << std::endl;
	}//Destructor
};

class Staff : public Item {
public:
	Staff() {
		//std::cout << "Staff Added" << std::endl;
		Damage = 3;//Set Damage
		Name = "Staff";//Set Name
		//Equipped = true;
	}
	~Staff() {
		//std::cout << "Staff Removed" << std::endl;
	}
};

class Knife : public Item {
public:
	Knife() {
		//std::cout << "Knife Added" << std::endl;
		Damage = 3;//Set Damage
		Name = "Knife";//Set Name
		//Equipped = true;
	}
	~Knife() {
		//std::cout << "Knife Removed" << std::endl;
	}
};

class PowerSword : public Item {
public:
	PowerSword() {
		cout << "You have found a Power Sword" << endl;//Loot object message
		Damage = 10;//Set Damage
		Name = "Power Sword";//Set Name
		//Equipped = true;
	}
	~PowerSword() {}
};

class Stick : public Item {
public:
	Stick() {
		cout << "You have found a Stick" << endl;//Loot object message
		Damage = 3;//Set Damage
		Name = "Stick";//Set Name
		//Equipped = true;
	}
	~Stick() {}
};

class Club : public Item {
public:
	Club() {
		cout << "You have found a Club" << endl;//Loot object message
		Damage = 6;//Set Damage
		Name = "Club";//Set Name
		//Equipped = true;
	}
	~Club() {}
};



class EnemySword : public Item {
public:
	EnemySword() {
		//std::cout << "Rusty Sword Added" << std::endl;
		Damage = 2;//Set Damage
		Name = "Rusty Sword";//Set Name
		Equipped = true;
	}
	~EnemySword() {
		//std::cout << "Rusty Sword Removed" << std::endl;
	}
};//Nerfed Item for Enemy

class EnemyBow : public Item {
public:
	EnemyBow() {
		//std::cout << "Bow Added" << std::endl;
		Damage = 2;//Set Damage
		Name = "Bow";//Set Name
		Equipped = true;
	}
	~EnemyBow() {
		//std::cout << "Bow Removed" << std::endl;
	}
};//Nerfed Item for Enemy

class EnemyAxe : public Item {
public:
	EnemyAxe() {
		//std::cout << "Rusty Axe Added" << std::endl;
		Damage = 3;//Set Damage
		Name = "Rusty Axe";//Set Name
		Equipped = true;
	}
	~EnemyAxe() {
		//std::cout << "Rusty Axe Removed" << std::endl;
	}
};//Nerfed Item for Enemy