#include "sign_up.h"

sign_up::sign_up(QWidget *parent) : QWidget(parent)
{

}
sign_up::sign_up(QString str){
    setWindowTitle("Sign up");

    gdl = new QGridLayout();
    gdl->setSizeConstraint(QLayout::SetFixedSize);//_____________________________________________
    // Labels
    lbl_firstName = new QLabel("First name: ");
    lbl_lastName = new QLabel("Last name: ");
    lbl_gender = new QLabel("Gender: ");
    lbl_userName = new QLabel("Username: ");
    lbl_email = new QLabel("Email: ");
    lbl_password = new QLabel("Password: ");
    lbl_answer = new QLabel("Enter information");
    // Line Edits and Combo Box
    led_firstName = new QLineEdit();
    led_lastName = new QLineEdit();
    cmb_gender = new QComboBox();
    led_userName = new QLineEdit();
    led_email = new QLineEdit();
    led_password = new QLineEdit();
    led_password->setEchoMode(QLineEdit::Password);
    // Push Button
    pbn_final = new QPushButton("Create Account");
    // Grid Layout Labels
    gdl->addWidget(lbl_firstName,0,0);
    gdl->addWidget(lbl_lastName,1,0);
    gdl->addWidget(lbl_gender,2,0);
    gdl->addWidget(lbl_userName,3,0);
    gdl->addWidget(lbl_email,4,0);
    gdl->addWidget(lbl_password,5,0);
    gdl->addWidget(lbl_answer,7,0,1,2);
    // Grid Layout Line Edit and Combo Box
    gdl->addWidget(led_firstName,0,1);
    gdl->addWidget(led_lastName,1,1);
    gdl->addWidget(cmb_gender,2,1);
    cmb_gender->addItem("Female");
    cmb_gender->addItem("Male");
    gdl->addWidget(led_userName,3,1);
    gdl->addWidget(led_email,4,1);
    gdl->addWidget(led_password,5,1);
    led_password->setEchoMode(QLineEdit::Password);
    gdl->addWidget(pbn_final,6,1);

    setLayout(gdl);

    connect(pbn_final,SIGNAL(clicked()),this,SLOT(Save_info()));
//    connect(pbn_final,SIGNAL(clicked()),this,SLOT(close()));
}
void sign_up::Save_info(){
    if (led_firstName->text().isEmpty() ||
           led_lastName->text().isEmpty() ||
           led_userName->text().isEmpty() ||
           led_email->text().isEmpty() ||
           led_password->text().isEmpty())
        lbl_answer->setText("Information must be complete !!!");
    else{
        Usernames.push_back(led_userName->text());
        Passwords.push_back(led_password->text());
        led_firstName->clear();
        led_lastName->clear();
        led_userName->clear();
        led_email->clear();
        led_password->clear();
        lbl_answer->setText("Enter information");
        close();
    }
}
QVector<QString> sign_up::get_usernames(){return Usernames;}
QVector<QString> sign_up::get_passwords(){return Passwords;}
