#include <QGraphicsPixmapItem>
#include <QMimeData>
#include <QDragEnterEvent>
#include <QDragMoveEvent>
#include <QDropEvent>
#include <QStringListModel>
#include <QDataStream>
#include <QTableView>
#include <QHeaderView>
#include <QGraphicsView>
#include <QItemSelectionModel>
#include "mygraphicsview.h"

QListView *globalListView; // Объявление глобальных переменных для QListView и QTableView
QTableView *tableView;

MyGraphicsView::MyGraphicsView(QListView *listView, QWidget *parent)// Конструктор класса MyGraphicsView
    : QGraphicsView(parent), globalListView(listView) {
    connect(globalListView->selectionModel(), &QItemSelectionModel::currentChanged, // Подключение сигнала изменения выбора в QListView к слоту onListViewItemSelected
            this, &MyGraphicsView::onListViewItemSelected);
}

void MyGraphicsView::dragEnterEvent(QDragEnterEvent *event) // Обработчик события ввода drag n drop
{
    if (event->mimeData()->hasFormat("application/vnd.text.listwidgetitem")) {
        event->acceptProposedAction(); // Принятие действия
    }
}

void MyGraphicsView::dragMoveEvent(QDragMoveEvent *event) // Обработчик перемещения в процессе drag n drop
{
    if (event->mimeData()->hasFormat("application/vnd.text.listwidgetitem")) { // Проверка формата и принятие действия
        event->acceptProposedAction();
    }
}

void MyGraphicsView::dropEvent(QDropEvent *event) { // Обработчик события drop
    if (event->mimeData()->hasFormat("application/vnd.text.listwidgetitem")) {
        QByteArray itemData = event->mimeData()->data("application/vnd.text.listwidgetitem"); // Извлечение данных из события
        QDataStream dataStream(&itemData, QIODevice::ReadOnly);

        QPixmap pixmap; // Чтение pixmap и текста из потока данных
        QString text;
        dataStream >> pixmap >> text;

        //const int itemWidth = 64;
        //const int itemHeight = 64;
        //const int itemsPerRow = this->width() / itemWidth;

        QGraphicsPixmapItem *item = new QGraphicsPixmapItem(pixmap); // Создание и добавление нового элемента сцены
        item->setFlag(QGraphicsItem::ItemIsSelectable, true);
        item->setData(0, text);
        item->setPos(0,0);
        scene()->addItem(item);

        event->acceptProposedAction(); // Принятие события drop
        QStringListModel* model = qobject_cast<QStringListModel*>(globalListView->model()); // Обновление модели списка QListView новым элементом
            if (!model) {
                model = new QStringListModel(this);
                globalListView->setModel(model);
            }
            QStringList list = model->stringList();
            list << text;
            model->setStringList(list); // Обновление модели списка
}
}



//void MyGraphicsView::mousePressEvent(QMouseEvent *event) {}

void MyGraphicsView::onListViewItemSelected(const QModelIndex &current, const QModelIndex &previous) // Слот, вызываемый при изменении выбранного элемента в QListView
{
    QString itemText = current.data().toString(); // Получение идентификатора иконки
    QPointF itemCoords = findIconCoordinates(itemText); // Функция поиска координат иконки

    QStandardItemModel *model = qobject_cast<QStandardItemModel*>(tableView->model()); // Обновление модели QTableView новыми координатами
    model->setItem(0, 1, new QStandardItem(QString::number(itemCoords.x())));
    model->setItem(1, 1, new QStandardItem(QString::number(itemCoords.y())));
}

QPointF MyGraphicsView::findIconCoordinates(const QString &itemText) { // Функция поиска координат иконки в QGraphicsView по наименованию
    foreach (QGraphicsItem *item, this->scene()->items()) {

        if (item->data(0).toString() == itemText) { // Проверка на совпадение текста
            return item->pos(); // Возвращаются координаты иконки
        }
    }
    return QPointF(); // Возвращается пустой объект, если иконка не найдена
}


void MyGraphicsView::getResize() { // Слот для обновления размера сцены

    scene()->setSceneRect(0, 0, width()-2, height()-2);// Установка размера сцены равным размеру виджета минус 2 пикселя с каждой стороны
}

void MyGraphicsView::MyGraphicsView::resizeEvent(QResizeEvent *event) { //Обработчик события изменения размера виджета
    QGraphicsView::resizeEvent(event);
    getResize(); // Обновление размера сцены
}
