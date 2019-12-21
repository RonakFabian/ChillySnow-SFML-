#pragma once
#include"Tree.h"
#include"Player.h"
#include"HighScore.h"


bool isDead = false;
Font thickFont;
Font smallFont;
Text scoreText;
Text gameOverText;
Text spaceToRestart;
Text highScore;
Clock ck;
Time _time;
int currentScore;
int _highScore;
int prevScore;
int timer = 0;
std::vector<Tree> treePool;
int tempHighScore = 0;
bool canDebugColliders;

