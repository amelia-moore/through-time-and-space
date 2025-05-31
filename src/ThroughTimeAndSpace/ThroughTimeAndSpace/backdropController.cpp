// background controller, controls backdrops

#include <SFML/Graphics.hpp>
#include "backdropController.h"

// has mapping of backdrop images to numbers, one backdrop object (private object probably)
// method to switch backdrop (switchBackdrop)

void BackdropController::switchBackdrop(int bgNum, RenderWindow * win) { 
	activeBackdrop->switchBackdrop(bgNum); 
	activeBackdrop->renderCurrentBackdrop(win);
}

void Backdrop::switchBackdrop(int bgNum) { //possibly add some changes for game settings changes?
	// actually load and switch texture
	// check enum, change/load texture from file, render new backdrop
	activeTextureEnum = bgNum; // as final confirmation
	
}

void Backdrop::renderCurrentBackdrop(RenderWindow * win) {
	(*win).draw(*sprite);
}