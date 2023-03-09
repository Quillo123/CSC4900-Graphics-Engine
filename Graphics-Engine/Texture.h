#pragma once
#include <string>
class Texture
{
public:
	Texture();

	void LoadTexture(std::string filepath);

	void Use();

private:
	unsigned int _textureId;
	unsigned char* _data;
	int _width;
	int _height;
	int _numChannels;
};

