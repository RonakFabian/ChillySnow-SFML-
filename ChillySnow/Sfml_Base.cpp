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


class Player
{

private:
	

public:
	sf::Sprite sp;
	sf::Texture* t;

	Player(sf::Texture* t)
	{
		this->t = t;
		sp.setTexture(*t);

		

	
	}

	void Move()
	{
		if (Keyboard::isKeyPressed(Keyboard::A))
			sp.move(-10.f, 0.f);
		if (Keyboard::isKeyPressed(Keyboard::D))
			sp.move(10.f, 0.f);
	}
};

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

	for (size_t i = 0; i < 15; i++)
	{
		Tree tree(&t);
		treePool.push_back(tree);
	}



	

	
	Player player(&pt);
	player.sp.setPosition(250, 100);





	

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}

	
		
		

		window.clear(Color(230,240,234));
		player.Move();

		window.draw(player.sp);
		for (size_t i = 0; i < treePool.size(); i++)
		{
			window.draw(treePool[i].sp);
			treePool[i].Move();

		}
		


		window.display();
	}

	return 0;
}