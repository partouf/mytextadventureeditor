#include "itemwindow.h"
#include "ui_itemwindow.h"
#include "mytextadventure.h"

ItemWindow::ItemWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ItemWindow)
{
    ui->setupUi(this);

    LoadItems();
}

ItemWindow::~ItemWindow()
{
    delete ui;
}

void ItemWindow::LoadItems()
{
    ui->comboBox->clear();

    auto items = CGame::Instance()->Items.get();
    for (int idx = 0; idx < items->Count(); idx++)
    {
        auto item = items->GetByIndex(idx);
        ui->comboBox->addItem(item->Title.c_str(), idx);
    }
}

MyTextAdventure::CItem* ItemWindow::SelectedItem() {
    if (ui->comboBox->currentIndex() >= 0)
    {
        int selectedItemIndex = ui->comboBox->currentData().toInt();

        return CGame::Instance()->Items.get()->GetByIndex(selectedItemIndex);
    }

    return nullptr;
}

