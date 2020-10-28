#ifndef SETTINGWINDOW_H
#define SETTINGWINDOW_H

#include <QMainWindow>

#include <QMainWindow>
#include <QTimer>
#include <QDebug>
#include <qt_windows.h>

#include <QCloseEvent>

namespace Ui {
class SettingWindow;
}

class SettingWindow : public QMainWindow
{
	Q_OBJECT

public:
	explicit SettingWindow(QWidget *parent = nullptr);
	~SettingWindow();


private:
	Ui::SettingWindow *ui;
	HHOOK hhkLowLevelKybd;
	bool bWinKey;


private:
	void closeEvent(QCloseEvent *event);
};


#endif // SETTINGWINDOW_H
