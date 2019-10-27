#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QMessageBox>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


class User{
    int age; // private
    QString name; //private
    static int total_count;
public:
    explicit User(QString name, int age=18){
        if(age>=18){
            this->age=age;
        }else{
            this->age=18;
        }
        this->name=name;
        total_count++;
    }
    QString getName(){
        return name;
    }
    int getAge(){
        return age;
    }
    static int getTotalCount(){
        return total_count;
    }
    static std::vector<User> users_;
};

int User::total_count = 0;
std::vector<User> User::users_;

void MainWindow::on_submitPushButton_clicked()
{
    qDebug() << "User added the student";

    User student(ui->nameLineEdit->text(), ui->ageLineEdit->text().toInt());
    QMessageBox msg(QMessageBox::Information,"New student arrived!",
                    "Hello, "+ student.getName() + "!");
    qDebug() << msg.exec();
    User::users_.push_back(student);

    qDebug() << "------------------------";
}

void MainWindow::on_deleteByIndex_clicked()
{
    qDebug() << "User deleted the student by index";

    int index(ui->indexEditLine->text().toInt());
    User::users_.erase(User::users_.begin()+index);

    qDebug() << "------------------------";
}

void MainWindow::on_deleteByName_clicked()
{
    qDebug() << "User deleted student by name";

    QString nameDel(ui->nameEditLineDel->text());
    for (int i=0; i < User::users_.size(); i++) {
        if (User::users_[i].getName()==nameDel)
        {
            User::users_.erase(User::users_.begin()+i);
            break;
        }
    }

    qDebug() << "------------------------";
}

void MainWindow::on_totalCount_clicked()
{
    qDebug() << "User got the total count";

    qDebug() << User::users_.size();

    qDebug() << "------------------------";
}
