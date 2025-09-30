#include "textBox.h"
#include "player.h"

int main()
{
	float width = 1920;
	float height = 1080;
	Vector2u resolution = Vector2u(width,height);
	Vector2f screenSize = Vector2f(width, height);
	VideoMode vm(resolution);
	RenderWindow window(vm, "murderMystery",State::Fullscreen);	

	vector<String> sayings = { "hello","hi","how are you?","goodbye","see you later","bye" };
	int currSay = 0; // keeps track of the current saying to display 

	Font font;
	if (!font.openFromFile("fonts/tuffy.ttf")) {cerr << "Error: Could not load font!" << endl;}

	Text& text = *(new Text(font," ",30));
	textBox tb(screenSize,text);


	Clock clock;
	Clock gameClock;

	//keeps window open
	while (window.isOpen()) {
		Time dt = clock.restart();
		Time gc = gameClock.getElapsedTime();
		while (const optional event = window.pollEvent())
		{
			if (event->is<Event::Closed>() || Keyboard::isKeyPressed(Keyboard::Key::Escape))
				// Quit the game when the window is closed
				window.close();
		}

		if (Keyboard::isKeyPressed(Keyboard::Key::Enter)) {
			tb.nextline(gc);
		}

		tb.update(text,sayings,currSay);


		// Update the game state
		window.clear();
		tb.getTextBox(window,text);
		window.display();

	}//end of open window

}//end of main

