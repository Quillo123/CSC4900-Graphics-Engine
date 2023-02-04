#include "Texture.h"
#include <glad/glad.h>
#include "stb_image.h"
#include <iostream>


Texture::Texture()
{
	glGenTextures(1, &_textureId);
    _data = nullptr;
    _width = 0;
    _height = 0;
    _numChannels = 0;
}

void Texture::LoadTexture(std::string filepath)
{
    glBindTexture(GL_TEXTURE_2D, _textureId);
    // set the texture wrapping/filtering options (on the currently bound texture object)
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    // load and generate the texture
    _data = stbi_load(filepath.c_str(), &_width, &_height, &_numChannels, 0);
    if (_data)
    {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, _width, _height, 0, GL_RGB, GL_UNSIGNED_BYTE, _data);
        glGenerateMipmap(GL_TEXTURE_2D);
    }
    else
    {
        std::cout << "Failed to load texture: " << filepath << std::endl;
    }

    glBindTexture(GL_TEXTURE_2D, 0);
}

void Texture::Use()
{
    if (_width > 0 && _height > 0) {
        glBindTexture(GL_TEXTURE_2D, _textureId);
    }
}


