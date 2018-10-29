#include "stdafx.h"
#include "Enemies.h"
#include "Enemy.h"

Enemies::Enemies()
{
	//name, level, health, maxHealth, damage, attackChance, defendChance, attackTimes);
	Enemy *rat = new Enemy(new char[4]{ "rat" }, 1, 2, 2, new int[2]{ 1, 2 }, 20, 20, 1);
	Enemy *leprechaun = new Enemy(new char[15]{ "mad leprechaun" }, 1, 3, 3, new int[2]{ 0, 3 }, 30, 10, 1);
	Enemy *goblin = new Enemy(new char[7]{ "goblin" }, 2, 5, 5, new int[2]{ 1, 5 }, 30, 20, 1);
	Enemy *wolf = new Enemy(new char[5]{ "wolf" }, 2, 8, 8, new int[2]{ 1, 6 }, 40, 10, 1);
	Enemy *orc = new Enemy(new char[4]{ "orc" }, 3, 10, 10, new int[2]{ 3, 7 }, 40, 25, 1);
	Enemy *ogre = new Enemy(new char[5]{ "ogre" }, 4, 20, 20, new int[2]{ 4, 14 }, 45, 30, 1);
	Enemy *werewolf = new Enemy(new char[9]{ "werewolf" }, 5, 30, 30, new int[2]{ 2, 7 }, 50, 30, 2);
	Enemy *troll = new Enemy(new char[6]{ "troll" }, 6, 100, 100, new int[2]{ 3, 30 }, 30, 20, 1);
	Enemy *spider = new Enemy(new char[13]{ "giant spider" }, 7, 80, 80, new int[2]{ 3, 36 }, 60, 40, 1);
	Enemy *manticore = new Enemy(new char[10]{ "manticore" }, 8, 120, 120, new int[2]{ 2, 20 }, 45, 45, 3);
	Enemy *golem = new Enemy(new char[6]{ "golem" }, 9, 300, 300, new int[2]{ 5, 50 }, 50, 20, 2);
	Enemy *hydra = new Enemy(new char[6]{ "hydra" }, 10, 180, 180, new int[2]{ 2, 12 }, 40, 30, 9);

	EnemyList[0] = rat;
	EnemyList[1] = leprechaun;
	EnemyList[2] = goblin;
	EnemyList[3] = wolf;
	EnemyList[4] = orc;
	EnemyList[5] = ogre;
	EnemyList[6] = werewolf;
	EnemyList[7] = troll;
	EnemyList[8] = spider;
	EnemyList[9] = manticore;
	EnemyList[10] = golem;
	EnemyList[11] = hydra;

	Enemy *lich = new Enemy(new char[5]{ "lich" }, 99, 150, 150, new int[2]{ 4, 40 }, 90, 60, 2);
	Enemy *dragon = new Enemy(new char[7]{ "dragon" }, 99, 500, 500, new int[2]{ 3, 30 }, 65, 50, 4);

	BossList[0] = lich;
	BossList[1] = dragon;
}


Enemies::~Enemies()
{
	//TODO remove enemies i guess?
	//delete EnemyList;
	//delete BossList;
}
