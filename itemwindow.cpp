#include "itemwindow.h"
#include "ui_itemwindow.h"

ItemWindow::ItemWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ItemWindow)
{
    ui->setupUi(this);
}

ItemWindow::~ItemWindow()
{
    delete ui;
}

void ItemWindow::LoadItems()
{
    ui->comboBox->clear();

}
