#pragma once

#include <windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include <gl/glut.h>
#include <IL/ilut.h>


struct TextureHandler{
	ILubyte* data;
	ILuint image_id;
	ILint width, height;
	ILint destFormat;
	ILint destType;
	GLuint texture_id;

	bool LoadTextureFromFile(const char* filename,int id){
		ilEnable(IL_ORIGIN_SET);
		ilOriginFunc(IL_ORIGIN_LOWER_LEFT);
		
		image_id = id; texture_id = id;

		ilGenImages(1,&image_id);
		ilBindImage(image_id);
		if(!ilLoadImage(filename)){
			return false;
		}
		ilConvertImage(IL_RGB,IL_UNSIGNED_BYTE);

		data = ilGetData();
		width = ilGetInteger(IL_IMAGE_WIDTH);
		height = ilGetInteger(IL_IMAGE_HEIGHT);
		destFormat = ilGetInteger(IL_IMAGE_FORMAT);
		destType = ilGetInteger(IL_IMAGE_TYPE);

		glGenTextures(1, &texture_id);
		glBindTexture(GL_TEXTURE_2D,texture_id);
		glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

		glTexImage2D(GL_TEXTURE_2D, 0, destFormat, width, height, 0 , destFormat, destType, data);
		
		ilDeleteImages(1,&image_id);
		return true;
	}
};