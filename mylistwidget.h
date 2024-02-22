#ifndef MYLISTWIDGET_H
#define MYLISTWIDGET_H

#include <QListWidget>
#include <QMimeData>
#include <QDrag>
#include <QMouseEvent>

class MyListWidget : public QListWidget {
    Q_OBJECT
public:
    explicit MyListWidget(QWidget *parent = nullptr); // Конструктор класса MyListWidget

protected:
    void addIconsWithLabels(); // Функция для добавления элементов в QListWidget
    void mousePressEvent(QMouseEvent *event) override; // Переопределение события нажатия мыши для реализации перетаскивания элементов
};

#endif
