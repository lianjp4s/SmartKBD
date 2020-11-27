#include "keyprocess.h"
#include <QDebug>


// Crosslink between Qt class and win callback
KeyProcess * kpReference;

static DWORD m_vkcode;

LRESULT CALLBACK LowLevelKeyboardProc(int nCode, WPARAM wParam, LPARAM lParam)
{
	LPKBDLLHOOKSTRUCT tmpData = (LPKBDLLHOOKSTRUCT)lParam;
	if (nCode == HC_ACTION)
	{
		switch (wParam)
		{
			// Pass KeyDown/KeyUp messages for Qt class to logicize
		case WM_KEYDOWN:
			m_vkcode = tmpData->vkCode;
			break;
		case WM_SYSKEYDOWN:
			m_vkcode = tmpData->vkCode;
			break;
		case WM_KEYUP:
			//qDebug() << "released";
			break;
		}
	}
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

int lKeyPrecessGetVKCode()
{
	return m_vkcode;
}

KeyProcess::~KeyProcess()
{
	UnhookWindowsHookEx(hhkLowLevelKybd);
}

void KeyProcess::startProcess()
{
	hhkLowLevelKybd = SetWindowsHookEx(WH_KEYBOARD_LL, LowLevelKeyboardProc, nullptr, 0);
}
