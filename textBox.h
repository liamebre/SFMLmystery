#pragma once
#include "inc.h"

class textBox
{
public:
	RectangleShape baseBox;
	RectangleShape textArea;
	Vector2f size;
	Vector2f position;
	textBox( Vector2f _size,Text& _text);
	~textBox();
	bool nextLine = false;
	Time lastInputsTime = Time::Zero;


	void getTextBox(RenderWindow& _window, Text& _text);
	void nextline(Time clock);
	void update(Text& _tex, vector <String> texts, int& line ) ;
	String changeText(vector<String> texts, int& line);
};

