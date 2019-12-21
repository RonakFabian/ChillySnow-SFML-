#pragma once
#include"Common.h"
class Player
{

private:

	Vector2f pos;
	float speed = 5.0f;


public:
	sf::Sprite sp;
	sf::Texture* t;

	sf::CircleShape collider;


	//Setting Texture to Sprite
	Player(sf::Texture* t)
	{
		this->t = t;
		sp.setTexture(*t);

		collider.setRadius(17.5f);
		collider.setFillColor(sf::Color(255, 0, 0, 200));
		collider.setPosition(sp.getPosition());

	}

	//Player Movement
	void Move()
	{

		if (Keyboard::isKeyPressed(Keyboard::Left) || Keyboard::isKeyPressed(Keyboard::A))
		{
			sp.move(-speed, 0);

		}
		if (Keyboard::isKeyPressed(Keyboard::Right) || Keyboard::isKeyPressed(Keyboard::D))
		{
			sp.move(speed, 0);

		}
		collider.setPosition(sp.getPosition());
	}
};