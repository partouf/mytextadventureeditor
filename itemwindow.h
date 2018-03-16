#ifndef ITEMWINDOW_H
#define ITEMWINDOW_H

#include <QDialog>
#include "mytextadventure.h"

using namespace MyTextAdventure;

namespace Ui {
class ItemWindow;
}

class ItemWindow : public QDialog
{
    Q_OBJECT

public:
    explicit ItemWindow(QWidget *parent = 0);
    ~ItemWindow();

    CItem* SelectedItem();

private:
    Ui::ItemWindow *ui;
    void LoadItems();
};

#endif // ITEMWINDOW_H
