#ifndef MYGRAPHICSVIEW_H
#define MYGRAPHICSVIEW_H

#include <QListWidget>
#include <QMimeData>
#include <QDrag>
#include <QMouseEvent>
#include <QDragEnterEvent>
#include <QDragMoveEvent>
#include <QDropEvent>
#include <QGraphicsView>
#include <QTableView>
#include <QStandardItemModel>
#include <QItemSelectionModel>
#include "mylistwidget.h"
class MyGraphicsView : public QGraphicsView {
 Q_OBJECT
public:
explicit MyGraphicsView(QListView *listView, QWidget *parent = nullptr); // Конструктор класса MyGraphicsView
public slots:
    void getResize(); // Слот для обновления размера сцены
    void onListViewItemSelected(const QModelIndex &current, const QModelIndex &previous); // Слот, вызываемый при изменении выбранного элемента в QListView
protected:
    void dragEnterEvent(QDragEnterEvent *event) override; // Обработчик события ввода drag n drop
    void dragMoveEvent(QDragMoveEvent *event) override; // Обработчик перемещения в процессе drag n drop
    void dropEvent(QDropEvent *event) override; // Обработчик события drop
//  void mousePressEvent(QMouseEvent *event) override;

    QPointF findIconCoordinates(const QString &itemText); // Функция поиска координат иконки в QGraphicsView по наименованию
    void resizeEvent(QResizeEvent *event) override; //Обработчик события изменения размера виджета
private:
    QListView *globalListView;
    QTableView *tableView;
    QStandardItemModel *tableModel;
};

#endif
