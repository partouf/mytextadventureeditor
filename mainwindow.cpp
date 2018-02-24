#include "mainwindow.h"
#include "ui_mainwindow.h"

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
        rooms->Load("../mytextadventure");

        CGame::Instance()->Rooms = std::move(rooms);
    }
    catch(const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    RefreshRoomList();
}

void MainWindow::SaveRooms()
{
    CRoomsFromJson *rooms = reinterpret_cast<CRoomsFromJson *>(CGame::Instance()->Rooms.get());
    rooms->Save("../mytextadventure");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::LoadDataIntoUI(MyTextAdventure::CRoom *room)
{
    selectedRoom = room;

    ui->edtRoomId->setValue(room->Id);
    ui->edtRoomTitle->setText(room->Title.c_str());
    ui->edtRoomDescription->setText(room->Description.c_str());
}

void MainWindow::on_lstRoomTitles_currentRowChanged(int currentRow)
{
    if (currentRow >= 0)
    {
        LoadDataIntoUI(CGame::Instance()->Rooms->GetByIndex(currentRow));
    }
}

void MainWindow::on_actionAdd_room_triggered()
{
    double nextRoomID = floor(CGame::Instance()->Rooms->GetMaxRoomId()) + 1.0;

    auto newRoom = CGame::Instance()->Rooms->AddRoom(nextRoomID);

    RefreshRoomList();

    int rowCount = (int)CGame::Instance()->Rooms->Count();
    ui->lstRoomTitles->setCurrentRow(rowCount - 1);
    LoadDataIntoUI(newRoom);

    ui->edtRoomTitle->setFocus();
}

void MainWindow::on_actionSave_triggered()
{
    SaveRooms();
}

void MainWindow::on_edtRoomDescription_textChanged()
{
    if (selectedRoom != nullptr)
    {
        auto text = ui->edtRoomDescription->toPlainText();
        selectedRoom->Description = text.toStdString();
    }
}

void MainWindow::on_edtRoomTitle_textChanged(const QString &arg1)
{
    if (selectedRoom != nullptr)
    {
        selectedRoom->Title = arg1.toStdString();

        auto rowText = CGame::Instance()->Rooms->FormatRoomTitle(selectedRoom);
        ui->lstRoomTitles->currentItem()->setText(rowText);
    }
}
