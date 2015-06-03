#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QHBoxLayout>
#include <QPushButton>
#include <QImage>
#include <QtGlobal>
#include <QTime>
#include <QLabel>

#include <stdlib.h>

#include "imageviewer.hpp"

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void inc1Button_Clicked(bool checked);
    void inc10Button_Clicked(bool checked);
    void inc100Button_Clicked(bool checked);
    void inc1000Button_Clicked(bool checked);
    void inc10000Button_Clicked(bool checked);
    void inc100000Button_Clicked(bool checked);
    void inc1000000Button_Clicked(bool checked);
    void resetButton_Clicked(bool checked);

private:
    const int diameter;
    const double half_diameter;

    QWidget *cw;
    QVBoxLayout *layout;
    QHBoxLayout *graphicLayout;
    QVBoxLayout *labelLayout;
    QHBoxLayout *buttonLayout;

    ImageViewer *view;
    QImage img;

    QLabel *piLabel;

    QPushButton *inc1Button;
    QPushButton *inc10Button;
    QPushButton *inc100Button;
    QPushButton *inc1000Button;
    QPushButton *inc10000Button;
    QPushButton *inc100000Button;
    QPushButton *inc1000000Button;
    QPushButton *inc10000000Button;
    QPushButton *resetButton;

    int inCircle;
    int outCircle;

    void resetImage();
    void hitDots(int n);
    int boundRand(int l, int u) const;
    bool isInCircle(int x, int y) const;
};

#endif // MAINWINDOW_H
