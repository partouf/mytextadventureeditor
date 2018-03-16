#ifndef PATHWINDOW_H
#define PATHWINDOW_H

#include <QDialog>
#include "mytextadventure.h"

namespace Ui {
class PathWindow;
}

class PathWindow : public QDialog
{
    Q_OBJECT

public:
    explicit PathWindow(QWidget *parent = 0);
    ~PathWindow();

    void LoadPath(const MyTextAdventure::path_t p);
    void SavePath(MyTextAdventure::path_t *p);

private:
    Ui::PathWindow *ui;
};

#endif // PATHWINDOW_H
