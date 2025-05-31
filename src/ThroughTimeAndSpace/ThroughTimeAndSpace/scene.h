#pragma once

#include "backdropController.h"

class Scene {
	// etc
	// has backdropController, stageController (has object controllers and character controllers), camera controller
	// basically contains all main controllers, the controller of the controllers
	// layers are backdrop, stage, camera, probably need audio controller, player interaction controller?

public:
	Scene(RenderWindow * window) {
		bControl = new BackdropController();
		bControl->switchBackdrop(0, window);
	}

	~Scene() {
		delete bControl;
	}
protected: // for now
	BackdropController* bControl;
	//StageController * sControl;
	//CameraController * cControl;
	//AudioController * aControl;
};