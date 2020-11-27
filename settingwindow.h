#ifndef SETTINGWINDOW_H
#define SETTINGWINDOW_H

#include <QMainWindow>

#include <QMainWindow>
#include <QGridLayout>
#include <QWidget>
#include <QTimer>

#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>
#include <QFile>

#include <QCloseEvent>
#include "keylabel.h"

class SettingWindow : public QMainWindow
{
	Q_OBJECT

public:
	explicit SettingWindow(QWidget *parent = nullptr);
	~SettingWindow();


private:
	QGridLayout *mapLyt;
	QWidget *mapWidget;

	QList <KeyLabel *> keyLabels;

	QJsonObject *locationConfig;
	QJsonDocument *locationConfigDoc;
	QFile *locationConfigFile;


private:
	void closeEvent(QCloseEvent *event);
};


#endif // SETTINGWINDOW_H
