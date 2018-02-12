#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
#include <QFile>
#include <QTimer>
#include <QtGamepad/QGamepad>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->setFixedSize(this->width(), this->height() );             // disable windows size change

    doConnect();
    ui->statusBar->addPermanentWidget( ui->tcp_status_label, 1 );   // add tcp_status_label on statusBar

    timer = new QTimer(this);                                       // create timer
    connect(timer, SIGNAL(timeout()), this, SLOT(update()));        // connect update() to timer slot

    load_css_style();
}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_clear_button_clicked()
{
    ui->console_text->clear();
    tcrt_5000_left = 0;
    tcrt_5000_right = 0;
}

void MainWindow::on_start_button_clicked(bool checked)
{
    if( checked ){
        timer->start(200);
    } else {
        timer->stop();
    }
}

void MainWindow::load_css_style()
{
    QFile styleSheet("style.qss");                                  // load CSS style
    if (!styleSheet.open(QIODevice::ReadOnly)) {
        qWarning("Unable to open style.qss");
        return;
    }
    qApp->setStyleSheet(styleSheet.readAll());
}






