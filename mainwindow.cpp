#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QWidget>
#include <QList>
#include <QListIterator>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , vKeyboard(NULL)
{
    ui->setupUi(this);

    /* TODO make translator */
    this->vKeyboard = new VirtualKeyboard(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_lineEdit_selectionChanged()
{
    QList<QWidget*> lole = this->findChildren<QWidget*>();
    QListIterator<QWidget*> it(lole);
    QWidget *leField;
    while(it.hasNext())
    {
        leField = it.next();
        if(QLineEdit *le = qobject_cast<QLineEdit*>(leField))
        {
            if(le->hasFocus())
            {
                vKeyboard->show(le);
            }
        }
    }
    //vKeyboard->show(this->selectedWidget...);
//    vKeyboard->show(this);
}
