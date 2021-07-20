#include "sign_in_up.h"
#include "./ui_sign_in_up.h"

sign_in_up::sign_in_up(QWidget *parent)
    : QWidget(parent)

{
    setWindowTitle("Login");
    gdl=new QGridLayout;
    lblUser=new QLabel;
    lblPass=new QLabel;
    lblAnswer = new QLabel("Result :");
    ledUser=new QLineEdit;
    ledPass=new QLineEdit;
    lbl_Answer = new QLabel("Indeterminate!");
    pbn_login = new QPushButton("Login");
    pbn_login->setDefault(true);
    pbn_sign_up = new QPushButton("Sign up");
    gdl->setSizeConstraint(QLayout::SetFixedSize);//_____________________________________________
    lblUser->setText("Username");
    gdl->addWidget(lblUser,0,0);
    lblPass->setText("Password");
    gdl->addWidget(lblPass,1,0);
    gdl->addWidget(lblAnswer,5,0);
    gdl->addWidget(ledUser,0,1,1,2);
    gdl->addWidget(ledPass,1,1,1,2);
    ledPass->setEchoMode(QLineEdit::Password);
    gdl->addWidget(lbl_Answer,5,1,1,2);
    gdl->addWidget(pbn_login,3,1,1,2);
    gdl->addWidget(pbn_sign_up,4,1,1,2);

    setLayout(gdl);

    sign_up_window = new sign_up("ali");

    connect(pbn_sign_up,SIGNAL(clicked()),this,SLOT(openNewPage()));
    connect(pbn_login,SIGNAL(clicked()),this,SLOT(CHeck()));
}
void sign_in_up::openNewPage(){
    sign_up_window->show();
    lbl_Answer->setText("Indeterminate!");
}
void sign_in_up::CHeck(){
    if(ledUser->text().isEmpty() || ledPass->text().isEmpty())
        lbl_Answer->setText("Enter both!");
    else{
        QVector<QString> usernames=sign_up_window->get_usernames();
        QVector<QString> passwords=sign_up_window->get_passwords();
        bool userName=0,passWord=0;
        int i = 0;
        for(;i < usernames.size();i++){
            if(ledUser->text() == usernames[i] && ledPass->text() == passwords[i]){
                userName=true;
                passWord=true;
                break;
            }
        }
        if(userName && passWord){
            lbl_Answer->setText("Welcome " + usernames[i]);
        }else{
            lbl_Answer->setText("Not found");
        }
        ledUser->clear();
        ledPass->clear();
    }
}
sign_in_up::~sign_in_up()
{

}

