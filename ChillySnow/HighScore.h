#pragma once
#include<fstream>
#include<iostream>
#include<string>

class HighScore
{
private:
	std::fstream  myfile;

	int myScore;

public:
	HighScore()
	{
		CreateFile();
		GetHighScore();
	}
	//Make a new TextFile
	void CreateFile()
	{
		myfile.open("HighScoreFile.txt");
		myfile.close();
	}
	//Overwrite score 
	void WriteHighScore(const int& scoreToWrite)
	{
		myfile.open("HighScoreFile.txt");
		myfile << scoreToWrite;
		myfile.close();
	}
	// Get highscore
	int GetHighScore()
	{
		myfile.open("HighScoreFile.txt");
		myfile >> myScore;
		return myScore;
	
	}


};