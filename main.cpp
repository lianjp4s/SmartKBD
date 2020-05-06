#include <QApplication>
#include <QSystemTrayIcon>

#include "traymenu.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TrayMenu *pTrayMenu = new TrayMenu;
    QSystemTrayIcon *pSysTrayIcon = new QSystemTrayIcon;
    pSysTrayIcon->setContextMenu(pTrayMenu);
    pSysTrayIcon->setToolTip(QString::fromLocal8Bit("我就是托盘"));
    pSysTrayIcon->setIcon(QIcon(":/icons/smkbd.png"));
    pSysTrayIcon->show();
    return a.exec();
}
