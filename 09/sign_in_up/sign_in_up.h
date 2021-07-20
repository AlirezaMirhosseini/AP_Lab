#ifndef SIGN_IN_UP_H
#define SIGN_IN_UP_H

#include <QWidget>
#include <QFormLayout>
#include <QGridLayout>
#include <QComboBox>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include <QGroupBox>
#include <QString>
#include "sign_up.h"

QT_BEGIN_NAMESPACE
namespace Ui { class sign_in_up; }
QT_END_NAMESPACE

class sign_in_up : public QWidget
{
    Q_OBJECT

public:
    sign_in_up(QWidget *parent = nullptr);
    ~sign_in_up();

public slots:
    void CHeck();
    void openNewPage();
signals:
    //void sayStatus();

private:
    QGridLayout* gdl;
    QLabel* lblUser;
    QLabel* lblPass;
    QLabel* lblAnswer;
    QLineEdit* ledUser;
    QLineEdit* ledPass;
    QLabel* lbl_Answer;
    QPushButton* pbn_login;
    QPushButton* pbn_sign_up;

    sign_up* sign_up_window;
};
#endif // SIGN_IN_UP_H
