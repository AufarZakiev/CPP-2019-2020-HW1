#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QMessageBox>
#include <cstdlib>
#include <ctime>

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
  ui->setupUi(this);
}

MainWindow::~MainWindow()
{
  delete ui;
}
//отдельный класс UserRecord с генератором ID
class UserRecord
{
public:
  int getID()
  {
    return ID;
  }

private:
  //функция генерирует ID для пользователя
  static int ID_generation()
  {
    srand(time(NULL));
    int ID_return;
    ID_return = rand() % 1000;  //пусть будет ID[0;999]
    return ID_return;
  }
  int ID = ID_generation();
  //список всех ID, понадобится для проверки дубликатов ID
  static std::vector<int> users_records_id;
  //функция проверяет на дубликаты ID
  static bool isContains(int user_id)
  {
    bool is = false;
    for (unsigned int i = 0; i < users_records_id.size(); i++)
    {
      if (users_records_id[i] == user_id)
      {
        is = true;
        break;
      }
    }
    return is;
  }
};
class User
{
  int age;       // private
  QString name;  // private
  UserRecord record;

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
  int getID()
  {
    return record.getID();
  }

  static std::vector<User> users_;
  // 1)метод добавления студентов
  static void addUser(User student)
  {
    //поставлю ограничение в 1000 студентов
    if (users_.size() < 1000)
    {
      User::users_.push_back(student);
    }
    else
    {
      qDebug() << "Full list of students";
    }
  }
  // 2)метод удаления студентов по ID
  static void deleteUserByIndex(int remove_ID)
  {
    for (unsigned int i = 0; i < User::users_.size(); i++)
    {
      if (User::users_[i].getID() == remove_ID)
      {
        User::User::users_.erase(User::users_.begin() + i);
        qDebug() << "Student with index " << remove_ID << " was succesfully deleted!";
        break;
      }
    }
  }
  // 3)метод удаления студентов по имени, студент есть в списке
  static void deleteUserByName(QString name)
  {
    for (unsigned int i = 0; i < User::users_.size(); i++)
    {
      if (User::users_[i].getName() == name)
      {
        User::users_.erase(User::users_.begin() + i);
        qDebug() << "Student " << name << " was succesfully deleted!";
        break;
      }
    }
  }
  // 4)метод получения количества студентов
  static int totalCount()
  {
    return users_.size();
  }
};
std::vector<User> User::users_;
// std::vector<int> UserRecord::users_records_;
void MainWindow::on_submitPushButton_clicked()
{
  qDebug() << "User clicked on submit button";
  User student(ui->nameLineEdit->text(), ui->ageLineEdit->text().toInt());
  QMessageBox msg(QMessageBox::Information, "New student arrived!", "Hello " + student.getName() + "!");
  qDebug() << msg.exec();
  // 1)работа метода добавления студентов
  User::addUser(student);
  // 4)работа метода получения количества студентов
  qDebug() << "Total count:" << User::totalCount();
  qDebug() << "ID: " << User::users_[User::totalCount() - 1].getID();
  qDebug() << "Student name:" << User::users_[User::totalCount() - 1].getName();
  qDebug() << "Student age:" << User::users_[User::totalCount() - 1].getAge();
  qDebug() << "------------------------";
  // 2)Пусть для примера программа будет удалять студента с именем Alex
  User::deleteUserByName("Alex");
  // 3)Пусть для примера программа будет удалять студента с индексом 9
  User::deleteUserByIndex(9);
}
