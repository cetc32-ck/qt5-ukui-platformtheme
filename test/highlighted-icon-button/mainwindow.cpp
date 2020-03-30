/*
 * Qt5-UKUI
 *
 * Copyright (C) 2020, Tianjin KYLIN Information Technology Co., Ltd.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 *
 * Authors: Yue Lan <lanyue@kylinos.cn>
 *
 */

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_checkBox_toggled(bool checked)
{
    ui->pushButton->setProperty("useIconHighlightEffect", checked);
    ui->pushButton->update();
    ui->toolButton->setProperty("useIconHighlightEffect", checked);
    ui->toolButton->update();
    ui->comboBox->setEnabled(checked);
}

void MainWindow::on_comboBox_currentIndexChanged(int index)
{
    int mode = index;
    ui->pushButton->setProperty("iconHighlightEffectMode", mode);
    ui->pushButton->update();
    ui->toolButton->setProperty("iconHighlightEffectMode", mode);
    ui->toolButton->update();
}
