#pragma once
#include <string>
#include <SFML/Graphics.hpp>
#include <iostream>

// fyi most of this is probably getting scrapped with my new base sprite being backdrop plan

using namespace sf;
using namespace std;

// a lot of constants
// default width x height (temporary)
const int DWIDTH = 1860;
const int DHEIGHT = 600;
// load background file names
const string startingPath = "../../../assets/backdrops/";
const std::string TEST = "test.png";

class Backdrop { 
public:
	Backdrop() {
		width = DWIDTH;
		height = DHEIGHT;
		activeTextureEnum = 0;
		string bgPath = startingPath + TEST;
		if (!texture.loadFromFile(bgPath, false, IntRect({ 10, 10 }, { width, height })))
		{
			// error check
			cout << "Could not find default background";
		}
		sprite = new Sprite(texture);
	};

	~Backdrop() {
		delete sprite;
	};

	void switchBackdrop(int bgNum);
	void renderCurrentBackdrop(Window * win);
protected:
	int width;
	int height;
	int activeTextureEnum;
	Texture texture;
	Sprite * sprite; // MAKE THIS A SMART POINTER
};

class BackdropController {
protected:
	Backdrop* activeBackdrop = nullptr; // this should be a smart pointer CHANGE IT
	enum backdrops {
		TEST,
	};
public:
	BackdropController() {
		activeBackdrop = new Backdrop();
	};
	~BackdropController() {
		delete activeBackdrop;
	};
	void switchBackdrop(int bgNum, Window* win);

};