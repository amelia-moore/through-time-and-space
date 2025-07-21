// background controller, controls backdrops
// possibly merge into making backdrop a sprite that's basically just sprite 0, always rendered on the bottom and is completely not interactable

#include <SFML/Graphics.hpp>
#include "backdropController.h"

// has mapping of backdrop images to numbers, one backdrop object (private object probably)
// method to switch backdrop (switchBackdrop)

void BackdropController::switchBackdrop(int bgNum, Window * win) { 
	activeBackdrop->switchBackdrop(bgNum); 
	activeBackdrop->renderCurrentBackdrop(win);
}

void Backdrop::switchBackdrop(int bgNum) { //possibly add some changes for game settings changes?
	// actually load and switch texture
	// check enum, change/load texture from file, render new backdrop
	activeTextureEnum = bgNum; // as final confirmation
	
}

void Backdrop::renderCurrentBackdrop(Window * win) {
	(*win).draw(*sprite);
}