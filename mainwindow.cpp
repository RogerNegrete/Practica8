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



void MainWindow::on_pushButton_clicked()
{
    QString directory = QFileDialog::getExistingDirectory(this, tr("Open Directory"), "/home/alumno", QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
    if (!directory.isEmpty()) {
        ui->label->setText(directory); // Establecer la ruta de la carpeta en el QLabel

        QDir dir(directory);
        QStringList entries = dir.entryList(QDir::Dirs | QDir::Files | QDir::NoDotAndDotDot); // Obtener carpetas y archivos dentro del directorio

        ui->listWidget->clear(); // Limpiar la lista antes de agregar nuevos elementos

        for (const QString& entry : entries) {
            ui->listWidget->addItem(entry); // Agregar cada carpeta o archivo a la lista
        }
    }
}
