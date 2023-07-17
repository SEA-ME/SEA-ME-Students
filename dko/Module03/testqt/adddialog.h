#ifndef ADDDIALOG_H
#define ADDDIALOG_H

#include <QDialog>
#include <QCheckBox>

QT_BEGIN_NAMESPACE
class QLabel;
class QPushButton;
class QLineEdit;
QT_END_NAMESPACE

//! [0]
class AddDialog : public QDialog
{
    Q_OBJECT

public:
    AddDialog(QWidget *parent = 0);
    QLineEdit *nameText;
    QLineEdit *phoneText;
    QLineEdit *emailText;
    QCheckBox *bookmarkCheckbox;
private:
    QLabel *nameLabel;
    QLabel *phoneLabel;
    QLabel *emailLabel;
    QLabel *bookmarkLabel;  // Checkbox label
    QPushButton *okButton;
    QPushButton *cancelButton;
    //QCheckBox *bookmarkCheckbox;
};
//! [0]

#endif // ADDDIALOG_H
