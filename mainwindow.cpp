#include "mainwindow.hpp"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , diameter(501)
    , half_diameter(diameter/2.0)
    , cw(new QWidget())
    , layout(new QVBoxLayout())
    , graphicLayout(new QHBoxLayout())
    , labelLayout(new QVBoxLayout())
    , buttonLayout(new QHBoxLayout())
    , view(new ImageViewer())
    , img(QImage(diameter, diameter, QImage::Format_RGB32))
    , piLabel(new QLabel())
    , inc1Button(new QPushButton("1点打つ"))
    , inc10Button(new QPushButton("10点打つ"))
    , inc100Button(new QPushButton("100点打つ"))
    , inc1000Button(new QPushButton("1000点打つ"))
    , inc10000Button(new QPushButton("1万点打つ"))
    , inc100000Button(new QPushButton("10万点打つ"))
    , inc1000000Button(new QPushButton("100万点打つ"))
    , resetButton(new QPushButton("リセット"))
{
    setCentralWidget(cw);
    cw->setLayout(layout);
    layout->addLayout(graphicLayout);
    layout->addLayout(labelLayout);
    layout->addLayout(buttonLayout);

    connect(inc1Button, SIGNAL(clicked(bool)), this, SLOT(inc1Button_Clicked(bool)));
    connect(inc10Button, SIGNAL(clicked(bool)), this, SLOT(inc10Button_Clicked(bool)));
    connect(inc100Button, SIGNAL(clicked(bool)), this, SLOT(inc100Button_Clicked(bool)));
    connect(inc1000Button, SIGNAL(clicked(bool)), this, SLOT(inc1000Button_Clicked(bool)));
    connect(inc10000Button, SIGNAL(clicked(bool)), this, SLOT(inc10000Button_Clicked(bool)));
    connect(inc100000Button, SIGNAL(clicked(bool)), this, SLOT(inc100000Button_Clicked(bool)));
    connect(inc1000000Button, SIGNAL(clicked(bool)), this, SLOT(inc1000000Button_Clicked(bool)));
    connect(resetButton, SIGNAL(clicked(bool)), this, SLOT(resetButton_Clicked(bool)));

    graphicLayout->addWidget(view);
    labelLayout->addWidget(piLabel);
    buttonLayout->addWidget(inc1Button);
    buttonLayout->addWidget(inc10Button);
    buttonLayout->addWidget(inc100Button);
    buttonLayout->addWidget(inc1000Button);
    buttonLayout->addWidget(inc10000Button);
    buttonLayout->addWidget(inc100000Button);
    buttonLayout->addWidget(inc1000000Button);
    buttonLayout->addWidget(resetButton);

    piLabel->setAlignment(Qt::AlignCenter);

    resetImage();
    qsrand(QTime::currentTime().msec());
}

MainWindow::~MainWindow() { }

void
MainWindow::inc1Button_Clicked(bool checked)
{
    Q_UNUSED(checked);
    hitDots(1);
}

void
MainWindow::inc10Button_Clicked(bool checked)
{
    Q_UNUSED(checked);
    hitDots(10);
}

void
MainWindow::inc100Button_Clicked(bool checked)
{
    Q_UNUSED(checked);
    hitDots(100);
}

void
MainWindow::inc1000Button_Clicked(bool checked)
{
    Q_UNUSED(checked);
    hitDots(1000);
}

void
MainWindow::inc10000Button_Clicked(bool checked)
{
    Q_UNUSED(checked);
    hitDots(10000);
}

void
MainWindow::inc100000Button_Clicked(bool checked)
{
    Q_UNUSED(checked);
    hitDots(100000);
}

void
MainWindow::inc1000000Button_Clicked(bool checked)
{
    Q_UNUSED(checked);
    hitDots(1000000);
}

void
MainWindow::resetButton_Clicked(bool checked)
{
    Q_UNUSED(checked);
    resetImage();
}

void
MainWindow::resetImage()
{
    int i, j;

    for (i = 0; i < diameter; i++)
        for (j = 0; j < diameter; j++)
            img.setPixel(i, j, qRgb(255, 255, 255));
    inCircle = outCircle = 0;

    view->showImage(img);
    piLabel->setText("0.0");
    setWindowTitle("0");
}

void
MainWindow::hitDots(int n)
{
    int i;
    int x, y;
    for (i = 0; i < n; i++)
    {
        x = boundRand(0, diameter-1);
        y = boundRand(0, diameter-1);

        if (isInCircle(x, y))
        {
            inCircle++;
            img.setPixel(x, y, qRgb(255, 0, 0));
        }
        else
        {
            outCircle++;
            img.setPixel(x, y, qRgb(0, 0, 255));
        }
    }
    view->showImage(img);
    piLabel->setText(QString::number(4*(double)inCircle/(double)(inCircle+outCircle)));
    this->setWindowTitle(QString::number(inCircle+outCircle));
}

int
MainWindow::boundRand(int l, int u) const { return (int)(qrand()*(u-l+1.0)/(1.0+RAND_MAX)); }

bool
MainWindow::isInCircle(int x, int y) const
{
    double xx = x-half_diameter, yy = y-half_diameter;
    return half_diameter*half_diameter >= (xx*xx + yy*yy);
}
