#pragma once
#include <string>
#include <iostream>
#include "GameItems.hpp"

using namespace std;

class Entity {
protected://Protected Attributes to avoid being accessed unintentionally
	int Health;//Health of the Entity (Friendly or Enemy)
	int Speed;//If it starts first or second
	//int Damage;//How much damage it outputs //The Weapon has this stat, no long needed
	string AggressiveText="";//What the entity says when they attack
	string DefensiveText="";//What the entity says when they defend
public:
	Item EquippedItem;//What weapon they are holding
	std::string EntityName;//The name of the entity

	//Setter
	void SetEquipped(Item i) { EquippedItem = i;}
	void SetHealth(int i) {Health = i;}
	void SetSpeed(int i) { Speed = i; }
	//void SetDamage(int i) { Damage = i; }
	//Getter
	Item ReturnEquippedItem() { return EquippedItem; }
	int ReturnHealth() { return Health; }
	int ReturnSpeed() { return Speed; }
	//int ReturnDamage() { return Damage; }

	void OutputStats() {
		std::cout << EntityName << ": Health (" << ReturnHealth() << ")" << std::endl;//Outputs the amount of health of the Entity
		std::cout << EntityName << ": Speed (" << ReturnSpeed() << ")" << std::endl;//Outputs the amount of health of the Entity
	}
	bool CheckAlive() {
		if (Health < 1) {
			cout << EntityName<<": defeated!" << endl;
			return false;
		}
		return true;
	}
	virtual int Attack() {
		cout << EntityName << ": "<< AggressiveText << endl;//Outputting Aggressive text
		return EquippedItem.ReturnDamage();//Return damage of the weapon the character is holding
	}
	void TakeDamage(int i) {
		cout << EntityName << ": "<<DefensiveText << endl;//Outputting defensive text
		Health = Health - i;//Set health with an removed amount given in parameter.
	}
	void DisplayHealth() {
		cout << EntityName << ": Hit Points (" << Health << ")" << endl;//Displaying just the hit points.
	}
	void AddHealth(int i) {
		Health = Health + i;//Set health with an added amount given in parameter.
	}


};
class MainCharacter :public Entity {//Derived Class Main Character with added Option Attributes if the game was expanded.
public:
	Item Inventory[10];//If there were more Items could place in this list
	std::string PlayerName;//A character name that the user could set.
	void SetPlayerName(std::string i) { PlayerName = i; }
	MainCharacter() {//Setting some default aggressive and defensive texts for all "main character" classes.
		AggressiveText = "Attack!";
		DefensiveText = "Ugh!";
	}

};
class Warrior : public MainCharacter {
public:
	Warrior() {
		std::cout << "You've Selected Warrior" << std::endl;
		SetHealth(30);//High Health
		SetSpeed(1);
		Sword S = Sword();
		SetEquipped(S);
		EntityName = "Warrior";
		Inventory[0] = S;
		//std::cout << "Inventory Slot 0: " << Inventory[0].Name << std::endl;
		std::cout << "Health: " << ReturnHealth() << std::endl;
		std::cout << "Speed: " << ReturnSpeed() << std::endl;
		
	}
	~Warrior() {
		//std::cout << "Player Defeated" << std::endl;
	}
};
class Mage : public MainCharacter {
public:
	Mage() {
		std::cout << "You've Selected Mage" << std::endl;
		SetHealth(23);//Medium Health
		SetSpeed(1);

		Staff ST = Staff();
		SetEquipped(ST);
		EntityName = "Mage";
		Inventory[0] = ST;
		//std::cout << "Inventory Slot 0: " << Inventory[0].Name << std::endl;
		std::cout << "Health: " << ReturnHealth() << std::endl;
		std::cout << "Speed: " << ReturnSpeed() << std::endl;
	}
	~Mage() {
		//std::cout << "Player Defeated" << std::endl;
	}
};
class Thief : public MainCharacter {
public:
	Thief() {
		std::cout << "You've Selected Thief" << std::endl;
		SetHealth(20);//Low Health
		SetSpeed(3);

		Knife K = Knife();
		SetEquipped(K);
		EntityName = "Thief";
		Inventory[0] = K;
	}
	~Thief() {
		//std::cout << "Player Defeated" << std::endl;
	}
};


class Goblin :public  Entity {
public:
	Goblin() {
		std::cout << "You've Encountered A Goblin" << std::endl;
		SetHealth(12);//Low Health
		SetSpeed(2);
		EnemySword ES = EnemySword();
		SetEquipped(ES);
		EntityName = "Goblin";
		AggressiveText = "Hehe! Take This";
		DefensiveText = "Ow Ow Ow!";
	}
	~Goblin() {
		//std::cout << "You've Defeated A Goblin" << std::endl;
	}
};
class Skeleton :public Entity {
public:
	Skeleton() {
		std::cout << "You've Encountered A Skeleton" << std::endl;
		SetHealth(17);//Medium Health
		SetSpeed(1);
		EnemyBow EB = EnemyBow();
		SetEquipped(EB);
		EntityName = "Skeleton";
		AggressiveText = "*Angry Bone Noises*";
		DefensiveText = "*Bone Rattling!*";

	}
	~Skeleton() { }


};
class Orc : public Entity {
public:
	Orc() {
		std::cout << "You've Encountered A Orc" << std::endl;
		SetHealth(30);//High Health
		SetSpeed(1);
		EnemyAxe EA = EnemyAxe();
		SetEquipped(EA);
		EntityName = "Orc";
		AggressiveText = "AHHHHH!!!";
		DefensiveText = "Argh!...";
	}
	~Orc() { }
};