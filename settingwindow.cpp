#include "settingwindow.h"

#include <QDebug>
#include <QMessageBox>


SettingWindow::SettingWindow(QWidget *parent) :
	QMainWindow(parent)
{

	mapWidget = new QWidget;
	mapLyt = new QGridLayout(mapWidget);

	locationConfigFile = new QFile("./locationConfig.json");
	if (!locationConfigFile->open(QIODevice::ReadWrite)) {
		QMessageBox::warning(this, tr("错误"), tr("打开配置文件失败"));
		return;
	}
	QJsonDocument tmpJDoc = QJsonDocument::fromJson(locationConfigFile->readAll());
	QJsonObject tmpJObj = tmpJDoc.object();
	QJsonArray tmpJArray = tmpJObj["config"].toArray();
	int tmpY = 0;
	int tmpX = 0;
	for (quint8 i = 0; i < tmpJArray.size(); i++) {
		tmpJObj = tmpJArray.at(i).toObject();
		auto *keyLabel = new KeyLabel(tmpJObj["KeyID"].toInt());
		if (tmpY != tmpJObj["yPos"].toInt()) {
			tmpY = tmpJObj["yPos"].toInt();
			tmpX = 0;
		}
		//qDebug() << "Key : " << keyLabel->text() << "\t\t\t" << "y : " << tmpY << "x : " << tmpX;
		mapLyt->addWidget(keyLabel, tmpY, tmpX, 1, tmpJObj["width"].toInt());
		tmpX += tmpJObj["width"].toInt();
	}
	locationConfigFile->close();
	this->setCentralWidget(mapWidget);
	this->setStyleSheet("font-family: Fantasque Sans Mono; font-size: 12pt");

}

SettingWindow::~SettingWindow()
{
}

void SettingWindow::closeEvent(QCloseEvent *event)
{
	hide();
	event->ignore();
}
