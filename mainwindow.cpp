#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "mytextadventure.h"
#include "stdafx.h"

using namespace MyTextAdventure;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    LoadRooms();
}

void MainWindow::RefreshRoomList()
{
    ui->lstRoomTitles->clear();
    ui->lstRoomTitles->addItems(CGame::Instance()->Rooms->GetRoomTitles());
}

void MainWindow::LoadRooms()
{
    try
    {
        std::unique_ptr<CRoomsFromJson> rooms = std::make_unique<CRoomsFromJson>();
        rooms->Load("/Users/Patrick/Projects/Partouf/mytextadventure");

        CGame::Instance()->Rooms = std::move(rooms);
    }
    catch(const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    RefreshRoomList();
}

MainWindow::~MainWindow()
{
    delete ui;
}
