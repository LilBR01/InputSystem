#pragma once
#include "Actions/InputActionMap.h"

namespace inputsystem
{

	class InputSystem
	{
	public:
		InputSystem();
		~InputSystem();

	private:
		bool m_actived;
		InputActionMap& m_actionMapping;

	private:


	};
}
