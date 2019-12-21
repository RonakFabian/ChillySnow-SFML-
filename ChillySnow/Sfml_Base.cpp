#include"pch.h"
#include"Sfml_Base.h"



//Reset score and clock timer and return tree back to their positions
void Init()
{
	scoreText.setPosition(50, 0);
	scoreText.setFillColor(sf::Color::Black);
	scoreText.setCharacterSize(25);

	ck.restart();

	

	for (Tree &t : treePool)
	{
		t.SendToBack();
	}

}

//Cmd 
void Instructions()
{

}

//Text to display if game over.
void ShowText()
{
	//Check if current score is greater than highscore and overwrite is true


	

	gameOverText.setFillColor(sf::Color::Black);
	gameOverText.setCharacterSize(45);
	gameOverText.setPosition(25, 100);
	gameOverText.setString("GAME OVER ");

	spaceToRestart.setFillColor(sf::Color::Black);
	spaceToRestart.setCharacterSize(25);
	spaceToRestart.setPosition(60, 170);
	spaceToRestart.setString("Press 'Space' To Restart");

	scoreText.setPosition(200, APP_HEIGHT - 50);
	scoreText.setString("SCORE:" + std::to_string(timer));


	highScore.setFillColor(sf::Color::Blue);
	highScore.setCharacterSize(25);

	highScore.setPosition(115, APP_HEIGHT - 100);

	
	


	

	


}

void Reset()
{
	Init();
	isDead = false;
}

int main()
{

	//Window creation
	RenderWindow window(VideoMode(APP_WIDTH, APP_HEIGHT), "SFML GAME", Style::Default);
	window.setFramerateLimit(60);

	//Declaring textures and passing texture so they remain in same scope as the window to draw them
	Texture t;
	Texture pt;

	t.loadFromFile("Images/Tree.png");
	pt.loadFromFile("Images/Ball.png");
	smallFont.loadFromFile("Font/f.ttf");
	thickFont.loadFromFile("Font/fluo.ttf");

	//Setting fonts
	scoreText.setFont(smallFont);
	gameOverText.setFont(thickFont);
	spaceToRestart.setFont(smallFont);
	highScore.setFont(thickFont);

	//Pushing trees to a vector
	for (size_t i = 0; i < 15; i++)
	{
		Tree tree(&t);
		treePool.push_back(tree);
	}


	Player player(&pt);
	player.sp.setPosition(225, 85);
	Init();



	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
			if (event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::F1)
				{
					canDebugColliders = !canDebugColliders;
				}
			}

		}

		window.clear(Color(230, 240, 234));

		//Check if player collides with any of the colliders
		if (!isDead)
		{

			for (size_t i = 0; i < treePool.size(); i++)
			{
				window.draw(treePool[i].sp);

				if (canDebugColliders == true)
				{
					window.draw(treePool[i].collision);
					window.draw(player.collider);
					
				}

				treePool[i].Move();
				//Cheking for collider intersections
				if (player.collider.getGlobalBounds().intersects(treePool[i].collision.getGlobalBounds()))
				{
					isDead = true;
				}
			}
			//Text at game running state
			player.Move();
			_time = ck.getElapsedTime();
			timer = _time.asSeconds();
			scoreText.setPosition(APP_WIDTH - 50, APP_HEIGHT - 50);
			scoreText.setString(std::to_string(timer));
			currentScore = timer;
			window.draw(player.sp);
			window.draw(scoreText);


		}
		else
		{
			// Text at game over state
			ShowText();
			window.draw(scoreText);
			window.draw(gameOverText);
			window.draw(spaceToRestart);
			window.draw(highScore);
	

			//Ask for input if user wants to play again if yes then reset values and play again
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
			{
				player.sp.setPosition(225, 85);
				Reset();
			}

		}

		window.display();

	}

	return 0;
}