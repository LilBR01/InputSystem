#include "Controls/InputControl.h"

namespace inputsystem
{
	PhysicalDevice InputControl::GetPhysicalDeviceFromKey(InputKey key)
	{
		if (key < InputKey::KeyMax)
		{
			return PhysicalDevice::Keyboard;
		}
		else if (key < InputKey::MouseMax)
		{
			return PhysicalDevice::Mouse;
		}
		//TODO::Gamepad

		return PhysicalDevice::Unknown;
	}
}