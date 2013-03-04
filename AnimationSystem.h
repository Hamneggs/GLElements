#include "Animation.h"
#include <vector>

/*
	This class is an Animation System. It is meant to represent a single entity that has
	various states of animation.
	
	USAGE:
	==================================================================================
		To use an Animation System you must first provide it with at least one
	state, and set it's location and size. Then you may select the state and draw the
	System. Drawing the System will render the Animation of the current ANIM_STATE
	at the current location and size of the Animation System.
		This is meant for entities that have various states, such as characters in a 
	2-D game, e.g. Running, Jumping, walking, falling, etc.
*/

/*
A struct that binds an Animation to a state.
*/
struct ANIM_STATE
{
	/*
	The Animation bound to this state.
	*/
	Animation * anim;
	
	/*
	The integer identifier of this state.
	*/
	unsigned int stateID;
}

class AnimationSystem
{

	public:
	
		/*
		Constructs the Animation System.
		*/
		AnimationSystem();
		
		/*
		Destructs the Animation System.
		*/
		~AnimationSystem();
			
		/*
		Initializes the Animation system by giving it a location and size.
		*/
		void init(float x, float y, float z, float width, float height);
			
		/*
		Adds a new Animation State to the system, allocating a new State ID that is
		returned.
		*/
		int addNewState(Animation * newAnimation);
			
		/*
		Adds an already created Animation State, if the StateID of this new state isn't
		already taken.
		*/
		bool addNewState(ANIM_STATE newState);
			
		/*
		Constructs and adds a new Animation State if the specified ID is not taken.
		*/
		bool addNewState(unsigned int newStateID, Animation * newAnimation);
			
		/*
		Replaces one state's Animation with a new Animation, if the state exists.
		*/
		bool replaceState(unsigned int stateIDToReplace, Animation * replacementAnimation);
			
		/*
		Deletes an Animation State, if the state exists.
		*/
		bool deleteState(unsigned int stateIDToDelete);
			
		/*
		Returns a state, if it exists.
		*/
		ANIM_STATE * getState(unsigned int stateID);
			
		/*
		Sets the current state to the one with the specified ID, if it exists.
		*/
		void setCurrentState(unsigned int stateID);
			
		/*
		Sets the location of the Animation System.
		*/
		void setLocation(float newX, float newY, float newZ);
			
		/*
		Changes the location of the Animation System.
		*/
		void chnageLocation(float changeX, float changeY, float changeZ);
			
		/*
		Sets the size of the Animation System.
		*/
		void setSize(float newWidth, float newHeight);
			
		/*
		Changes the size of the Animation System.
		*/
		void changeSize(float changeWidth, float changeHeight);
			
		/*
		Renders the Animation System.
		*/
		void drawSystem(void);
		
		/*
		Renders the Animation System at the given location.
		*/
		void drawSystem(float x, float y, float z);
		
	private:
			
		/*
		The Vector that stores the animation states of this System.
		*/
		std::vector<ANIM_STATE> states;
			
		/*
		The current State.
		*/
		ANIM_STATE currentState;
			
		/*
		The X location of the Animation System.
		*/
		float x;
			
		/*
		The Y location of the Animation System.
		*/
		float y;
			
		/*
		The Z location of the Animation System.
		*/
		float z;
			
		/*
		The width of the Animation System.
		*/
		float width;
			
		/*
		The height of the Animation System.
		*/
		float height;
		
};