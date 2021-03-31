#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QMessageBox>

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
  ui->setupUi(this);
}

MainWindow::~MainWindow()
{
  delete ui;
}

class User
{
  int age;
  QString name;

public:
  explicit User(QString name, int age = 18)
  {
    if (age >= 18)
    {
      this->age = age;
    }
    else
    {
      this->age = 18;
    }
    this->name = name;
  }
  QString getName()
  {
    return name;
  }
  int getAge()
  {
    return age;
  }

  static size_t getTotalCount()
  {
    return users_.size();
  }

  static void addStudent(QString name, int age)
  {
    User student(name, age);
    users_.push_back(student);
  }

  static bool deleteStudentByIndex(size_t index)
  {
    if ((index < 0) || (index >= getTotalCount()))
    {
      return false;
    }
    else
    {
      users_.erase(users_.begin() + index);
      return true;
    }
  }

  static void deleteStudentByName(QString name)
  {
    for (size_t i = 0; i < users_.size(); i++)
    {
      if (name == users_[i].name)
        users_.erase(users_.begin() + i);
    }
  }
  static std::vector<User> users_;
};
std::vector<User> User::users_;

void MainWindow::on_submitPushButton_clicked()
{
  qDebug() << "User clicked on submit button";
  // ui->nameLineEdit->setText("Aufar");
  User student(ui->nameLineEdit->text(), ui->ageLineEdit->text().toInt());

  QMessageBox msg(QMessageBox::Information, "New student arrived!", "Hello " + student.getName() + "!");
  // qDebug() << "Name:" << student.getName();
  // qDebug() << "Age:" << student.getAge();
  qDebug() << msg.exec();
  qDebug() << User::getTotalCount();
  User::users_.push_back(student);
  // qDebug() << "Last student age:" << User::users_.end()->getAge();
  // qDebug() << "Last student name:" << User::users_.end()->getName();
  qDebug() << "Total count:" << User::users_.size();
  qDebug() << "First student name ([0]):" << User::users_[0].getName();
  qDebug() << "First student name (at):" << User::users_.at(0).getName();
  qDebug() << "------------------------";
}
