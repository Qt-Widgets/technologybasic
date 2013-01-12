#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSql>
#include <QListWidget>
#include <QButtonGroup>
#include <QRegExp>
#include <QListWidget>
#include <QDesktopServices>
#include <QMessageBox>
#include <QFileDialog>

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
    void on_listWidget_itemClicked(QListWidgetItem *item);
    void buttonClick(int index);
    void on_lineEdit_textChanged(const QString &arg1);
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    QStringList Title, Text;
    QString dbpath;
};

#endif // MAINWINDOW_H
