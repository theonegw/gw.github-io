#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // 初始化
    for(int i = 0;i < 4;i ++){
        for(int j = 0;j < 4;j++){
            s[i][j] = 0;
        }
    }
    button  = new QPushButton("开始游戏",this);

    button->setGeometry(60,400,200,50);
    show();

    // 随机种子
    qsrand(uint(QTime(0,0,0).secsTo(QTime::currentTime())));
    // 槽与信号，采用C++11特性匿名函数
    connect(button,&QPushButton::clicked,[=](){
        QMessageBox::about(this,"游戏规则","WASD控制方块上下左右移动");
        score = 0;
        for(int i = 0;i < 4;i++){
            for(int j = 0;j <4;j++){
                s[i][j] = 0;
            }
        }
        button->setText("重新游戏");
        int randi = qrand() % 4;
        int randj = qrand() % 4;
        s[randi][randj] = 2;
        state = true;
        update();
    });
     //update();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::paintEvent(QPaintEvent *)
{
    QPainter p(this);   // 绘图，构造一个QPainter对象
    p.setBrush(Qt::blue);   // 应用画刷
    p.setFont(QFont("微软雅黑",20,700,false));
    QString Score;
    p.drawText(QPoint(20,60),"分数：" + QString::number(score));   // 文本上数字的显示

    for(int i = 0;i < 4;i++){
        for(int j = 0;j < 4;j++){
            p.setPen(Qt::transparent);
            if(s[i][j] == 0){
                p.setBrush(Qt::gray);
                p.drawRect(i * 60 + 40,j * 60 + 120 ,60,60);
            }
            else if(s[i][j] == 2){
                p.setBrush(Qt::red);
                p.drawRect(i * 60 + 40,j * 60 + 120 ,60,60);
                p.setPen(Qt::black);    // 绘制图形没有描边
                p.setFont(QFont("微软雅黑",10,700,false));
                // 绘制
                p.drawText(QRectF(i * 60 + 40,j * 60 + 120 ,60,60),QString::number(2),QTextOption(Qt::AlignCenter));
            }
            else if(s[i][j] == 4){
                p.setBrush(Qt::darkRed);
                p.drawRect(i * 60 + 40,j * 60 + 120 ,60,60);
                p.setPen(Qt::black);
                p.setFont(QFont("微软雅黑",10,700,false));
                // 绘制
                p.drawText(QRectF(i * 60 + 40,j * 60 + 120 ,60,60),QString::number(4),QTextOption(Qt::AlignCenter));
            }
            else if(s[i][j] == 8){
                p.setBrush(Qt::green);
                p.drawRect(i * 60 + 40,j * 60 + 120 ,60,60);
                p.setPen(Qt::black);
                p.setFont(QFont("微软雅黑",10,700,false));
                // 绘制
                p.drawText(QRectF(i * 60 + 40,j * 60 + 120 ,60,60),QString::number(8),QTextOption(Qt::AlignCenter));
            }
            else if(s[i][j] == 16){
                p.setBrush(Qt::darkGreen);
                p.drawRect(i * 60 + 40,j * 60 + 120 ,60,60);
                p.setPen(Qt::black);
                p.setFont(QFont("微软雅黑",10,700,false));
                // 绘制
                p.drawText(QRectF(i * 60 + 40,j * 60 + 120 ,60,60),QString::number(16),QTextOption(Qt::AlignCenter));
            }
            else if(s[i][j] == 32){
                p.setBrush(Qt::yellow);
                p.drawRect(i * 60 + 40,j * 60 + 120 ,60,60);
                p.setPen(Qt::black);
                p.setFont(QFont("微软雅黑",10,700,false));
                // 绘制
                p.drawText(QRectF(i * 60 + 40,j * 60 + 120 ,60,60),QString::number(32),QTextOption(Qt::AlignCenter));
            }
            else if(s[i][j] == 64){
                p.setBrush(Qt::darkYellow);
                p.drawRect(i * 60 + 40,j * 60 + 120 ,60,60);
                p.setPen(Qt::black);
                p.setFont(QFont("微软雅黑",10,700,false));
                // 绘制
                p.drawText(QRectF(i * 60 + 40,j * 60 + 120 ,60,60),QString::number(64),QTextOption(Qt::AlignCenter));
            }
            else if(s[i][j] == 128){
                p.setBrush(Qt::cyan);
                p.drawRect(i * 60 + 40,j * 60 + 120 ,60,60);
                p.setPen(Qt::black);
                p.setFont(QFont("微软雅黑",10,700,false));
                // 绘制
                p.drawText(QRectF(i * 60 + 40,j * 60 + 120 ,60,60),QString::number(128),QTextOption(Qt::AlignCenter));
            }
            else if(s[i][j] == 256){
                p.setBrush(Qt::darkCyan);
                p.drawRect(i * 60 + 40,j * 60 + 120 ,60,60);
                p.setPen(Qt::black);
                p.setFont(QFont("微软雅黑",10,700,false));
                // 绘制
                p.drawText(QRectF(i * 60 + 40,j * 60 + 120 ,60,60),QString::number(256),QTextOption(Qt::AlignCenter));
            }
            else if(s[i][j] == 512){
                p.setBrush(Qt::magenta);
                p.drawRect(i * 60 + 40,j * 60 + 120 ,60,60);
                p.setPen(Qt::black);
                p.setFont(QFont("微软雅黑",10,700,false));
                // 绘制
                p.drawText(QRectF(i * 60 + 40,j * 60 + 120 ,60,60),QString::number(512),QTextOption(Qt::AlignCenter));
            }
            else if(s[i][j] == 1028){
                p.setBrush(Qt::darkMagenta);
                p.drawRect(i * 60 + 40,j * 60 + 120 ,60,60);
                p.setPen(Qt::black);
                p.setFont(QFont("微软雅黑",10,700,false));
                // 绘制
                p.drawText(QRectF(i * 60 + 40,j * 60 + 120 ,60,60),QString::number(1028),QTextOption(Qt::AlignCenter));
            }
            else if(s[i][j] == 2048){
                p.setBrush(Qt::darkBlue);
                p.drawRect(i * 60 + 40,j * 60 + 120 ,60,60);
                p.setPen(Qt::black);
                p.setFont(QFont("微软雅黑",10,700,false));
                // 绘制
                p.drawText(QRectF(i * 60 + 40,j * 60 + 120 ,60,60),QString::number(2048),QTextOption(Qt::AlignCenter));
            }
        }
    }
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if(!state){
        return ;
    }
    switch (event->key()){
    case Qt::Key_W:
        PressUp();
        break;
    case Qt::Key_S:
        PressDown();
        break;
    case Qt::Key_A:
        PressLeft();
        break;
    case Qt::Key_D:
        PressRight();
        break;
    default:
        return ;
    }

    // 实现随机函数
    myRand();
    update();// 刷新界面

}

