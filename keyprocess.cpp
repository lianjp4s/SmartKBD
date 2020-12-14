#include "keyprocess.h"
#include <QMessageBox>
#include <QDebug>
#include "keyname.h"


// Crosslink between Qt class and win callback
KeyProcess * kpReference;

static DWORD m_vkcode;

QJsonArray keymapJArray;

LRESULT CALLBACK LowLevelKeyboardProc(int nCode, WPARAM wParam, LPARAM lParam)
{
	LPKBDLLHOOKSTRUCT tmpData = (LPKBDLLHOOKSTRUCT)lParam;
#if 1
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
#endif
	((LPKBDLLHOOKSTRUCT)lParam)->vkCode = keymapJArray.at(tmpData->vkCode)["KeyVal"].toInt();
#if 0
	if (tmpData->vkCode == eKey_A) {
		((LPKBDLLHOOKSTRUCT)lParam)->vkCode = eKey_0;
	}
	qDebug() << KeyNameList.at(tmpData->vkCode);
#endif
	return CallNextHookEx(nullptr, nCode, wParam, lParam);
}


void KeyProcess::refreshKeyMap()
{
	QFile tmpJFile("./keymap.json");
	if (!tmpJFile.open(QIODevice::ReadWrite)) {
		//QMessageBox::warning(this, tr("错误"), tr("打开配置文件失败"));
		qDebug() << "刷新配置失败！";
		return;
	}
	QJsonDocument tmpJDoc = QJsonDocument::fromJson(tmpJFile.readAll());
	QJsonObject tmpJObj = tmpJDoc.object();
	keymapJArray = tmpJObj["map"].toArray();
	tmpJFile.close();
}


KeyProcess::KeyProcess()
{
	kpReference = this;
	refreshKeyMap();
}

int lKeyProcessGetVKCode()
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
