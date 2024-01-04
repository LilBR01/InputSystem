#pragma once
#include <unordered_map>
#include "GLFW/glfw3.h"
#include "../InputDevice.h"


namespace inputsystem
{
	class Keyboard
	{
	private:
		std::unordered_map<InputKey, InputDeviceState> m_keyboardState{};

	public:
		std::unordered_map<InputKey, InputDeviceState> GetKeyboardState(int index);

		void UpdateKeyboardState(GLFWwindow* window);

	private:
		static InputKey FormKeyToInputKey(int key);
	};
}