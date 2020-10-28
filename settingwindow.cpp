#include "settingwindow.h"
#include "ui_settingwindow.h"

// Crosslink between Qt class and win callback
SettingWindow * mwReference;

LRESULT CALLBACK LowLevelKeyboardProc(int nCode, WPARAM wParam, LPARAM lParam)
{
	if (nCode == HC_ACTION)
	{
		switch (wParam)
		{
			// Pass KeyDown/KeyUp messages for Qt class to logicize
		case WM_KEYDOWN:
			qDebug() << "pressed";
			break;
		case WM_SYSKEYDOWN:
			qDebug() << "pressed";
			break;
		case WM_KEYUP:
			qDebug() << "released";
			break;
		}
	}
	return CallNextHookEx(nullptr, nCode, wParam, lParam);
	return 1;
}



SettingWindow::SettingWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::SettingWindow)
{
	ui->setupUi(this);

	// Setup variables
	mwReference = this;
	bWinKey     = false;

	// Install the low-level keyboard & mouse hooks
	hhkLowLevelKybd = SetWindowsHookEx(WH_KEYBOARD_LL, LowLevelKeyboardProc, nullptr, 0);

	QPixmap bacMap(":/pics/layout.png");

	QPalette bacPalette = this->palette();
	bacPalette.setBrush(QPalette::Background, QBrush(QPixmap(":/pics/layout.png")));

	ui->widget->setPalette(bacPalette);

}

SettingWindow::~SettingWindow()
{
	// Be friendly! Remove hooks!
	UnhookWindowsHookEx(hhkLowLevelKybd);
	delete ui;
}

void SettingWindow::closeEvent(QCloseEvent *event)
{
	hide();
	event->ignore();
}
