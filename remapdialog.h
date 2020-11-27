#ifndef REMAPDIALOG_H
#define REMAPDIALOG_H

#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QKeyEvent>
#include <QGridLayout>

class RemapDialog : public QDialog
{
	Q_OBJECT
public:
	explicit RemapDialog(QWidget *parent = nullptr);
private:
	QLabel *tipLbl;
	QLineEdit *settingKeyLEdit;
	QGridLayout *mainLyt;

private slots:
	void keyPressEvent(QKeyEvent *event);
};

#endif // REMAPDIALOG_H
