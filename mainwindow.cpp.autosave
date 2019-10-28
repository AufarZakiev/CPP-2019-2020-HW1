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
    
    void addStudent(QString name, int age){
        User::users_.push_back(*new User(name,age));
    }
    
    long itsAFinalCoundown(){
        return User::users_.size();
    }
    
    void delStudent(long index){
        for (long i = index; i < User::users_.size()-1;i++);
        User::users_.at(index) = User::users_.at(index+1);
        User::users_.erase(User::users_.begin()+ User::users_.size()-1);
    }
    
    void delStudent(QString name){
        long index = -1;
        for (long i = 0 ; i < User::users_.size();i++)
        {
            if (User::users_.at(i).getName() == name)
            index = i;
        }
        if (index != -1){
            for (long i = index; i < User::users_.size()-1;i++);
            User::users_.at(index) = User::users_.at(index+1);
            User::users_.erase(User::users_.begin()+ User::users_.size()-1);
            
        }
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

