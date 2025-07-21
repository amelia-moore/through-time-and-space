// implement sprite base class, parent for extension, possibly abstract. children are player character, maybe regular characters if you
// want a trailing party, regular objects (interactable vs not, reflective vs not, mob object vs not (ie kettle), mirror vs not). 
// (maybe backdrop too, or maybe taht's separate)

using namespace std;

class Sprite {
private: // intent is so backdrop is default settings and objects can override and change given details
	// basic characteristics
	bool interactable = false; // auto not interactable
	bool reflective = false; // auto no reflection mechanics
	bool mirror = false; // auto no mirror mechanics
	bool alive = false; // auto not alive, can't move or fight it.
	bool player = false; // auto not player -- separate class where if it's a player, it can have its own player handler to handle moves

	// location
	int x = -1;
	int y = -1; // no location loaded for the object

	// height and width
	int len = -1;
	int wid = -1; // none loaded yet

	// layer?
	int layer = -1; // 0 for backdrop, extending off for others
	// reflective is only needed in object base class, i assume who cares if a human is reflective altho that might be a fun puzzle
		// yeah nvm that might be a fun puzzle lol

	// store asset on heap w/RAII
	unique_ptr asset = nullptr;

	// implement methods in public
public:
	// basic getters -- make virtual if needed
	bool isPlayer() const { return player; }
	bool isAlive() const { return alive; }
	bool isMirror() const { return mirror; } // can toggle this -- a mirror can be broken therefore not reflective, an obj can reflect but not be a mirror
	bool isReflective() const { return reflective; }
	bool isInteractable() const { return interactable; }

	// other getters
};