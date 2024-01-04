#pragma once
#include <functional>
#include"../Controls/InputControl.h"

namespace inputsystem
{
	enum class PhysicalDevice
	{
		Unknown,
		Keyboard,
		Mouse,
		//Gamepad,
	};

	struct InputDeviceState
	{
		float m_value = 0.0f;
	};

	using InputDeviceStateCallbackFunc = std::function<std::unordered_map<InputKey, InputDeviceState>(int)>;
	
	struct InputDevice
	{
		PhysicalDevice m_device;
		int m_index;
		std::unordered_map<InputKey, InputDeviceState> m_currentState;
        InputDeviceStateCallbackFunc StateFunc;
	};

    enum class InputKey
    {
        Unknown,

        KeyA,
        KeyB,
        KeyC,
        KeyD,
        KeyE,
        KeyF,
        KeyG,
        KeyH,
        KeyI,
        KeyJ,
        KeyK,
        KeyL,
        KeyM,
        KeyN,
        KeyO,
        KeyP,
        KeyQ,
        KeyR,
        KeyS,
        KeyT,
        KeyU,
        KeyV,
        KeyW,
        KeyX,
        KeyY,
        KeyZ,
        KeyBracketL,
        KeyBracketR,
        KeyBackslash,
        KeySemicolon,
        KeyApostrophe,
        KeyComma,
        KeyPeriod,
        KeyForwardSlash,
        KeyTilde,
        KeyEscape,
        KeyF1,
        KeyF2,
        KeyF3,
        KeyF4,
        KeyF5,
        KeyF6,
        KeyF7,
        KeyF8,
        KeyF9,
        KeyF10,
        KeyF11,
        KeyF12,
        KeyPrintScreen,
        KeyScrollLock,
        KeyPauseBreak,
        KeyInsert,
        KeyHome,
        KeyPageUp,
        KeyPageDown,
        KeyEnd,
        KeyDelete,
        KeyBackspace,
        KeyArrowUp,
        KeyArrowLeft,
        KeyArrowRight,
        KeyArrowDown,
        KeyTab,
        KeyCapsLock,
        KeyShiftLeft,
        KeyShiftRight,
        KeyEnter,
        KeyCtrlLeft,
        KeyCtrlRight,
        KeyAltLeft,
        KeyAltRight,
        KeyNumlock,
        KeyNumpadDivide,
        KeyNumpadMultiply,
        KeyNumpadMinus,
        KeyNumpadPlus,
        KeyNumpadReturn,
        KeyNumpadPeriod,
        KeyNumpad1,
        KeyNumpad2,
        KeyNumpad3,
        KeyNumpad4,
        KeyNumpad5,
        KeyNumpad6,
        KeyNumpad7,
        KeyNumpad8,
        KeyNumpad9,
        KeyNumpad0,
        KeyMax,

        MouseX,
        MouseY,
        MouseMoveX,
        MouseMoveY,
        MouseButtonRight,
        MouseButtonLeft,
        MouseButtonMiddle,
        MouseMax,

        //TODO:Gamepad
    };

}
