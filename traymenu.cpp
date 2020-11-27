#include "traymenu.h"

#include <QApplication>
#include <QMessageBox>

TrayMenu::TrayMenu(QWidget *parent) : QMenu(parent)
{
	pShowSettingAction = new QAction(tr("显示设置窗口"));
	pQuitAction = new QAction(tr("退出"));
	this->addAction(pShowSettingAction);
	this->addAction(pQuitAction);

	pConfigWindow = new SettingWindow;

	connect(pShowSettingAction, &QAction::triggered,
			this, &TrayMenu::on_pShowSettingAction_triggered);
	connect(pQuitAction, &QAction::triggered,
			this, &TrayMenu::on_pQuitAction_triggered);
}

void TrayMenu::on_pShowSettingAction_triggered()
{
	pConfigWindow->show();
}

void TrayMenu::on_pQuitAction_triggered()
{
	qApp->quit();
}

TrayMenu::~TrayMenu()
{
    delete pConfigWindow;
}
