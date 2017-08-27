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

private:
    Ui::MainWindow *ui;

    void LoadRooms();
    void RefreshRoomList();
    void LoadDataIntoUI(const MyTextAdventure::CRoom *room);
};

#endif // MAINWINDOW_H
