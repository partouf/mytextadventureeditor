#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "stdafx.h"
#include "pathwindow.h"
#include "itemwindow.h"

using namespace MyTextAdventure;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    LoadRooms();
    LoadItems();
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

void MainWindow::LoadItems()
{
    try
    {
        std::unique_ptr<CItemsFromJson> items = std::make_unique<CItemsFromJson>();
        items->Load("../mytextadventure");

        CGame::Instance()->Items = std::move(items);
    }
    catch(const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
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

    auto rooms = CGame::Instance()->Rooms.get();

    ui->lstPaths->clear();
    for (auto path : selectedRoom->Paths)
    {
        ui->lstPaths->addItem(rooms->FormatPathTitle(path));
    }

    auto items = CGame::Instance()->Items.get();

    ui->lstItems->clear();
    for (auto item : selectedRoom->Items)
    {
        auto itemdata = items->GetByItemId(item);
        ui->lstItems->addItem(itemdata->Title.c_str());
    }
}

void MainWindow::ReloadRoom()
{
    LoadDataIntoUI(selectedRoom);
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
    auto rooms = CGame::Instance()->Rooms.get();

    double nextRoomID = floor(rooms->GetMaxRoomId()) + 1.0;
    auto newRoom = rooms->AddRoom(nextRoomID);

    RefreshRoomList();

    int rowCount = (int)rooms->Count();
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

void MainWindow::on_btnAddPath_clicked()
{
    path_t p;

    PathWindow dlg(this);
    dlg.LoadPath(p);
    if (dlg.exec() != 0)
    {
        dlg.SavePath(&p);

        selectedRoom->Paths.emplace_back(p);

        ReloadRoom();
    }
}

void MainWindow::on_btnAddItem_clicked()
{
    ItemWindow dlg(this);
    if (dlg.exec() != 0)
    {
        auto item = dlg.SelectedItem();
        if (item != nullptr)
        {
            selectedRoom->Items.emplace_back(item->Id);

            ReloadRoom();
        }
    }
}

void MainWindow::on_btnDelItem_clicked()
{
    auto idx = ui->lstItems->currentRow();
    auto id = selectedRoom->Items.at(idx);
    selectedRoom->RemoveItem(id);

    ReloadRoom();
}
