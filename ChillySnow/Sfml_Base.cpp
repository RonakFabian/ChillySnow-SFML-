#include"pch.h"
#include"Sfml_Base.h"
#include"Tree.h"
#include"Player.h"





void Reset()
{

}

int main()
{


	srand(time(NULL));

	RenderWindow window(VideoMode(APP_WIDTH, APP_HEIGHT), "SFML GAME", Style::Default);
	window.setFramerateLimit(60);

	std::vector<Tree> treePool;


	Texture t;
	Texture pt;
	t.loadFromFile("Images/Tree.png");
	pt.loadFromFile("Images/Ball.png");
	font.loadFromFile("Font/f.otf");
	text.setFont(font);

	for (size_t i = 0; i < 15; i++)
	{
		Tree tree(&t);
		treePool.push_back(tree);
	}


	Player player(&pt);
	text.setPosition(50, 0);
	text.setFillColor(sf::Color::Black);
	text.setCharacterSize(25);




	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}

		window.clear(Color(230, 240, 234));

		if (!isDead)
		{


			for (size_t i = 0; i < treePool.size(); i++)
			{
				window.draw(treePool[i].sp);
				window.draw(treePool[i].collision);
				treePool[i].Move();

				if (player.sp.getGlobalBounds().intersects(treePool[i].collision.getGlobalBounds()))
				{

					isDead = true;
					Reset();

				}
			}

			player.Move();
			_time = ck.getElapsedTime();
			timer = _time.asSeconds();
			text.setString("Score:" + std::to_string(timer));

			window.draw(player.sp);
			window.draw(text);


		}
		window.display();

	}

	return 0;
}