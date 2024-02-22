#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QGroupBox>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QListView>
#include <QTableView>
#include <QStandardItemModel>
#include <QHeaderView>
#include "MyListWidget.h"
#include "mygraphicsview.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);  // Создание экземпляра QApplication

    QWidget window;
    window.setWindowTitle("Комплексное расположение виджетов");

    QHBoxLayout *mainLayout = new QHBoxLayout;  // Создание главной горизонтальной компоновки

    QListView *listView = new QListView;

    QListWidget *listWidget = new QListWidget();
    QVBoxLayout *leftLayout = new QVBoxLayout; // Создание вертикальной компоновки для левой части интерфейса
    QGraphicsScene *graphicsScene = new QGraphicsScene();
    MyGraphicsView *graphicsView = new MyGraphicsView(listView); // Создание наследованного от QGraphicsView виджета для отображения графической сцены
    graphicsView->setScene(graphicsScene);
    graphicsView->setAcceptDrops(true);
    leftLayout->addWidget(graphicsView, 1);

    QHBoxLayout *bottomLayout = new QHBoxLayout; // Создание горизонтальной компоновки для нижней части интерфейса
    QTableView *tableView = new QTableView;
    bottomLayout->addWidget(listView);
    bottomLayout->addWidget(tableView);
    QStandardItemModel *model = new QStandardItemModel(2, 2); // 2 строки и 2 столбца

    tableView->horizontalHeader()->setVisible(false);
    tableView->verticalHeader()->setVisible(false);
    model->setItem(0, 0, new QStandardItem("x"));
    model->setItem(1, 0, new QStandardItem("y"));
    model->setItem(0, 1, new QStandardItem(QString::number(0)));
    model->setItem(1, 1, new QStandardItem(QString::number(0)));

    tableView->setModel(model);

    leftLayout->addLayout(bottomLayout);

    QGroupBox *groupBox = new QGroupBox("Элементы управления"); // Создание группового контейнера для элементов управления
    groupBox->setFixedWidth(200);
    QVBoxLayout *groupBoxLayout = new QVBoxLayout(groupBox); // Создание вертикальной компоновки внутри группового контейнера
    MyListWidget *myListWidget = new MyListWidget;
    groupBoxLayout->addWidget(myListWidget, 0);


    mainLayout->addLayout(leftLayout, 2);
    mainLayout->addWidget(groupBox, 1);

    window.setLayout(mainLayout);
    window.resize(800, 600); // Установка начального размера главного окна
    window.show();

    return app.exec();
}
