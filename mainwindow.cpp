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
private:
  int age_;
  QString name_;
  static int total_count_;

public:
  explicit User(QString name, int age = 18)
  {
    if (age >= 18)
    {
      this->age_ = age;
    }
    else
    {
      this->age_ = 18;
    }
    this->name_ = name;
    total_count_++;
  }

  QString getName()
  {
    return name_;
  }

  int getAge()
  {
    return age_;
  }

  static int getTotalCount()
  {
    return total_count_;
  }

  static size_t getCount()
  {
    return users_.size();
  }

  static void addUser(User user)
  {
    users_.push_back(user);
  }

  static void removeUserAt(int index)
  {
    users_.erase(users_.begin() + index);
  }

  static void removeUserByName(QString name)
  {
    for (std::vector<User>::iterator it = users_.begin(); it < users_.end(); it++)
    {
      if (it->name_ == name)
      {
        users_.erase(it);
        break;
      }
    }
  }

  static std::vector<QString> getAllNames()
  {
    std::vector<QString> list;
    for (std::vector<User>::iterator it = users_.begin(); it < users_.end(); it++)
    {
      list.push_back(it->name_);
    }
    return list;
  }

  static std::vector<User> users_;
};

int User::total_count_ = 0;
std::vector<User> User::users_;

void MainWindow::on_submitPushButton_clicked()
{
  /*
  qDebug() << "User clicked on submit button";
  // ui->nameLineEdit->setText("Aufar");
  User student(ui->nameLineEdit->text(), ui->ageLineEdit->text().toInt());

  QMessageBox msg(QMessageBox::Information,"New student arrived!", "Hello "+
  student.getName() + "!");
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
  */

  // Добавление студентов
  User::addUser(User("Timofey", 22));
  User::addUser(User("Aufar", 33));
  User::addUser(User("Valery", 44));
  User::addUser(User("Kirill", 55));
  User::addUser(User("Artem", 66));
  User::addUser(User("Camila", 77));

  // Текущий число и список студентов
  qDebug() << "Current students' count: " << User::getCount();
  qDebug() << "All students: ";
  qDebug() << User::getAllNames();

  // Удаление студента номер 4
  qDebug() << "Removing user at 4 index";
  User::removeUserAt(4);

  // Текущее число и список студентов
  qDebug() << "Current Students' Count: " << User::getCount();
  qDebug() << "All students: ";
  qDebug() << User::getAllNames();

  // Удаление студента по имени
  qDebug() << "Removing user named Aufar ";
  User::removeUserByName("Aufar");

  // Текущее число и список студентов
  qDebug() << "Current Students' Count: " << User::getCount();
  qDebug() << "All students: ";
  qDebug() << User::getAllNames();
}
