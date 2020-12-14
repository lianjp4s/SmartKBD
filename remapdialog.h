#ifndef REMAPDIALOG_H
#define REMAPDIALOG_H

#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QKeyEvent>
#include <QShowEvent>
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
	QPushButton *okBtn;
	QPushButton *cancelBtn;

	int destKey;

signals:
	void keymapChanged(int keyval);

private slots:
	void keyPressEvent(QKeyEvent *event);
	void showEvent(QShowEvent *event);
	void on_okBtn_clicked();
	void on_cancelBtn_clicked();

public:
	void setDefaultKey(int keyval);
};

#endif // REMAPDIALOG_H
