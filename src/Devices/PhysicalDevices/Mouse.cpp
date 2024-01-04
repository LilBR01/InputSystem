#include "Devices/PhysicalDevices/Mouse.h"

namespace inputsystem
{
	std::unordered_map<InputKey, InputDeviceState> Mouse::GetMouseState(int index)
	{
		return m_mouseState;
	}

	void Mouse::UpdateMouseState(GLFWwindow* window)
	{
		for (int button = GLFW_MOUSE_BUTTON_1; button < GLFW_MOUSE_BUTTON_LAST; button++)
		{
			InputKey iKey = FormMouseButtonToInputKey(button);
			if (iKey == InputKey::Unknown) continue;

			auto state = glfwGetMouseButton(window, button);
			m_mouseState[iKey].m_value = static_cast<float>(state);
		}

		float lastX = m_mouseState[InputKey::MouseX].m_value;
		float lastY = m_mouseState[InputKey::MouseY].m_value;

		double x, y;
		glfwGetCursorPos(window, &x, &y);

		m_mouseState[InputKey::MouseMoveX].m_value = static_cast<float>(x) - lastX;
		m_mouseState[InputKey::MouseMoveY].m_value = static_cast<float>(y) - lastY;
		m_mouseState[InputKey::MouseX].m_value = static_cast<float>(x);
		m_mouseState[InputKey::MouseY].m_value = static_cast<float>(y);
	}

	InputKey Mouse::FormMouseButtonToInputKey(int button)
	{
		switch (button)
		{
			case GLFW_MOUSE_BUTTON_LEFT:
				return InputKey::MouseButtonLeft;
			case GLFW_MOUSE_BUTTON_RIGHT:
				return InputKey::MouseButtonRight;
			case GLFW_MOUSE_BUTTON_MIDDLE:
				return InputKey::MouseButtonMiddle;
			default:
				return InputKey::Unknown;
		}
	}
}