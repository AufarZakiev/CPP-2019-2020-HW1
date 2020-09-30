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
     int index;
    QString name;
    static int total_count;
    static std::vector<User> users_;
public:
    explicit User(QString name, int index){
        this->name=name;
        this->index=index;
        total_count++;
    }
    QString getName(){
        return name;
    }
    int getIndex(){
        return index;
    }

    void add_student(User user){
        users_.push_back(user);
    }
    void delete_student_index(int index){
        users_.erase(std::remove(users_.begin(), users_.end(), index), users_.end());
    }
    void delete_student_name(QString name){
        users_.erase(std::remove(users_.begin(), users_.end(), name), users_.end());
    }
    static int getTotalCount(){
        return total_count;
    }

};

int User::total_count = 0;
std::vector<User> User::users_;

void MainWindow::on_submitPushButton_clicked()
{
    qDebug() << "User clicked on submit button";
    // ui->nameLineEdit->setText("Aufar");
    User student(ui->nameLineEdit->text(), ui->ageLineEdit->text().toInt());

    QMessageBox msg(QMessageBox::Information,"New student arrived!",
                    "Hello "+ student.getName() + "!");
    // qDebug() << "Name:" << student.getName();
    // qDebug() << "Age:" << student.getAge();
    qDebug() << msg.exec();
    qDebug() << User::getTotalCount();
    User::users_.push_back(student);
    //qDebug() << "Last student age:" << User::users_.end()->getAge();
    //qDebug() << "Last student name:" << User::users_.end()->getName();
    qDebug() << "Total count:" << User::users_.size();
    qDebug() << "First student name ([0]):" << User::users_[0].getName();
    qDebug() << "First student name (at):" << User::users_.at(0).getName();
    qDebug() << "------------------------";
}
