#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QStyleFactory>
#include <QDir>
#include <QStringListModel>
#include <QGSettings>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QGSettings settings("org.ukui.style", "/org/ukui/style/");
    auto currentStyle = settings.get("styleName").toString();
    auto currentIconTheme = settings.get("iconThemeName").toString();

    auto styles = QStyleFactory::keys();
    styles.removeOne("ukui");
    QStringListModel *style_model = new QStringListModel(styles, this);
    ui->comboBox->setModel(style_model);
    ui->comboBox->setCurrentText(currentStyle);

    QDir iconThemePaths = QDir("/usr/share/icons");
    auto iconThemes = iconThemePaths.entryList(QDir::Dirs);
    QStringListModel *icon_theme_model = new QStringListModel(iconThemes, this);
    ui->comboBox_2->setModel(icon_theme_model);
    ui->comboBox_2->setCurrentText(currentIconTheme);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_comboBox_currentIndexChanged(const QString &arg1)
{
    //change style
    QGSettings settings("org.ukui.style", "/org/ukui/style/");
    settings.set("styleName", arg1);
}

void MainWindow::on_comboBox_2_currentIndexChanged(const QString &arg1)
{
    //change icon theme
    QGSettings settings("org.ukui.style", "/org/ukui/style/");
    settings.set("iconThemeName", arg1);
}
