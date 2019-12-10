//#include "pch.h"
//#include "Tree.h"
//
//
//
//Tree::Tree()
//{
//	
//	
//	srand(NULL);
//	//randomX = 100 + rand() % APP_WIDTH*4;
//	
//	randomX = rand() % APP_WIDTH + 50;
//
//	circle.setRadius(20);
//	circle.setPointCount(3);
//
//	circle.setPosition(randomX,APP_HEIGHT-50);
//	//circle.setPosition(100,APP_HEIGHT-50);
//
//
//	srand((unsigned)time(&timer));
//
//
//
//}
//Tree::Tree(sf::Texture* t)
//{
//	this->texture = t;
//	Tree::tSprite.setTexture(*texture);
//}
//void Tree::Move()
//{
//	circle.move( 0, -5.f);
//	
//	if (circle.getPosition().y <= 0)
//	{
//		
//		circle.setPosition(sf::Vector2f((1 + rand() % 500), APP_HEIGHT - 50));
//		circle.setPosition(circle.getPosition().x, APP_HEIGHT+rand()%1000);
//	}
//}
//
//void Tree::setPosition(sf::Vector2f Pos)
//{
//	circle.setPosition(Pos);
//}
//
//float Tree::returnRandomX() const {	return randomX;}
//
//
//
//
//Tree::~Tree(){}
//
