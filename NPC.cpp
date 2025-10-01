#include "NPC.h"

NPC::NPC(Vector2f _pos, Vector2f _size)
{
	size = _size;
	body.setSize(size);
	body.setOrigin({ size.x / 2,size.y / 2 });
	position = _pos;
	body.setPosition(position);
	body.setFillColor(Color::Red);
	body.setOutlineColor(Color::White);
	body.setOutlineThickness(size.x / 15);
	speed = 200;
}

NPC::~NPC()
{
}
