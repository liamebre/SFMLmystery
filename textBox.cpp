#include "textBox.h"

textBox::~textBox()
{
	position = Vector2f(0.f, 0.f);
	size = Vector2f(0.f, 0.f);

	baseBox.setSize(size);
	baseBox.setPosition(position);
	baseBox.setFillColor(Color::Black);
	baseBox.setOutlineColor(Color::White);

	textArea.setSize(size);
	textArea.setPosition(position);
}

textBox::textBox( Vector2f _size,Text& _text)
{
	size = { _size.x - 100, _size.y / 4};
	position = { 50, size.y * 3 - 30};

	baseBox.setSize({ size.x, size.y});
	baseBox.setPosition({ position.x, position.y });
	baseBox.setFillColor(Color::Black);
	baseBox.setOutlineColor(Color::White);
	baseBox.setOutlineThickness(5.f);

	textArea.setSize(Vector2f(size.x - 20.f, size.y - 20.f));
	textArea.setPosition(Vector2f(position.x + 10.f, position.y + 10.f));
	textArea.setFillColor(Color::White);

	_text.setCharacterSize(50);
	_text.setPosition(Vector2f(position.x + 20.f, position.y + 20.f));
	_text.setFillColor(Color::Black);
	_text.setString("hello");
}

void textBox::nextline(Time gt)
{
	if (gt.asMilliseconds() - lastInputsTime.asMilliseconds() < 300) {
		return;
	}
	else {
		nextLine = true;
		lastInputsTime = gt;
	}
}

void textBox::update(Text& _text,vector<String> texts, int& line)
{
	if (nextLine) {
		_text.setString(changeText(texts,line));
		nextLine = false;
	}
}

String textBox::changeText(vector<String> texts, int& line)
{
	line++;
	if (line >= static_cast<int>(texts.size()) ) {
		line = 0;
	}
	return texts[line];
}

void textBox::getTextBox(RenderWindow& _window, Text& _text)
{
	_window.draw(baseBox);
	_window.draw(textArea);
	_window.draw(_text);
}

