//#include "pch.h"
//#include "Game.h"
//
//
//void Game::initVariables()
//{
//	window = nullptr;
//
//	
//
//	spaceShip.setRadius(17.5f);
//	spaceShip.setOutlineColor(sf::Color::White);
//	spaceShip.setPointCount(30);
//	spaceShip.setFillColor(sf::Color(0, 128, 125));
//	spaceShip.setPosition(250, 100);
//	
//	offset = spaceShip.getPosition() - trailPos;
//	
//
//	sf::Transform transform;
//	speed = 5;
//	
//	/*sf::Texture tex;
//	tex.loadFromFile("Images/Tree.png");
//
//	
//
//
//	for (int i = 0; i < 15; i++)
//	{
//		Tree tree(&tex);
//		treePool.push_back(tree);
//	}
//*/
//	
//	
//	
//}
//
//
//
//Game::Game()
//{
//	
//	initVariables();
//	initWindow();
//
//
//}
//
//
//void Game::Update()
//{
//	PollEvents();
//	MovePlayer();
//	
//}
//
//
//
//void Game::MovePlayer()
//{
//
//	x = 0;
//	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A))
//	{
//		x = -1;
//	}
//	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D))
//	{
//		x = 1;
//
//	}
//
//
//	transform.translate(x*speed, 0);
//
//
//
//}
//
//void Game::Render()
//{
//
//	
//	window->clear(sf::Color(235,235,222));
//	//--------------------------------------
//
//
//	window->draw(spaceShip, transform);
//
//	
//	timer = clock.getElapsedTime();
//	
//	for (int i = 0; i < treePool.size(); i++)
//	{
//	
//		treePool[i].Move();
//		window->draw(treePool[i].tSprite);
//		
//	}
//
//
//
//	
//	
//	//--------------------------------------
//	window->display();
//
//}
//
//
//
//Game::~Game()
//{
//	delete window;
//}
//bool Game::isWindowOpen()
//{
//	return window->isOpen();
//}
//void Game::PollEvents()
//{
//	while (window->pollEvent(event))
//	{
//		
//		
//
//		switch (event.type)
//		{
//			case sf::Event::Closed:
//				window->close();
//				break;
//
//			case sf::Event::KeyPressed:if (event.key.code == (sf::Keyboard::Escape))
//				window->close();
//				break;
//
//
//		}
//	}
//
//
//}
//void Game::initWindow()
//{
//	window = new sf::RenderWindow(sf::VideoMode(APP_WIDTH, APP_HEIGHT), "SFML works!");
//	window->setFramerateLimit(60);
//
//
//}
//
