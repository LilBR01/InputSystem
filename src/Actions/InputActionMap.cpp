#include "Actions/InputActionMap.h"


namespace inputsystem
{
	void InputActionMap::RegisterDevice(const PhysicalDevice& device)
	{
		m_devices.emplace_back(device);
	}

	void InputActionMap::RemoveDevice(PhysicalDevice deviceType, int inputIndex)
	{
		auto isDevice = [deviceType, inputIndex](const InputDevice& device)
		{
			return device.m_device == deviceType && device.m_index == inputIndex;
		};

		std::erase_if(m_devices, isDevice);	
	}

	void InputActionMap::RegisterActionCallback(const std::string& actionName, const ActionCallback& callback)
	{
		m_actionCallbackMapping[actionName].emplace_back(callback);
	}

	void InputActionMap::RemoveActionCallback(const std::string& actionName, const std::string& callbackRef)
	{
		auto isRef = [callbackRef](const ActionCallback& callback)
		{
			return callback.m_ref == callbackRef;
		};

		std::erase_if(m_actionCallbackMapping[actionName], isRef);
	}

	void InputActionMap::MapInputToAction(InputKey key, const InputAction& action)
	{
		m_inputKeyMapping[key].emplace_back(action);
		m_inputActionMapping[action.m_actionName].emplace_back(key);
	}

	void InputActionMap::UnmapInputFromAction(InputKey key, const std::string& action)
	{
		auto isKey = [key](const InputKey& inputKey)
		{
			return key == inputKey;
		};
		std::erase_if(m_inputActionMapping, isKey);

		auto isAction = [action](const InputAction& inputAction)
		{
			return inputAction.m_actionName == action;
		};
		std::erase_if(m_inputKeyMapping[key], isAction);
	}

	float InputActionMap::GetActionValue(const std::string& actionName)
	{
		auto& keys = m_inputActionMapping[actionName];

		if (keys.empty())
		{
			return 0.0f;
		}

		float value = 0.0f;
		InputKey theKey = InputKey::Unknown;

		for (auto& key : keys)
		{
			auto device = InputControl::GetPhysicalDeviceFromKey(key);

			for(auto& iDevice : m_devices)
			{
				auto state = iDevice.StateFunc(iDevice.m_index);
			}
		}
		return 0.0f;
	}

	void InputActionMap::ProcessInput()
	{
		for(auto& device : m_devices)
		{
			auto newState = device.StateFunc(device.m_index);

		}
	}

	void InputActionMap::PropagateActionEvent(const ActionEvent& event)
	{
		if (size_t i = m_actionCallbackMapping[event.m_actionName].empty()) return;
		for (size_t i = m_actionCallbackMapping[event.m_actionName].size() - 1; i >= 0; i--)
		{
			auto& actionCallback = m_actionCallbackMapping[event.m_actionName][i];

			if (actionCallback.Func(event.m_device, event.m_deviceIndex, event.m_value)) break;
		}
	}
	
	std::vector<ActionEvent> InputActionMap::GenerateActionEvent(int deviceIndex, InputKey key, float newValue)
	{
		auto& actions = m_inputKeyMapping[key];

		std::vector<ActionEvent> actionEvents{};

		PhysicalDevice device = InputControl::GetPhysicalDeviceFromKey(key);

		for (auto& action : actions)
		{
			actionEvents.emplace_back(ActionEvent{
				 .m_actionName = action.m_actionName,
				 .m_device = device,
				 .m_deviceIndex = deviceIndex,
				 .m_value = newValue * action.m_scale
				});
		}

		return actionEvents;
	}
}
