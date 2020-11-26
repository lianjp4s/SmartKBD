#include <QApplication>
#include <QSystemTrayIcon>

#include "traymenu.h"
#include "keyprocess.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

	KeyProcess *kProcess = new KeyProcess;
	kProcess->startProcess();

    TrayMenu *pTrayMenu = new TrayMenu;
    QSystemTrayIcon *pSysTrayIcon = new QSystemTrayIcon;
    pSysTrayIcon->setContextMenu(pTrayMenu);
	pSysTrayIcon->setToolTip("我就是托盘");
    pSysTrayIcon->setIcon(QIcon(":/icons/smkbd.png"));
    pSysTrayIcon->show();
    return a.exec();
}
