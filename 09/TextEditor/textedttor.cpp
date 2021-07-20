#include "textedttor.h"
#include "./ui_textedttor.h"

TextEdttor::TextEdttor(QWidget *parent)
    : QWidget(parent)
{
    setWindowTitle("Text Editor");
    main_layout = new QVBoxLayout();
    text_edit_plain = new QTextEdit();
    menu_bar = new QMenuBar();
    main_layout->setMenuBar(menu_bar);
    file_menu = new QMenu(tr("&File"));
    menu_bar->addMenu(file_menu);
    open_action = new QAction(tr("&Open"));
    open_action->setShortcut(tr("Ctrl+O"));
    save_action = new QAction(tr("&Save"));
    save_action->setShortcut(tr("Ctrl+S"));
    file_menu->addAction(open_action);
    file_menu->addAction(save_action);
    main_layout->addWidget(text_edit_plain);
    setLayout(main_layout);


    connect(save_action,SIGNAL(triggered()),this,SLOT(save_file()));
    connect(open_action,SIGNAL(triggered()),this,SLOT(open_file()));
}

TextEdttor::~TextEdttor()
{

}
void TextEdttor::open_file(){
    QString Filter = "All File(*.*);; Text File(*.txt)";
    file_name = QFileDialog::getOpenFileName(this, "Open a file", "E://", Filter);
    QFile my_file(file_name);
    if(!my_file.open(QFile::ReadOnly | QFile::Text)){
        QMessageBox::warning(this, "title", "The open operation failed");
    }
    QTextStream in(&my_file);
    QString plain_text = in.readAll();
    text_edit_plain->setPlainText(plain_text);
}
void TextEdttor::save_file(){
    QString Filter = "All File(*.*);; Text File(*.txt)";
    if(file_name.isEmpty()){
        file_name = QFileDialog::getSaveFileName(this, "Save a file", "E://", Filter);
    }
    QFile my_file2(file_name);
    if(!my_file2.open(QFile::WriteOnly | QFile::Text)){
        QMessageBox::warning(this, "title", "The save operation failed");
    }
    QTextStream out(&my_file2);
    out << text_edit_plain->toPlainText();
    text_edit_plain->clear();
}

