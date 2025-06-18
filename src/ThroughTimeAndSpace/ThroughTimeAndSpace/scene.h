#pragma once

#include "backdropController.h"

class Scene {
	// etc
	// has backdropController, stageController (has object controllers and character controllers), camera controller
	// basically contains all main controllers, the controller of the controllers
	// layers are backdrop, stage, camera, probably need audio controller, player interaction controller?

public:
	Scene(RenderWindow * win) {
		bControl = new BackdropController();
		window = win;
		loadInitialScene(window);
	}

	~Scene() {
		delete bControl;
	}

	int loadScene1(RenderWindow* window);
	int loadScene2(RenderWindow* window);
protected: // for now
	BackdropController * bControl;
	RenderWindow* window;
	//StageController * sControl;
	//AudioController * aControl;
};