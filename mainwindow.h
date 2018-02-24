#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "mytextadventure.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_lstRoomTitles_currentRowChanged(int currentRow);

    void on_actionAdd_room_triggered();

    void on_actionSave_triggered();

    void on_edtRoomDescription_textChanged();

    void on_edtRoomTitle_textChanged(const QString &arg1);

private:
    Ui::MainWindow *ui;
    MyTextAdventure::CRoom *selectedRoom;

    void LoadRooms();
    void SaveRooms();
    void RefreshRoomList();
    void LoadDataIntoUI(MyTextAdventure::CRoom *room);
};

#endif // MAINWINDOW_H
