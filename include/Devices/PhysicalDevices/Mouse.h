#pragma once
#include <unordered_map>
#include <GLFW/glfw3.h>
#include "../InputDevice.h"

namespace inputsystem
{
	class Mouse
	{
	private:
		std::unordered_map<InputKey, InputDeviceState> m_mouseState{};

	public:
		std::unordered_map<InputKey, InputDeviceState> GetMouseState(int index);

		void UpdateMouseState(GLFWwindow* window);

	private:
		static InputKey FormMouseButtonToInputKey(int button);
	};
}


