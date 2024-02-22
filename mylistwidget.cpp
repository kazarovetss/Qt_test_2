#include "mylistwidget.h"


MyListWidget::MyListWidget(QWidget *parent) : QListWidget(parent) { // Конструктор класса MyListWidget

        setDragEnabled(true);// Включение возможности перетаскивания элементов внутри виджета
        setAcceptDrops(true); // Разрешение на прием перетаскиваемых элементов
        setDropIndicatorShown(true);// Отображение индикатора места, куда будет перемещен перетаскиваемый элемент
        addIconsWithLabels();// Добавление иконок с подписями в виджет
}

void MyListWidget::addIconsWithLabels()// Функция для добавления элементов в QListWidget
{
    QListWidgetItem *item1 = new QListWidgetItem(QIcon(":/img/img/green.jpg"), "Зеленый");
    this->addItem(item1);

    QListWidgetItem *item2 = new QListWidgetItem(QIcon(":/img/img/red.jpg"), "Красный");
    this->addItem(item2);

    QListWidgetItem *item3 = new QListWidgetItem(QIcon(":/img/img/orange.jpg"), "Оранжевый");
    this->addItem(item3);

    QListWidgetItem *item4 = new QListWidgetItem(QIcon(":/img/img/blue.png"), "Синий");
    this->addItem(item4);

    QListWidgetItem *item5 = new QListWidgetItem(QIcon(":/img/img/yellow.png"), "Желтый");
    this->addItem(item5);
}


void MyListWidget::mousePressEvent(QMouseEvent *event) { // Переопределение события нажатия мыши для реализации перетаскивания элементов
    QListWidget::mousePressEvent(event);

    if (event->button() != Qt::LeftButton) return;  // Если нажата не левая кнопка мыши, обработка прекращается

    QListWidgetItem *item = itemAt(event->pos());  // Получение элемента под курсором мыши
    if (!item) return;

    QByteArray itemData;  // Подготовка данных элемента для перетаскивания
    QDataStream dataStream(&itemData, QIODevice::WriteOnly);
    QPixmap pixmap = item->icon().pixmap(32, 32);
    QString text = item->text();
    dataStream << pixmap << text; // Запись данных в поток

    QMimeData *mimeData = new QMimeData; // Создание объекта QMimeData и установка данных элемента
    mimeData->setData("application/vnd.text.listwidgetitem", itemData);

    QDrag *drag = new QDrag(this); // Создание объекта QDrag для реализации операции перетаскивания
    drag->setMimeData(mimeData); // Установка данных для перетаскивания
    drag->setPixmap(pixmap);
    drag->setHotSpot(QPoint(0, 0));
    drag->exec(Qt::CopyAction | Qt::MoveAction); // Начало операции перетаскивания с возможностью копирования или перемещения
}


