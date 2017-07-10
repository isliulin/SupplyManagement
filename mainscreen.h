#ifndef MAINSCREEN_H
#define MAINSCREEN_H

#include <QFile>
#include <QMainWindow>
#include <QApplication>
#include <QStackedWidget>
#include <QSystemTrayIcon>
#include <QPropertyAnimation>

#include "udpsocket.h"
#include "loginscreen.h"
#include "aboutusscreen.h"
#include "usermanagerment.h"
#include "rolemanagerment.h"

class MainScreen : public QMainWindow
{
    Q_OBJECT

public:
    MainScreen(QWidget *parent = 0);
    ~MainScreen();
signals:
    void sendSocket(QUrl url);
    void sendMsg(QUrl url);
public:
    int login();
private slots:
    void initUI();
    void initUdp();
    void swithMaxNormal();
    void initToolButton(QToolButton *btn);
    void readToolButton();
    void stackChange(QByteArray win);
    void animationHide();
    void animationClose();
    void recvSocket(QUrl url);
private:
    QStackedWidget *stack;
    UdpSocket udp;
    UserManagerment *user;
    RoleManagerment *role;
};

#endif // MAINSCREEN_H
