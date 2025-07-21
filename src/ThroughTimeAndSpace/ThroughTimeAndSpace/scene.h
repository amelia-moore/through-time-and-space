#pragma once

#include "backdropController.h"

// a scene is dictated by a general set of backdrops and story associated. there is a finite number of scenes, and backdrops can change in each.
// for example, the opening scene consists of just Time going to work. the second scene consists of Space getting ready to go out.
// Time cannot flip in the mirror in scene 1 (dialogue preventing him from flipping, but allows him to access a menu maybe). Space can flip, changing the backdrop.
// a scene can have cutscenes, fight scenes, or reflection/mirror menu scenes within it, but it does not change the scene number. 
// the only special scene is the title menu (scene 0). the others are sub-scenes and recurrence y/n of that sub-scene does not affect the scene number.
// perhaps indicate changing scene via player character switch? maybe, gives more clarity for coding but less choice for player.
// (could just do it for now since idk how much character customization i want to give the player, and it might be ambitious to put in)

class Scene {
	// etc
	// has backdropController, stageController (has object controllers and character controllers), camera controller
	// basically contains all main controllers, the controller of the controllers
	// layers are backdrop, stage, camera, probably need audio controller, player interaction controller?

	// instantiates all of the controller specifics per scene

public:
	Scene(Window * win) {
		bControl = new BackdropController();
		window = win;
		loadInitialScene(window);
	}

	~Scene() {
		delete bControl;
	}

	int loadScene1(Window* window);
	int loadScene2(Window* window);
protected: // for now
	BackdropController * bControl;
	Window* window;
	//LayersController * sControl; // renders objects -- if the object in question is a player, that object should also contain a player controller
	//AudioController * aControl;
};