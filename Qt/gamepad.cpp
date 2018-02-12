#ifndef MAINWINDOW_H
#include "ui_mainwindow.h"
#include "mainwindow.h"
#include <QString>
#include <QTimer>
#endif


void MainWindow::on_gamepad_button_clicked(bool checked)
{
    auto gamepads = QGamepadManager::instance()->connectedGamepads();
    if (gamepads.isEmpty()) { return; }

    if ( checked ){
        m_gamepad = new QGamepad(*gamepads.begin(), this);
    }else{
        delete m_gamepad;
        lock_gamepad_gripper = true;
    }
}

void MainWindow::GamePad()
{
        switch ( (int)m_gamepad->axisLeftY() )
        {
        case -1:
                on_forward_button_pressed();
        break;

        case 1:
                on_backward_button_pressed();
        break;
        }

        switch ( (int)m_gamepad->axisLeftX() )
        {
        case -1:
                on_left_button_pressed();
        break;

        case 1:
                on_right_button_pressed();
        break;
        }

        if ( m_gamepad->axisLeftX() == 0 and m_gamepad->axisLeftY()== 0 ) bufor_tx[0] = 0x5;

        if ( lock_gamepad_gripper == false)
        {
            switch ( (int)(2.5 * m_gamepad->buttonL2()) )   // gripper up/down
            {
            case 0:
                    ui->s1_slider->setValue( ui->s1_slider->value() - 5 );
            break;

            case 2:
                    ui->s1_slider->setValue( ui->s1_slider->value() + 5 );
            break;
            }

            switch ( (int)(2 * m_gamepad->buttonR2()) )     // gripper jaw
            {
            case 0:
                    ui->s2_slider->setValue( ui->s2_slider->value() - 1 );
            break;

            case 2:
                    ui->s2_slider->setValue( ui->s2_slider->value() + 1 );
            break;
            }
        }else{
            lock_gamepad_gripper = !( (bool)m_gamepad->buttonR2() and (bool)m_gamepad->buttonL2() ) ;
        }
}
