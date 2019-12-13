#pragma once
#include"pch.h"
#include"Common.h"
#include"Sfml_Base.h"


class Tree
{
private:
	time_t timer;
	float randomX;

public:
	Sprite sp;
	Texture* t;
	RectangleShape collision;

	Tree(Texture* t)
	{
		this->t = t;
		sp.setTexture(*t);

		srand(NULL);
		collision.setFillColor(sf::Color(250, 0, 0, 200));



		collision.setSize(Vector2f(50, 100));

		randomX = rand() % APP_WIDTH + 50;


		sp.setPosition(randomX - 50, APP_HEIGHT);



		srand((unsigned)time(&timer));
		sp.setPosition(sf::Vector2f((1 + rand() % 500), APP_HEIGHT - 50));

		collision.setPosition(sp.getPosition().x + 25, sp.getPosition().y + 50);
	}

	void Move()
	{
		sp.move(0, -5.f);

		if (sp.getPosition().y <= -150)
		{

			sp.setPosition(Vector2f((1 + rand() % 500), APP_HEIGHT + rand() % 1000));


		}
		collision.setPosition(sp.getPosition().x + 25, sp.getPosition().y + 50);
	}
};
	
	