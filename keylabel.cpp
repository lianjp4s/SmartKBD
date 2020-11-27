#include "keylabel.h"
#include "keyname.h"

#include <QDebug>

KeyLabel::KeyLabel(quint8 keyID, QWidget *parent) : QLabel(parent)
{
	m_keyID = keyID;
	this->setText(KeyNameList.at(keyID));
	this->setStyleSheet("background-color:white");
	this->setStyleSheet("border:2px solid black");
	remapDialog = new RemapDialog;
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
	remapDialog->exec();
	event->accept();
}
