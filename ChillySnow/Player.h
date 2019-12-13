#pragma once
#include"Common.h"
class Player
{

private:
	bool isMovingRight;


public:
	sf::Sprite sp;
	sf::Texture* t;



	float speed = 5.0f;



	Vector2f pos;
	Player(sf::Texture* t)
	{
		this->t = t;
		sp.setTexture(*t);


	}

	float lerp(float v0, float v1, float t) {
		return (1 - t) * v0 + t * v1;
	}


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


	}
};