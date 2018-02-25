#include "pathwindow.h"
#include "ui_pathwindow.h"

PathWindow::PathWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PathWindow)
{
    ui->setupUi(this);
}

PathWindow::~PathWindow()
{
    delete ui;
}

void PathWindow::LoadPath(const MyTextAdventure::path_t p)
{
    ui->edtPathRoomID->setValue(p.Room);
    ui->edtPathCaption->setText(p.Title.c_str());
}

void PathWindow::SavePath(MyTextAdventure::path_t *p)
{
    p->Room = ui->edtPathRoomID->value();
    p->Title = ui->edtPathCaption->text().toStdString();
}
