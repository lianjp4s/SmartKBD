#include "keylabel.h"
#include "keyname.h"

#include <QDebug>

KeyLabel::KeyLabel(quint8 keyID, QWidget *parent) : QLabel(parent)
{
	m_keyID = keyID;
	this->setText(KeyNameList.at(keyID));
	this->setStyleSheet("border:1px solid black");
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
	qDebug() << KeyNameList.at(m_keyID);
	event->accept();
}
