#include "mainwindow.h"
#include <QtGui>
#include <QtDeclarative>
#include <KApplication>
#include <KLocale>
#include <KCmdLineArgs>
#include <KAboutData>
#include <QLayout>

void MainWindow::photoTaken(){
    videoViewer->ui = ui;
    videoViewer->thread.storeImage=true;
}

void MainWindow::timerCounter(int count) {
    //qDebug(QString::number(count).toStdString().c_str());
    if (count>0) {
      system("beep -l 250 &");
    }
    else if (count==0) {
      system("beep -l 1000 -f 1000 &");
    }
}

void MainWindow::showDirectory() {
    system("kde-open ~/kamerka &");
    exit(0);
}

void MainWindow::resizeEvent(QResizeEvent *e) {
    videoViewer->resize(this->size());
    QMainWindow::resizeEvent(e);
}

MainWindow::~MainWindow()
{
    exit(0);
}

MainWindow::MainWindow() {
{
    qmlRegisterType<QGraphicsBlurEffect>("Effects",1,0,"Blur");
    qmlRegisterType<QGraphicsDropShadowEffect>("Effects",1,0,"DropShadow");

    ui = new QDeclarativeView;
    videoViewer = new videowidget(this);
    QIcon icon(":/kamerka.png");

    videoViewer->show();
    this->setCentralWidget(ui);
    this->setWindowIcon(icon);
    ui->setSource(QUrl("qrc:/kamerka.qml"));
    ui->rootContext()->setContextProperty("fileName", "");
    ui->setStyleSheet("background:transparent");
    videoViewer->setStyleSheet("background:transparent");

    ui->setResizeMode(QDeclarativeView::SizeRootObjectToView);
    this->setWindowTitle(QString("Kamerka"));


    if (videoViewer->thread.startUlan()) {
      QMessageBox msgbox( QMessageBox::Critical, "Error", "Could not... blablabla, nie dziaua :(");
      msgbox.exec();
      exit(0);
    }

    connect(ui->rootObject(), SIGNAL(photoTaken()), this, SLOT(photoTaken()));
    connect(ui->rootObject(), SIGNAL(timerCounter(int)), this, SLOT(timerCounter(int)));
    connect(ui->rootObject(), SIGNAL(showDirectory()), this, SLOT(showDirectory()));

  }

}