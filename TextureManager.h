#pragma once
#include"Common.h"

class TextureManager
{
	std::map<std::string, sf::Texture> Textures;
public:
	sf::Texture *GetTexture(std::string Path)
	{
		std::map<std::string, sf::Texture>::iterator it = Textures.find(Path);
		while (it != Textures.end())
		{
			if (it->first == Path)
			{
				std::cout << "Texture already loaded! " << Path.c_str() << " " << "[END]" << std::endl;
				return &it->second;
			}
			else
			{
				it++;
			}
		}

		sf::Texture texture;
		if (!texture.loadFromFile(Path))
			std::cout << "ERROR LOADING TEXTURE '" << Path.c_str() << "'!" << std::endl;
		Textures.insert(std::make_pair(Path, texture));
		//Paths.push_back(Path);
		std::cout << " " << Path.c_str() << std::endl;

		//return &Textures[0];
		return GetTexture(Path);
	}

};