#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    dbpath = "technologybasic.db";
    ui->setupUi(this);
    ui->textBrowser->setFont(QFont("SolaimanLipi",12,300,false));
    if(!QFile(dbpath).exists())
    {
        QMessageBox::warning(this, "Error", "Database not found","Select file");
        dbpath = QFileDialog::getOpenFileName(this, "Select Data Base File", QDir::homePath(), "SQLite Database (*.db)");
    }
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(dbpath);
    db.open();
    QSqlQuery query("SELECT `name`, `details` from `terms`");
    QSqlRecord record = query.record();
    while (query.next())
    {
        Title << query.value(record.indexOf("name")).toString();
        Text << query.value(record.indexOf("details")).toString();
    }

    QButtonGroup *buttons = new QButtonGroup;

    for(int i=0;i<Title.size();i++)
    {
        ui->listWidget->addItem(Title.at(i));
        QPushButton *button = new QPushButton(Title.at(i));
        button->setStyleSheet("QPushButton { background-color: green; border-style: inset; border-width: 1px; border-radius: 10px; border-color: white; font: bold 14px; color: white; }");
        ui->gridScrollArea->addWidget(button);
        buttons->addButton(button);
    }

    QObject::connect(buttons, SIGNAL(buttonClicked(int)), this, SLOT(buttonClick(int)));
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_listWidget_itemClicked(QListWidgetItem *item)
{
    QString text = Text.at(Title.indexOf(item->text()));
    ui->textBrowser->setText(text);
}

void MainWindow::buttonClick(int index)
{
    QString text = Text.at(abs(index) - 2);
    ui->textBrowser->setText(text);
}

void MainWindow::on_lineEdit_textChanged(const QString &arg1)
{
    QRegExp regExp(arg1,Qt::CaseInsensitive,QRegExp::Wildcard);
    ui->listWidget->clear();
    ui->listWidget->addItems(Title.filter(regExp));
}

void MainWindow::on_pushButton_clicked()
{
    QDesktopServices::openUrl(QUrl("http://technologybasic.com/"));
}
