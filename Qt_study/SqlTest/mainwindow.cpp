#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButtonCreate_clicked()
{
    QSqlDatabase d = QSqlDatabase::addDatabase("QSQLITE");
    d.setDatabaseName("dbtest");
    if (!d.open()) {
        qDebug("got problems with database");
    }

    {
        QSqlQuery query;
        query.exec("create table person (id int primary key, "
                   "firstname varchar(20), lastname varchar(20))");
        query.exec("insert into person values(101, 'Danny', 'Young')");
        query.exec("insert into person values(102, 'Christine', 'Holand')");
        query.exec("insert into person values(103, 'Lars', 'Gordon')");
        query.exec("insert into person values(104, 'Roberto', 'Robitaille')");
        query.exec("insert into person values(105, 'Maria', 'Papadopoulos')");

    }
}
