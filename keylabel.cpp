#include "keylabel.h"
#include "keyname.h"

#include <QDebug>

KeyLabel::KeyLabel(int keyID, QWidget *parent) : QLabel(parent)
{
	m_keyID = keyID;
	this->setText(KeyNameList.at(keyID));
	this->setStyleSheet("background-color:white");
	this->setStyleSheet("border:2px solid black");
	remapDialog = new RemapDialog;

	connect(remapDialog, &RemapDialog::keymapChanged, this, &KeyLabel::on_remapDialog_keymapChanged);
}

void KeyLabel::setLocation(int x, int y, int width)
{
	m_xPos = x;
	m_yPos = y;
	m_width = width;
}

void KeyLabel::mousePressEvent(QMouseEvent *event)
{
	if (event->button() != Qt::RightButton) {
		event->ignore();
		return;
	}
	qDebug() << KeyNameList.at(m_keyID);
}

void KeyLabel::mouseDoubleClickEvent(QMouseEvent *event)
{
	if (event->button() != Qt::LeftButton) {
		event->ignore();
		return;
	}
	remapDialog->setDefaultKey(m_keyID);
	remapDialog->exec();
	event->accept();
}

void KeyLabel::on_remapDialog_keymapChanged(int keyval)
{
	QFile tmpJFile("./keymap.json");
	if (!tmpJFile.open(QIODevice::ReadWrite | QIODevice::Truncate)) {
		//QMessageBox::warning(this, tr("错误"), tr("打开配置文件失败"));
		qDebug() << "刷新配置失败！";
		return;
	}
	QJsonDocument tmpJDoc = QJsonDocument::fromJson(tmpJFile.readAll());
	QJsonObject tmpJObj = tmpJDoc.object();
	QJsonArray tmpJArray = tmpJObj["map"].toArray();
	qDebug() << tmpJArray;
	QJsonObject tmpJObj1;
	tmpJObj1.insert("KeyVal", keyval);
	tmpJArray.replace(m_keyID, tmpJObj1);
	tmpJObj["map"] = tmpJArray;
	tmpJDoc.setObject(tmpJObj);
	tmpJFile.write(tmpJDoc.toJson());
	tmpJFile.close();
}
