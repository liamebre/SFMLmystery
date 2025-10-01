#pragma once
#include "inc.h"
#include "player.h"
class NPC : public player
{
public:

	RectangleShape body;
	Vector2f position;
	Vector2f size;
	int speed;
	string name = "john NPC";
	vector<bool> directions = { false,false,false,false };//up,down,left,right
	vector<String> sayings = { "N1 line 1","N1 line 2","N1 line 3 " };
	int currSay = 0; // keeps track of the current saying to display


	NPC(Vector2f _pos = { 300,300 }, Vector2f _size = { 30,60 });
	~NPC();
};

