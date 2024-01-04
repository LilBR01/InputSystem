#pragma once
#include <Devices/InputDevice.h>

namespace inputsystem
{
	class InputControl
	{
	public:


	private:
		InputKey m_inputKey;

	public:
		static PhysicalDevice GetPhysicalDeviceFromKey(InputKey key);
	};

}