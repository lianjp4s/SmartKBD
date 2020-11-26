#include "keyprocess.h"
#include <QDebug>


// Crosslink between Qt class and win callback
KeyProcess * kpReference;

LRESULT CALLBACK LowLevelKeyboardProc(int nCode, WPARAM wParam, LPARAM lParam)
{
	if (nCode == HC_ACTION)
	{
		switch (wParam)
		{
			// Pass KeyDown/KeyUp messages for Qt class to logicize
		case WM_KEYDOWN:
			//qDebug() << "pressed";
			break;
		case WM_SYSKEYDOWN:
			//qDebug() << "pressed";
			break;
		case WM_KEYUP:
			//qDebug() << "released";
			break;
		}
	}
	LPKBDLLHOOKSTRUCT tmpData = (LPKBDLLHOOKSTRUCT)lParam;
#if 0
	if (tmpData->vkCode == eKey_A) {
		((LPKBDLLHOOKSTRUCT)lParam)->vkCode = eKey_0;
	}
	qDebug() << KeyNameList.at(tmpData->vkCode);
#endif
	return CallNextHookEx(nullptr, nCode, wParam, lParam);
}



KeyProcess::KeyProcess()
{
	kpReference = this;

}

KeyProcess::~KeyProcess()
{
	UnhookWindowsHookEx(hhkLowLevelKybd);
}

void KeyProcess::startProcess()
{
	hhkLowLevelKybd = SetWindowsHookEx(WH_KEYBOARD_LL, LowLevelKeyboardProc, nullptr, 0);
}