void MainWindow::myRand()
{
        int i=0,j=0;
        struct Ns n[15];
        int ni=0;
        for (i=0;i<4;i++) {
            for (j=0;j<4;j++) {
                if(s[i][j]==0){
                    n[ni].i=i;
                    n[ni].j=j;
                    ni++;
                }
            }
        }

        if (ni==0) {
            for (i=0;i<4;i++) {
                for (j=0;j<3;j++) {
                    if(s[i][j]==s[i][j+1]){
                        return;
                    }
                }
            }
            for (j=0;j<4;j++) {
                for (i=0;i<3;i++) {
                    if(s[i][j]==s[i+1][j]){
                        return;
                    }
                }
            }
            // 没有空的方格，游戏结束
            QMessageBox::about(this,"游戏失败","分数为：" + QString::number(score)+"");
            return;
        }
        int rand=qrand()%ni;
        s[n[rand].i][n[rand].j]=2;
}

void MainWindow::PressLeft()
{

    for(int j = 0;j < 4;j++){
        for(int i = 1;i < 4;i++){
            if(s[i][j] == 0)continue;
            for(int k = i;k > 0;k--){
                if(s[k - 1][j] == 0)qSwap(s[k - 1][j],s[k][j]);
                else break;
            }
        }
    }

    for(int j = 0;j < 4;j++){
        for(int i = 1;i < 4;i++){
            if(s[i][j] == 0)continue;
            if(s[i - 1][j] == s[i][j]){
                s[i - 1][j] *= 2;
                s[i][j] = 0;
                score += s[i - 1][j];
            }
        }
    }

    for(int j = 0;j < 4;j++){
            for(int i = 1;i < 4;i++){
                if(s[i][j] == 0)continue;
                for(int k = i;k > 0;k--){
                    if(s[k - 1][j] == 0)qSwap(s[k - 1][j],s[k][j]);
                    else break;
                }
            }
        }
}

