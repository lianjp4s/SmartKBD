#ifndef TRAYMENU_H
#define TRAYMENU_H

#include <QMenu>


#include "mainwindow.h"

class TrayMenu : public QMenu
{
    Q_OBJECT

public:
    explicit TrayMenu(QWidget *parent = nullptr);
    ~TrayMenu();

signals:
    void showWindow();

private:
    QAction *pShowAction;
#if 0
    QAction *pSettingAction;
    QAction *pHomePageAction;
    QAction *pHelpAction;
    QAction *pAboutAction;
    QAction *pUpgradeAction;
    QAction *pQuitAction;
#endif
    MainWindow *pConfigWindow;

private slots:
    void prvvShowConfigWindowSlot();
};


#endif // TRAYMENU_H
