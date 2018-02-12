#ifndef MAINWINDOW_H
#include "ui_mainwindow.h"
#include "mainwindow.h"
#endif

void MainWindow::on_reset_uc_button_clicked()
{
    if(socket->isWritable()){
       socket->write("AT+RST?");
       ui->pwm_dc_slider->setValue(101);
       ui->s1_slider->setValue(60);
       ui->s2_slider->setValue(85);
       ui->speed_gripper_slider->setValue(5);
    }
}

void MainWindow::on_stop_button_pressed()
{
    bufor_tx[0] = 0x5;  // stop
}

void MainWindow::on_forward_button_pressed()
{
    bufor_tx[0] = 0x1;  // forward
}

void MainWindow::on_forward_button_released()
{
    bufor_tx[0] = 0x5;  // stop
}

void MainWindow::on_left_button_pressed()
{
    bufor_tx[0] = 0x2;  // left
}

void MainWindow::on_left_button_released()
{
    bufor_tx[0] = 0x5;  // stop
}

void MainWindow::on_right_button_pressed()
{
    bufor_tx[0] = 0x3;  // right
}

void MainWindow::on_right_button_released()
{
    bufor_tx[0] = 0x5;  // stop
}

void MainWindow::on_backward_button_pressed()
{
    bufor_tx[0] = 0x4;  // backward
}

void MainWindow::on_backward_button_released()
{
    bufor_tx[0] = 0x5;  // stop
}

void MainWindow::on_speed_gripper_slider_valueChanged(int value)
{
    bufor_tx[1] = (uint8_t)value;           // speed gripper
    ui->speed_gripper_label->setNum( (int)(-2.02*value+102.02) );
    ui->speed_gripper_label->setText( ui->speed_gripper_label->text() + "%" );
}

void MainWindow::on_adc_button_clicked()    // show in labels ADC value
{
    bufor_tx[0] = 0x6;                      // current ADC value
}

void MainWindow::on_s1_slider_valueChanged(int value)
{
    bufor_tx[3] = (uint8_t)value;                           // jaw position
    ui->s1_label->setNum( (int)(1.5*value-45)  );
    ui->s1_label->setText( ui->s1_label->text() + "°" );
}

void MainWindow::on_s2_slider_valueChanged(int value)
{
    bufor_tx[2] = (uint8_t)value;                           // gripper position
    ui->s2_label->setNum( (int)(1.5*value-45)  );
    ui->s2_label->setText( ui->s2_label->text() + "°" );
}

void MainWindow::on_pwm_dc_slider_valueChanged(int value)
{
    bufor_tx[4] = (uint8_t)value;                           // platform speed
    ui->pwm_dc_label->setNum( (int)(0.999*value) );
    ui->pwm_dc_label->setText( ui->pwm_dc_label->text() + "%" );

    switch (value){
        case 101:
        ui->pwm_dc_label->setText( "full speed" );
        break;

        case 96:
        ui->pwm_dc_label->setText( "medium speed" );
        break;

        case 71:
        ui->pwm_dc_label->setText( "slow speed" );
        break;

        case 51:
        ui->pwm_dc_label->setText( "very slow speed" );
        break;

    }
}
