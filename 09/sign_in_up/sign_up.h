#ifndef SIGN_UP_H
#define SIGN_UP_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QComboBox>
#include <QPushButton>
#include <QGridLayout>
#include <QString>
#include <QVector>

class sign_up : public QWidget
{
    Q_OBJECT
public:
    explicit sign_up(QWidget *parent = nullptr);
    sign_up(QString);
    QVector<QString> get_usernames();
    QVector<QString> get_passwords();
public slots:
    void Save_info();
signals:
private:
    QVector<QString> Usernames;
    QVector<QString> Passwords;
    int vector_size;
    QGridLayout *gdl;
    // Labels
    QLabel *lbl_firstName;
    QLabel *lbl_lastName;
    QLabel *lbl_gender;
    QLabel *lbl_userName;
    QLabel *lbl_email;
    QLabel *lbl_password;
    QLabel *lbl_answer;
    // Line Edits and Combo Box
    QLineEdit *led_firstName;
    QLineEdit *led_lastName;
    QComboBox *cmb_gender;
    QLineEdit *led_userName;
    QLineEdit *led_email;
    QLineEdit *led_password;

    // Push Button
    QPushButton *pbn_final;
};

#endif // SIGN_UP_H
