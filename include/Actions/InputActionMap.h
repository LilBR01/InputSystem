#pragma once
#include <unordered_map>
#include <vector>
#include "Actions/InputAction.h"
#include "Controls/InputControl.h"
#include "Devices/InputDevice.h"

namespace inputsystem
{
	class InputActionMap
	{
	private:
		std::vector<InputDevice> m_devices;
		 
		std::unordered_map<InputKey, std::vector<InputAction>> m_inputKeyMapping{};
		
		std::unordered_map<std::string, std::vector<InputKey>> m_inputActionMapping{};
		std::unordered_map<std::string, std::vector<ActionCallback>> m_actionCallbackMapping{};

	public:
		InputActionMap() = default;

		void RegisterDevice(const PhysicalDevice& device);
		void RemoveDevice(PhysicalDevice device, int inputIndex);

		void RegisterActionCallback(const std::string& actionName, const ActionCallback& callback);
		void RemoveActionCallback(const std::string& actionName, const std::string& callbackRef);

		void MapInputToAction(InputKey key, const InputAction& action);
		void UnmapInputFromAction(InputKey key, const std::string& action);

		float GetActionValue(const std::string& actionName);

		void ProcessInput();
		void PropagateActionEvent(const ActionEvent& event);
		std::vector<ActionEvent> GenerateActionEvent(int deviceIndex, InputKey key, float newValue);
	};
}

