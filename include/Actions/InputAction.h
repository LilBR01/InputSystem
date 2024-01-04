#pragma once
#include <string>
#include <functional>
#include "Devices/InputDevice.h"

namespace inputsystem
{
	struct InputAction
	{
		std::string m_actionName;
		float m_scale = 1.0f;
	};

	using ActionCallbackFunc = std::function<bool(PhysicalDevice, int, float)>;

	struct ActionCallback
	{
		std::string m_ref;
		ActionCallbackFunc Func;
	};

	struct ActionEvent
	{
		std::string m_actionName;
		PhysicalDevice m_device;
		int m_deviceIndex;
		float m_value;
	};
}

