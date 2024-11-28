#pragma once
#include <iostream>
#include <unordered_map>
#include <vector>
#include <functional>
#include <optional>
#include <array>
#include "../utils/Singleton.h"

#define TS_ENABLE_CONTROLLER_SUPPORT
namespace Techstorm {
	
	/// <summary>
	/// The enumeration for the different input device categories. This is here because the input system is going to be expanded in the future and it will be useful to maintaining developer sanity.
	/// </summary>
	enum class EInputType {
		INPUT_KEYBOARD,
		INPUT_MOUSE,
		INPUT_CONTROLLER
	};
	
	/// <summary>
	/// What sort of action should trigger the InputAction? <b>Please pay attention when using this because any slight change in InputAction keys will give you entirely different input results.</b>
	/// </summary>
	enum class EInputTrigger {
		INPUT_TRIGGER_PRESSED,
		INPUT_TRIGGER_RELEASED,
		INPUT_TRIGGER_DOWN,
		INPUT_TRIGGER_UP,
		INPUT_TRIGGER_REPEAT
	};
	
	/// <summary>
	/// Serves as a search key/input category for the input system. 
	/// <b>Please pay attention when using this because any slight change in InputAction keys will give you entirely different input results.</b>
	/// </summary>
	/// <remarks>
	/// InputAction contains a name (std::string), an key (int), a device type (<see cref="EInputType"/>) and a trigger (<see cref="EInputTrigger"/>) that will be used to distinguish between
	/// different InputActions. Not only will it act as a key, but it will also act as a category. 
	/// </remarks>
	class InputAction {
	public:
		std::string name;
		int key;
		EInputType type;
		EInputTrigger trigger;
	};

	/// <summary>
	/// The input registry is used to register InputActions (<see cref="InputAction"/>) and their callbacks. Remember that this is a singleton, so you may use this statically.
	/// </summary>
	/// <seealso cref="Singleton&lt;InputRegistry&gt;" />
	class InputRegistry : public Singleton<InputRegistry> {
	public:

		/// <summary>
		/// Registers a pointer of InputAction to the callback given. This works as a key-value pair, where the key is the action and the 
		/// value is the callback and is the reason why the return value is important. Please do not lose it or you will not be able to unregister the callback or you may unregister the wrong one!
		/// </summary>
		/// <param name="action">The InputAction to be used as a key.</param>
		/// <param name="callback">The callback that will be used to handle the InputAction.</param>
		/// <returns>The ID <b>of the callback</b>.</returns>
		int registerActionCallback(InputAction* action, std::function<void(InputAction*)> const& callback);
				
		/// <summary>
		/// Unregisters <b>ALL</b> callbacks for a given InputAction. This is useful if a keybind is no longer needed and you want to remove all callbacks in that category from the input system. 
		/// For example, this is useful when the player is joining a game. See <see cref="InputAction"/> for more information on what an InputAction is.
		/// </summary>
		/// <param name="action">The input action to unregister.</param>
		void unregisterAction(InputAction* action);
		
		/// <summary>
		/// Unregisters a specific callback for a given InputAction. 
		/// </summary>
		/// <param name="action">The action that owns the callback.</param>
		/// <param name="id">The callback's (the one being unregistered) identifier.</param>
		void unregisterCallback(InputAction* action, int id);
		

	protected:
		/// <summary>
		/// Checks all registered InputActions for callbacks. Without this, the callbacks won't be called and the input system is as useful as gloves are to an armless person.
		/// </summary>
		void checkAll();

	private:
#ifdef TS_ENABLE_CONTROLLER_SUPPORT

#endif
		
	private:
#ifdef TS_ENABLE_CONTROLLER_SUPPORT
		const float cLeftStickDeadzoneX = 0.1f;
		const float cLeftStickDeadzoneY = 0.1f;
		const float cRightStickDeadzoneX = 0.1f;
		const float cRightStickDeadzoneY = 0.1f;
		const float cLeftTriggerDeadzone = -0.9f;
		const float cRightTriggerDeadzone = -0.9f;
#endif
		std::unordered_map<InputAction*, std::unordered_map<int, std::function<void(InputAction*)>>> mActions;
	};
	
/*	/// <summary>
	/// Gets the current instance of the InputRegistry singleton <see cref="InputRegistry"/>. This is a quality of life function, and calling it like other singletons is perfectly okay.
	/// </summary>
	/// <returns>A reference to the current instance of the InputRegistry singleton.</returns>
	InputRegistry& GetInputRegistry() { return InputRegistry::Instance(); }
			
	/// <summary>
	/// Registers a callback by using the provided action (<see cref="InputAction"/>) and the callback parameter values. This works as a key-value pair, where the key is the action and the 
	/// value is the callback. This works the same way as the RegisterActionCallback function (InputRegistry::registerActionCallback), but it registers the callback
	/// in the current input registry (<see cref="InputRegistry"/>). This is simply a quality of life function, and calling it like other singletons is perfectly okay.
	/// </summary>
	/// <param name="action">The action.</param>
	/// <param name="callback">The callback.</param>
	int RegisterActionCallback(InputAction* action, std::function<void(InputAction*)> const& callback) { return GetInputRegistry().registerActionCallback(action, callback); }
	
	/// <summary>
	/// Unregisters ALL callbacks for the provided InputAction; action (<see cref="InputAction"/>), and unregisters it from the current input registry (<see cref="InputRegistry"/>). 
	/// This is simply a quality of life function, and calling it like other singletons is perfectly okay.
	/// </summary>
	/// <param name="action">The action that will have its callbacks deleted.</param>
	void UnregisterAction(InputAction* action) { GetInputRegistry().unregisterAction(action); }
		
	/// <summary>
	/// Unregisters a specific callback, denoted by id, for the provided InputAction; action (<see cref="InputAction"/>). This is simply a quality of life function, and calling it like 
	/// other singletons is perfectly okay.
	/// </summary>
	/// <param name="action">The action that the callback lies in.</param>
	/// <param name="id">The ID of the callback. You should have gotten it in the RegisterActionCallback or InputRegistry::registerActionCallback functions.</param>
	void UnregisterCallback(InputAction* action, int id) { GetInputRegistry().unregisterCallback(action, id); }*/

}