#include "traymenu.h"

TrayMenu::TrayMenu(QWidget *parent) : QMenu(parent)
{
    pShowAction = new QAction(tr("显示设置窗口"));
    pConfigWindow = new MainWindow;

    connect(pShowAction, &QAction::triggered, this, &TrayMenu::prvvShowConfigWindowSlot);
}

void TrayMenu::prvvShowConfigWindowSlot()
{
    pConfigWindow->show();
}

TrayMenu::~TrayMenu()
{
    delete pConfigWindow;
}
