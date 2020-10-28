#ifndef TRAYMENU_H
#define TRAYMENU_H

#include <QMenu>


#include "settingwindow.h"

class TrayMenu : public QMenu
{
    Q_OBJECT

public:
    explicit TrayMenu(QWidget *parent = nullptr);
    ~TrayMenu();

signals:
    void showWindow();

private:
	QAction *pShowSettingAction;
#if 0
    QAction *pSettingAction;
    QAction *pHomePageAction;
    QAction *pHelpAction;
    QAction *pAboutAction;
    QAction *pUpgradeAction;
#endif
	QAction *pQuitAction;
	SettingWindow *pConfigWindow;

private slots:
	void on_pShowSettingAction_triggered();
	void on_pQuitAction_triggered();
};


#endif // TRAYMENU_H
