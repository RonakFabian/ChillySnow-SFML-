#include"pch.h"
#include<iostream>
#include"SFML\Graphics.hpp"
#include"SFML\Window.hpp"
#include"SFML\System.hpp"
#include<math.h>
#include<vector>
#include<cstdlib>
#include"Common.h"


using namespace sf;



class Tree
{
private:
	time_t timer;
	float randomX;

public:
	Sprite sp;
	Texture* t;

	Tree(Texture* t)
	{
		this->t = t;
		sp.setTexture(*t);

		srand(NULL);
			
			
			randomX = rand() % APP_WIDTH + 50;
		
		
			sp.setPosition(randomX-50,APP_HEIGHT);
			
		
		
			srand((unsigned)time(&timer));
			sp.setPosition(sf::Vector2f((1 + rand() % 500), APP_HEIGHT - 50));
			sp.setPosition(sp.getPosition().x, APP_HEIGHT + rand() % 1000);
	}

	void Move()
	{
		sp.move(0, -5.f);
			
			if (sp.getPosition().y <=-150)
			{
				
				sp.setPosition(sf::Vector2f((1 + rand() % 500), APP_HEIGHT - 50));
				sp.setPosition(sp.getPosition().x, APP_HEIGHT+rand()%1000);
			}
	}
};



int main()
{
	srand(time(NULL));

	RenderWindow window(VideoMode(APP_WIDTH, APP_HEIGHT), "SFML GAME", Style::Default);
	window.setFramerateLimit(60);

	std::vector<Tree> treePool;
	
	Texture t;
	t.loadFromFile("Images/Tree.png");

	for (size_t i = 0; i < 15; i++)
	{
		Tree tree(&t);
		treePool.push_back(tree);
	}



	CircleShape player(25.f);
	player.setFillColor(Color::White);
	player.setPointCount(3);
	player.setOrigin(25.f, 25.f);





	

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}

	
		if (Keyboard::isKeyPressed(Keyboard::A))
			player.move(-10.f, 0.f);
		if (Keyboard::isKeyPressed(Keyboard::D))
			player.move(10.f, 0.f);
		

		window.clear(Color(230,240,234));

		for (size_t i = 0; i < treePool.size(); i++)
		{
			window.draw(treePool[i].sp);
			treePool[i].Move();

		}
		window.draw(player);


		window.display();
	}

	return 0;
}