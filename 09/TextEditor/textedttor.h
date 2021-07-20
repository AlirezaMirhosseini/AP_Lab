#ifndef TEXTEDTTOR_H
#define TEXTEDTTOR_H

#include <QWidget>
#include <QTextEdit>
#include <QFileDialog>
#include <QMenu>
#include <QMenuBar>
#include <QAction>
#include <QVBoxLayout>
#include <QMessageBox>
#include <QDir>
#include <QFile>
#include <QTextStream>

QT_BEGIN_NAMESPACE
namespace Ui { class TextEdttor; }
QT_END_NAMESPACE

class TextEdttor : public QWidget
{
    Q_OBJECT

public:
    TextEdttor(QWidget *parent = nullptr);
    ~TextEdttor();
public slots:
    void open_file();
    void save_file();
private:
    QVBoxLayout * main_layout;
    QTextEdit * text_edit_plain;
    QMenuBar * menu_bar;
    QMenu * file_menu;
    QAction * open_action;
    QAction * save_action;
    QString file_name;
};
#endif // TEXTEDTTOR_H
