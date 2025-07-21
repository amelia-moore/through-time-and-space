#pragma once
#include "backdropController.h"
#include "audioController.h"
#include "objectController.h"
#include "playerController.h"


// stage is in charge of game -- basically where a running game exists

class Stage {
	// houses all the controllers and has methods to change them

public:
	Stage(Window* win) {
		// visuals
		BackdropController* bControl = new BackdropController();
		ObjectController* oControl = new ObjectController();

		// audio
		AudioController* aControl = new AudioController();


		// methods
		int loadAudio(int file); // change -- checks int file in asset list
		int loadObject(int texture, int xpos, int ypos, bool interactable, bool player, Window * win); // interactable bool says how to treat it as an interactable (no interaction, passing interaction -- static but as player object is near it it becomes interactable, direct interaction -- player sprites -ie character walking or menu boxes- or always responds to player events/movement)
		int loadBackdrop(int texture, Window * win);
	}
protected:

};