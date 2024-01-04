#include "Devices/PhysicalDevices/Keyboard.h"

namespace inputsystem
{
	std::unordered_map<InputKey, InputDeviceState> inputsystem::Keyboard::GetKeyboardState(int index)
	{
		return m_keyboardState;;
	}

	void Keyboard::UpdateKeyboardState(GLFWwindow* window)
	{
		for (int key = GLFW_KEY_UNKNOWN; key < GLFW_KEY_LAST; key++)
		{
			InputKey iKey = FormKeyToInputKey(key);
			if (iKey == InputKey::Unknown) continue;

			auto state = glfwGetKey(window, key);

			m_keyboardState[iKey].m_value = static_cast<float>(state);
		}
	}

	InputKey Keyboard::FormKeyToInputKey(int key)
	{
		switch (key)
		{
		case GLFW_KEY_A:
			return InputKey::KeyA;
        case GLFW_KEY_B:
            return InputKey::KeyB;
        case GLFW_KEY_C:
            return InputKey::KeyC;
        case GLFW_KEY_D:
            return InputKey::KeyD;
        case GLFW_KEY_E:
            return InputKey::KeyE;
        case GLFW_KEY_F:
            return InputKey::KeyF;
        case GLFW_KEY_G:
            return InputKey::KeyG;
        case GLFW_KEY_H:
            return InputKey::KeyH;
        case GLFW_KEY_I:
            return InputKey::KeyI;
        case GLFW_KEY_J:
            return InputKey::KeyJ;
        case GLFW_KEY_K:
            return InputKey::KeyK;
        case GLFW_KEY_L:
            return InputKey::KeyL;
        case GLFW_KEY_M:
            return InputKey::KeyM;
        case GLFW_KEY_N:
            return InputKey::KeyN;
        case GLFW_KEY_O:
            return InputKey::KeyO;
        case GLFW_KEY_P:
            return InputKey::KeyP;
        case GLFW_KEY_Q:
            return InputKey::KeyQ;
        case GLFW_KEY_R:
            return InputKey::KeyR;
        case GLFW_KEY_S:
            return InputKey::KeyS;
        case GLFW_KEY_T:
            return InputKey::KeyT;
        case GLFW_KEY_U:
            return InputKey::KeyU;
        case GLFW_KEY_V:
            return InputKey::KeyV;
        case GLFW_KEY_W:
            return InputKey::KeyW;
        case GLFW_KEY_X:
            return InputKey::KeyX;
        case GLFW_KEY_Y:
            return InputKey::KeyY;
        case GLFW_KEY_Z:
            return InputKey::KeyZ;
        case GLFW_KEY_LEFT_BRACKET:
            return InputKey::KeyBracketL;
        case GLFW_KEY_RIGHT_BRACKET:
            return InputKey::KeyBracketR;
        case GLFW_KEY_BACKSLASH:
            return InputKey::KeyBackslash;
        case GLFW_KEY_SEMICOLON:
            return InputKey::KeySemicolon;
        case GLFW_KEY_APOSTROPHE:
            return InputKey::KeyApostrophe;
        case GLFW_KEY_COMMA:
            return InputKey::KeyComma;
        case GLFW_KEY_PERIOD:
            return InputKey::KeyPeriod;
        case GLFW_KEY_SLASH:
            return InputKey::KeyForwardSlash;
        case GLFW_KEY_GRAVE_ACCENT:
            return InputKey::KeyTilde;
        case GLFW_KEY_ESCAPE:
            return InputKey::KeyEscape;
        case GLFW_KEY_F1:
            return InputKey::KeyF1;
        case GLFW_KEY_F2:
            return InputKey::KeyF2;
        case GLFW_KEY_F3:
            return InputKey::KeyF3;
        case GLFW_KEY_F4:
            return InputKey::KeyF4;
        case GLFW_KEY_F5:
            return InputKey::KeyF5;
        case GLFW_KEY_F6:
            return InputKey::KeyF6;
        case GLFW_KEY_F7:
            return InputKey::KeyF7;
        case GLFW_KEY_F8:
            return InputKey::KeyF8;
        case GLFW_KEY_F9:
            return InputKey::KeyF9;
        case GLFW_KEY_F10:
            return InputKey::KeyF10;
        case GLFW_KEY_F11:
            return InputKey::KeyF11;
        case GLFW_KEY_F12:
            return InputKey::KeyF12;
        case GLFW_KEY_PRINT_SCREEN:
            return InputKey::KeyPrintScreen;
        case GLFW_KEY_SCROLL_LOCK:
            return InputKey::KeyScrollLock;
        case GLFW_KEY_PAUSE:
            return InputKey::KeyPauseBreak;
        case GLFW_KEY_INSERT:
            return InputKey::KeyInsert;
        case GLFW_KEY_HOME:
            return InputKey::KeyHome;
        case GLFW_KEY_PAGE_UP:
            return InputKey::KeyPageUp;
        case GLFW_KEY_PAGE_DOWN:
            return InputKey::KeyPageDown;
        case GLFW_KEY_END:
            return InputKey::KeyEnd;
        case GLFW_KEY_DELETE:
            return InputKey::KeyDelete;
        case GLFW_KEY_BACKSPACE:
            return InputKey::KeyBackspace;
        case GLFW_KEY_UP:
            return InputKey::KeyArrowUp;
        case GLFW_KEY_LEFT:
            return InputKey::KeyArrowLeft;
        case GLFW_KEY_RIGHT:
            return InputKey::KeyArrowRight;
        case GLFW_KEY_DOWN:
            return InputKey::KeyArrowDown;
        case GLFW_KEY_TAB:
            return InputKey::KeyTab;
        case GLFW_KEY_CAPS_LOCK:
            return InputKey::KeyCapsLock;
        case GLFW_KEY_LEFT_SHIFT:
            return InputKey::KeyShiftLeft;
        case GLFW_KEY_RIGHT_SHIFT:
            return InputKey::KeyShiftRight;
        case GLFW_KEY_ENTER:
            return InputKey::KeyEnter;
        case GLFW_KEY_LEFT_CONTROL:
            return InputKey::KeyCtrlLeft;
        case GLFW_KEY_RIGHT_CONTROL:
            return InputKey::KeyCtrlRight;
        case GLFW_KEY_LEFT_ALT:
            return InputKey::KeyAltLeft;
        case GLFW_KEY_RIGHT_ALT:
            return InputKey::KeyAltRight;
        case GLFW_KEY_NUM_LOCK:
            return InputKey::KeyNumlock;
        case GLFW_KEY_KP_DIVIDE:
            return InputKey::KeyNumpadDivide;
        case GLFW_KEY_KP_MULTIPLY:
            return InputKey::KeyNumpadMultiply;
        case GLFW_KEY_KP_SUBTRACT:
            return InputKey::KeyNumpadMinus;
        case GLFW_KEY_KP_ADD:
            return InputKey::KeyNumpadPlus;
        case GLFW_KEY_KP_ENTER:
            return InputKey::KeyNumpadReturn;
        case GLFW_KEY_KP_DECIMAL:
            return InputKey::KeyNumpadPeriod;
        case GLFW_KEY_KP_0:
            return InputKey::KeyNumpad0;
        case GLFW_KEY_KP_1:
            return InputKey::KeyNumpad1;
        case GLFW_KEY_KP_2:
            return InputKey::KeyNumpad2;
        case GLFW_KEY_KP_3:
            return InputKey::KeyNumpad3;
        case GLFW_KEY_KP_4:
            return InputKey::KeyNumpad4;
        case GLFW_KEY_KP_5:
            return InputKey::KeyNumpad5;
        case GLFW_KEY_KP_6:
            return InputKey::KeyNumpad6;
        case GLFW_KEY_KP_7:
            return InputKey::KeyNumpad7;
        case GLFW_KEY_KP_8:
            return InputKey::KeyNumpad8;
        case GLFW_KEY_KP_9:
            return InputKey::KeyNumpad9;
		default:
			return InputKey::Unknown;
		}
	}
}
