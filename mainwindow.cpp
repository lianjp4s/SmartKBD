#include "mainwindow.h"
#include "ui_mainwindow.h"

// Crosslink between Qt class and win callback
MainWindow * mwReference;

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
    //return CallNextHookEx(nullptr, nCode, wParam, lParam);
    return 1;
}



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Setup variables
    mwReference = this;
    bWinKey     = false;

    // Install the low-level keyboard & mouse hooks
    hhkLowLevelKybd = SetWindowsHookEx(WH_KEYBOARD_LL, LowLevelKeyboardProc, nullptr, 0);
}

MainWindow::~MainWindow()
{
    // Be friendly! Remove hooks!
    UnhookWindowsHookEx(hhkLowLevelKybd);
    delete ui;
}
