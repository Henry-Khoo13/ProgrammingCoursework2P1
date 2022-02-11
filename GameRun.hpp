#pragma once
#include <iostream> 
#include <string>
#include "GameEntities.hpp"
using namespace std;
namespace Game {
	//Convient area where key variables are stored and passed while the game runs.
	struct GameData {
		int Difficulty;
		int Role;
		int AmountOfEncounters;
		int RandomElmPos = 0;
	};
	int Run(bool Running);
	int Battle(MainCharacter& MC, GameData& GD);
	int Story(MainCharacter& MC, GameData& GD);
	int Loot(MainCharacter& MC, GameData& GD);
	int RandomNumber(int Elm);

	int Run(bool Running) {
		while (Running) {//While loop, ends if the user chooses to quit at the end.
			struct GameData GD;
			MainCharacter MC;
			cout << "Welcome to Henry's Text Adventure" << endl;
			cout << "(1) Easy"<<endl; //Type '1' for Easy
			cout << "(2) Medium" << endl; //Type '2' for Medium
			cout << "(3) Hard" << endl;//Type '3' for Hard
			cout << "Select The Difficulty: ";
			cin >> GD.Difficulty;
			switch (GD.Difficulty) {
			case 1:
				cout << "Easy Mode Selected"<<endl;
				GD.AmountOfEncounters = 3;
				break;
			case 2:
				cout << "Medium Mode Selected" << endl;
				GD.AmountOfEncounters = 5;
				break;
			case 3:
				cout << "Hard Mode Selected" << endl;
				GD.AmountOfEncounters = 7;
				break;
			default:
				cout << "Invalid Input" << endl;
				break;
			}
			cout << "\n" << endl;
			cout << "(1) Warrior" << endl; //Type '1' for Warrior
			cout << "(2) Mage" << endl; //Type '2' for Mage
			cout << "(3) Thief" << endl;//Type '3' for Thief
			cout << "Select The Player Class: ";
			cin >> GD.Role;
			switch (GD.Role) {
			case 1:
				//cout << "Warrior Selected" << endl;
				MC = Warrior();
				break;
			case 2:
				//cout << "Mage Selected" << endl;
				MC = Mage();
				break;
			case 3:
				//cout << "Thief Selected" << endl;
				MC = Thief();
				break;
			default:
				cout << "Invalid Input" << endl;
				break;
			}
			//Story(MC);

			while (GD.AmountOfEncounters > 0 && MC.CheckAlive()) {
				cout << "\n";
				cout << "Generating Scenario" << endl;
				cout << "\n";
				//cout << "ELM: " << GD.RandomElmPos;
				int RN = RandomNumber(GD.RandomElmPos);
				GD.RandomElmPos = GD.RandomElmPos + 1;
				switch (RN) {
				case 0:
					Battle(MC,GD);
					break;
				case 1:
					Story(MC,GD);
					break;
				case 2:
					Loot(MC,GD);
					break;
				default:
					cout << "Error" << endl;
					break;
				}
				GD.AmountOfEncounters = GD.AmountOfEncounters - 1;
				if (!MC.CheckAlive()) {
					cout << "Game Over..." << endl;
					break;
				}
				system("pause");
			}
			if (MC.CheckAlive()) {
				cout << "\n";
				cout << "Congratulations You Survived!" << endl;
				cout << "\n";
			}
			cout << "\n";
			cout << "(1) New Game" << endl; //Type '1' for Easy
			cout << "(2) Quit Game" << endl; //Type '2' for Medium
			cout << "Select An Option: ";
			int x;
			cin >> x;
			switch (x) {
			case 1:
				cout << "\n";
				cout << "Continuing Game" << endl;
				cout << "\n";
				break;
			case 2:
				cout << "\n";
				cout << "Ending Game" << endl;
				cout << "\n";
				Running = false;
				break;
			default:
				cout << "\n";
				cout << "Invalid Input: Ending Game" << endl;
				cout << "\n";
				Running = false;
				break;
			}
			//Running = false;// For Testing
		}
		return 0;
	}
	int Battle(MainCharacter& MC, GameData& GD) {
		Entity E;
		cout << "\n";
		cout << "A Combat Encounter!" << endl;
		cout << "\n";
		int RN = RandomNumber(GD.RandomElmPos);
		GD.RandomElmPos = GD.RandomElmPos + 1;
		//cout << "ELM: " << GD.RandomElmPos;
		//cout << "RN: " << RN;
		switch (RN) {
		case 0:
			E = Goblin();
			break;
		case 1:
			E = Skeleton();
			break;
		case 2:
			E = Orc();
			break;
		}
		while (E.CheckAlive() && MC.CheckAlive()) {
			if (MC.ReturnSpeed() >= E.ReturnSpeed()) {
				cout << "\n";
				cout << "-- " << MC.EntityName << " Turn--" << endl;

				E.TakeDamage(MC.Attack());
				MC.DisplayHealth();
				E.DisplayHealth();
				if (!E.CheckAlive()) {
					break;
				}

				cout << "\n";
				cout << "-- " << E.EntityName << " Turn--" << endl;


				MC.TakeDamage(E.Attack());
				MC.DisplayHealth();
				E.DisplayHealth();
				if (!MC.CheckAlive()) {
					break;
				}
			}
			else {
				cout << "\n";
				cout << "-- " << E.EntityName << " Turn--" << endl;

				MC.TakeDamage(E.Attack());
				MC.DisplayHealth();
				E.DisplayHealth();
				if (!MC.CheckAlive()) {
					break;
				}

				cout << "\n";
				cout << "-- " << MC.EntityName << " Turn--" << endl;
				E.TakeDamage(MC.Attack());
				MC.DisplayHealth();
				E.DisplayHealth();
				if (!E.CheckAlive()) {
					break;
				}
			}
		}
		if (!MC.CheckAlive()) {
			cout << "You have been defeated!" << endl;
		}
		else {
			cout << "You have defeated the " << E.EntityName << endl;
		}
		return 0;
	}
	//Battle Again a random enemy selected from 3 options
	//Will output if the user is dead and will be checked again in the main function to see if the game should end.
	int Story(MainCharacter& MC, GameData& GD) {
		cout << "\n";
		cout << "An Story Encounter!" << endl;
		cout << "\n";
		int RN = RandomNumber(GD.RandomElmPos);
		GD.RandomElmPos = GD.RandomElmPos + 1;
		switch (RN) {
		case 0:
			cout << MC.EntityName << ": takes a rest and gains some health"<<endl;
			MC.AddHealth(3);
			break;
		case 1:
			cout << MC.EntityName<<": trecks safely through some woods"<<endl;
			break;
		case 2:
			cout << MC.EntityName << ": drinks a healing potion" << endl;
			MC.AddHealth(4);
			break;

		default:
			cout << "Error" << endl;
			break;
		}
		return 0;
	}
	//This provides outputs story and a few random events that provide health to the character.
	int Loot(MainCharacter& MC, GameData& GD) {
		Item LootDrop;
		cout << "\n";
		cout << "A Loot Encounter!" << endl;
		cout << "\n";
		int RN = RandomNumber(GD.RandomElmPos);
		GD.RandomElmPos = GD.RandomElmPos + 1;
		int Input;
		switch (RN) {
		case 0:
			LootDrop = Stick();
			cout << "Current Weapon Equipped: " << MC.EquippedItem.Name<<endl;
			cout << "(1) Equip: "<< LootDrop.Name << endl; //Type '1' for Switching Weapon
			cout << "(2) Keep: " << MC.EquippedItem.Name << endl; //Type '2' for Keeping old Weapon
			cout << "Select An Option: ";
			cin >> Input;
			switch (Input) {
			case 1:
				MC.SetEquipped(LootDrop);
				cout << "Equipped " << MC.EquippedItem.Name << endl;
				break;
			case 2:
				cout << "Keeping " << MC.EquippedItem.Name << endl;
				break;
			default:
				cout << "Invalid Input Defaulting to keeping old equipment " << endl;
			}
			break;
		case 1:
			LootDrop = Club();
			cout << "Current Weapon Equipped: " << MC.EquippedItem.Name << endl;
			cout << "(1) Equip: "<< LootDrop.Name << endl; //Type '1' for Switching Weapon
			cout << "(2) Keep: " << MC.EquippedItem.Name << endl; //Type '2' for Keeping old Weapon
			cout << "Select An Option: ";
			cin >> Input;
			switch (Input) {
			case 1:
				MC.SetEquipped(LootDrop);
				cout << "Equipped " << MC.EquippedItem.Name << endl;
				break;
			case 2:
				cout << "Keeping " << MC.EquippedItem.Name << endl;
				break;
			default:
				cout << "Invalid Input Defaulting to keeping old equipment " << endl;
			}
			break;
		case 2:
			LootDrop = PowerSword();
			cout << "Current Weapon Equipped: " << MC.EquippedItem.Name << endl;
			cout << "(1) Equip: "<< LootDrop.Name << endl; //Type '1' for Switching Weapon
			cout << "(2) Keep: "<< MC.EquippedItem.Name << endl; //Type '2' for Keeping old Weapon
			cout << "Select An Option: ";
			cin >> Input;
			switch (Input) {
			case 1:
				MC.SetEquipped(LootDrop);
				cout << "Equipped " << MC.EquippedItem.Name << endl;
				break;
			case 2:
				cout << "Keeping " << MC.EquippedItem.Name << endl;
				break;
			default:
				cout << "Invalid Input Defaulting to keeping old equipment " << endl;
			}
			break;

		default:
			cout << "Error" << endl;
			break;
		}
		return 0;
	}
	//The option to pick upgraded or worse weapons which can be equipped to the character and replace their default weapon.
	int RandomNumber(int Elm) {
		int RandomNumber[100];
		srand((unsigned)time(0));
		for (int i = 0; i < 100; i++) {
			RandomNumber[i] = rand() % 99;
			//cout << RandomNumber[i] << endl;
		}
		if (RandomNumber[Elm] <= 33) {
			//cout << "0 RAN";
			return 0;
		}
		else if (33 < RandomNumber[Elm] && RandomNumber[Elm] <= 66) {
			//cout << "1 RAN";
			return 1;
		}
		else if (66 < RandomNumber[Elm] && RandomNumber[Elm] <= 99) {
			//cout << "2 RAN";
			return 2;
		}
		else {
			return 0;
		}
	}
	//Random script to create a random number, took a lot of time to figure out.

	//Functions above use referances to avoid having to pass too much data about, instead the class can be editted immediately like the game data.
}
//Below is extra code for creating a random variable in C++
//Had to experiement to figure out what worked.
/*
int RandomTest() {
	int RandomNumber;
	srand((unsigned)time(0));
	for (int i = 0; i < 30; i++) {
		RandomNumber = rand() % 3;
		cout << RandomNumber << endl;
	}
	cout << "THIS!!! << " << RandomNumber << endl;
	return 0;
}
*/
/*
int  number;
srand(time(0));
number = rand() % 100;
cout << number << "\t";
cout << "t";
int  i;
srand(time(0));
for (i = 1; i <= 10; i++)
{
	number = rand() % 100;
	cout << number << "\t";
}			//Warrior W = Warrior();
		//cout << "Test Program" << endl;
https://www.educba.com/random-number-generator-in-c-plus-plus/
*/