void MainWindow::PressRight()
{
    for(int j = 0;j < 4;j++){
        for(int i = 2;i >= 0;i--){
            if(s[i][j] == 0)continue;
            for(int k = i;k < 3;k++){
                if(s[k + 1][j] == 0)qSwap(s[k + 1][j],s[k][j]);
                else break;
            }
        }
    }

    for(int j = 0;j < 4;j++){
        for(int i = 2;i >= 0;i--){
            if(s[i][j] == 0)continue;
            if(s[i + 1][j] == s[i][j]){
                s[i + 1][j] *= 2;
                s[i][j] = 0;
                score += s[i + 1][j];
            }
        }
    }

    for(int j = 0;j < 4;j++){
        for(int i = 2;i >= 0;i--){
            if(s[i][j] == 0)continue;
            for(int k = i;k < 3;k++){
                if(s[k + 1][j] == 0)qSwap(s[k + 1][j],s[k][j]);
                else break;
            }
        }
    }
}

void MainWindow::PressUp()
{
       for(int i = 0;i < 4;i++){
           for(int j = 1;j < 4;j++){
               if(s[i][j] == 0)continue;
               for(int k = j;k > 0;k--){
                   if(s[i][k - 1] == 0)qSwap(s[i][k - 1],s[i][k]);
                   else break;
               }
           }
       }
       for(int i = 0;i < 4;i++){
           for(int j = 1;j < 4;j++){
               if(s[i][j] == 0)continue;
               if(s[i][j] == s[i][j - 1]){
                   s[i][j - 1] *= 2;
                   s[i][j] = 0;
                   score += s[i][j - 1];
               }

           }
       }
       for(int i = 0;i < 4;i++){
           for(int j = 1;j < 4;j++){
               if(s[i][j] == 0)continue;
               for(int k = j;k > 0;k--){
                   if(s[i][k - 1] == 0)qSwap(s[i][k - 1],s[i][k]);
                   else break;
               }
           }
       }

}

void MainWindow::PressDown()
{

    for(int i = 0;i < 4;i++){
        for(int j = 2;j >= 0;j--){
            if(s[i][j] == 0)continue;
            for(int k = j;k < 3;k++){
                if(s[i][k + 1] == 0)qSwap(s[i][k + 1],s[i][k]);
                else break;
            }
        }
    }
    for(int i = 0;i < 4;i++){
        for(int j = 2;j >= 0;j--){
            if(s[i][j] == 0)continue;
            if(s[i][j] == s[i][j + 1]){
                s[i][j + 1] *= 2;
                s[i][j] = 0;
                score += s[i][j + 1];
            }
        }
    }
    for(int i = 0;i < 4;i++){
        for(int j = 2;j >= 0;j--){
            if(s[i][j] == 0)continue;
            for(int k = j;k < 3;k++){
                if(s[i][k + 1] == 0)qSwap(s[i][k + 1],s[i][k]);
                else break;
            }
        }
    }

}
