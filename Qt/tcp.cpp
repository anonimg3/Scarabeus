#ifndef MAINWINDOW_H
#include "ui_mainwindow.h"
#include "mainwindow.h"
#include <QString>
#include <QTimer>
#endif

void MainWindow::doConnect()
{
    socket = new QTcpSocket(this);

    connect(socket, SIGNAL(connected()),this, SLOT(connected()));
    connect(socket, SIGNAL(disconnected()),this, SLOT(disconnected()));
    connect(socket, SIGNAL(bytesWritten(qint64)),this, SLOT(bytesWritten(qint64)));
    connect(socket, SIGNAL(readyRead()),this, SLOT(readyRead()));

    ui->tcp_status_label->setText ("<font color='green'>connecting...</font>");

    // this is not blocking call
    socket->connectToHost( ui->ip_address->text() , ui->port_address->text().toShort() );
    //socket->connectToHost( "192.168.1.23",8899 );
    // we need to wait...
    if(!socket->waitForConnected(1000))
    {
        ui->tcp_status_label->setText("<font color='red'>"+socket->errorString()+"</font>");
        ui->start_button->setEnabled( false );
        ui->start_button->setChecked( false );
    }


}

void MainWindow::on_connect_button_clicked(bool checked)
{
    checked ? doConnect() : socket->close();
}


void MainWindow::connected()
{
   ui->tcp_status_label->setText ("<font color='green'>connected...</font>");
   ui->start_button->setEnabled( true );
}

void MainWindow::disconnected()
{
    ui->tcp_status_label->setText ("<font color='red'>disconnected...</font>");
    ui->start_button->setEnabled( false );
    ui->start_button->setChecked( false );
    timer->stop();

}


void MainWindow::bytesWritten(qint64 bytes)
{
    ui->tcp_status_label->setText ("<font color='green'>");
    ui->tcp_status_label->setText(ui->tcp_status_label->text() + QString::number(bytes,10) + " bytes written...</font>");
}

void MainWindow::readyRead()
{
    uint8_t temp_u8 = 0;
    uint16_t temp_u16=0;
    QString text;

    ui->tcp_status_label->setText ("<font color='green'>reading...</font>");

    bufor_rx[0] = socket->read(1);
    bufor_rx[1] = socket->read(1);
    bufor_rx[2] = socket->read(1);
    bufor_rx[3] = socket->read(1);

    text.append("<font size=\"2\" color=\"green\">");
    text.append("<table width=\"100%\">");
    text.append("<tr>");
    text.append("<th>"+ bufor_rx[0].toHex() + "</th>");
    text.append("<th>"+ bufor_rx[1].toHex() + "</th>");
    text.append("<th>"+ bufor_rx[2].toHex() + "</th>");
    text.append("<th>"+ bufor_rx[3].toHex() + "</th>");
    text.append("</tr>");
    text.append("</table>");
    ui->console_text->append(text);
    text.clear();

    // US-015
    memcpy(&temp_u16, (bufor_rx[2] + bufor_rx[3]), sizeof(uint16_t));
//    ui->us_015_label->setText( "US-015: " + QString::number(temp_u16) + " impulsów" );
    ui->us_015_label->setText( "US-015: " + QString::number( (uint16_t)(0.16738*temp_u16-1) ) + " cm" );

    // TCRT-5000 right
    memcpy(&temp_u8, bufor_rx[1], sizeof(uint8_t));
    if ( bufor_tx[0] == 6 ) {
        ui->tcrt_5000_right_label->setText( "Right: " + QString::number(temp_u8) + " ADC" );
    }else{
        tcrt_5000_right = tcrt_5000_right + (temp_u8-100);
        ui->tcrt_5000_right_label->setText( "Right: " + QString::number( (uint16_t)(tcrt_5000_right) ) + " imp" );
//        ui->tcrt_5000_right_label->setText( "Right: " + QString::number( (uint16_t)(tcrt_5000_right*0.61261) ) + " cm" );
    }

    // TCRT-5000 left
    memcpy(&temp_u8, bufor_rx[0], sizeof(uint8_t));
    if ( bufor_tx[0] == 6 ) {
        ui->tcrt_5000_left_label->setText( "Left: " + QString::number(temp_u8) + " ADC" );
    }else{
        tcrt_5000_left = tcrt_5000_left + (temp_u8-100);
        ui->tcrt_5000_left_label->setText( "Left: " + QString::number( (uint16_t)(tcrt_5000_left) ) + " imp" );
//        ui->tcrt_5000_left_label->setText( "Left: " + QString::number( (uint16_t)(tcrt_5000_left*0.61261) ) + " cm" );
    }
}

void MainWindow::update()
{
    QString temp_text;
    if ( socket->isWritable() and ( memcmp( bufor_tx, bufor_tx_temp, sizeof(bufor_tx)) or ui->stop_button->isDown()  ) ){    // compare bufor_tx with bufor_tx_temp[]
        for(uint8_t i=0; i<sizeof(bufor_tx); i++){
            bufor_tx_temp[i] = bufor_tx[i];                                                 // copy array from bufor_tx[] to bufor_tx_temp[]
        }
        socket->write((const char*) &bufor_tx_temp, sizeof(bufor_tx_temp));                 // send bufor_tx[]

        temp_text.append("<font size=\"2\" color=\"red\">");
        temp_text.append("<table width=\"100%\">");
        temp_text.append("<tr>");
        temp_text.append("<th>"+ QString::number(bufor_tx_temp[0]) + "</th>");
        temp_text.append("<th>"+ QString::number(bufor_tx_temp[1]) + "</th>");
        temp_text.append("<th>"+ QString::number(bufor_tx_temp[2]) + "</th>");
        temp_text.append("<th>"+ QString::number(bufor_tx_temp[3]) + "</th>");
        temp_text.append("<th>"+ QString::number(bufor_tx_temp[4]) + "</th>");
        temp_text.append("</tr>");
        temp_text.append("</table>");
        ui->console_text->append(temp_text);                                                // add bufor_tx[] to console_text
        temp_text.clear();
    }
    if( ui->gamepad_button->isChecked() ) GamePad();
}



