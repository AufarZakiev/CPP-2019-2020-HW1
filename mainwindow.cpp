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
    static int index;
public:
    explicit User(QString name, int age=18){
        if(age>=18){
            this->age=age;
        }else{
            this->age=18;
        }
        this->name=name;
        index++;
    }
    QString getName(){
        return name;
    }
    int getAge(){
        return age;
    }
    static int getIndex(){
        return index;
    }
    static std::vector<User> users_;
    //1)метод добавления студентов
     static void addUser(User student){
       User::users_.push_back(student);
    }
    //2)метод удаления студентов по индексу
      static void deleteUserByIndex(int index){
        for(unsigned int i = 0;i<User::users_.size();i++){
            if(User::users_[i].getIndex()==index){
                User::User::users_.erase(User::users_.begin()+i);
                qDebug()<<"Student with index "<<index<<" was succesfully deleted!";
                break;
            }
        }
    }
    //3)метод удаления студентов по имени, студент есть в списке
     static void deleteUserByName(QString name){
        for(unsigned int i = 0;i<User::users_.size();i++){
            if(User::users_[i].getName()==name){
                User::users_.erase(User::users_.begin()+i);
                qDebug()<<"Student "<<name<<" was succesfully deleted!";
                break;
            }
        }
    }
    //4)метод получения количества студентов
     static int totalCount(){
         return users_.size();
     }
};

int User:: index= 0;
std::vector<User> User::users_;

    void MainWindow::on_submitPushButton_clicked()
{
    qDebug() << "User clicked on submit button";
    User student(ui->nameLineEdit->text(), ui->ageLineEdit->text().toInt());
    QMessageBox msg(QMessageBox::Information,"New student arrived!",
                    "Hello "+ student.getName() + "!");
    qDebug() << msg.exec();
    //1)работа метода добавления студентов
    User::addUser(student);
    //4)работа метода получения количества студентов
    qDebug() << "Total count:" << User::totalCount();
    qDebug() <<"Index: "<<User::getIndex();
    qDebug()<<"Student name:"<< User::users_[User::totalCount()-1].getName();
    qDebug()<<"Student age:"<<User::users_[User::totalCount()-1].getAge();
    qDebug() << "------------------------";
    //2)Пусть для примера программа будет удалять студента с именем Alex
    User::deleteUserByName("Alex");
    //3)Пусть для примера программа будет удалять студента с индексом 9
    User::deleteUserByIndex(9);
}
