#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMainWindow>
#include <QPushButton>
#include <QTime>
#include <QPainter>
#include <QKeyEvent>
#include <QMessageBox>

struct Ns
{
    int i,j;
};
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void paintEvent(QPaintEvent *);
    void keyPressEvent(QKeyEvent *event);
    QPushButton *button;
    void myRand();
    void PressUp();
    void PressDown();
    void PressLeft();
    void PressRight();
    int s[4][4];
    int score = 0;
    bool state;
    QPainter ss;
private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
