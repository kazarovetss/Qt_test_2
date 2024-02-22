# Qt_test_2
Добрый день! Высылая первую часть тестового задания, реализовала drag and drop и создала базовую структура, также перегрузила класс QListWidget в контейнере QGroupBox. Также возможность выделения добавленный иконок в QGraphicsView. Пока возникла проблема со связыванием всех виджетов для быстрого доступа между собой. Также при добавлении иконки в координаты (0,0) добавляется слайдер, пока не могу разобраться почему.

Выполнено:

Перетаскивание мышью иконки из поля (1) в поле (2), т.н. drag-n-drop.

После перетаскивания в поле (2) создается новый объект размером 64x64 пикселя, как на рисунке.

Поля имеют следующие типы:

(1) - перегруженный класс QListWidget в контейнере QGroupBox

(2) - QGraphicsView

(3) - QListView

(4) - QTableView**

При масштабировании окна поле 1 должно иметь постоянную ширину, размер остальных полей должен изменяться пропорционально размеру окна.
-------------------------------------------------------------------------
Добрый день, высылаю вторую часть тестового задания, создала таблицу с координатами и при добавлении иконки в QGraphicsView ее наименование автоматически добавляется в QListView. Сейчас рабтаю со связью QListView и QTableView. Думаю к четвергу реализую отображение координат и перемещение иконок на заданные.

Выполненно:

Перетаскивание мышью иконки из поля (1) в поле (2), т.н. drag-n-drop. Перетаскивание можно производить сколь угодно раз.

После перетаскивания в поле (2) создается новый объект в координатах (0, 0) размером 64x64 пикселя, как на рисунке.

Одновременно в поле (3) создается новая строка с содержимым "[icon]", как на рисунке

Появляется таблица с двумя настройками x и y, как на рисунке. Значение по умолчанию 0, 0.

Поля имеют следующие типы:

(1) - перегруженный класс QListWidget в контейнере QGroupBox

(2) - QGraphicsView

(3) - QListView

(4) - QTableView

При масштабировании окна поле 1 должно иметь постоянную ширину, размер остальных полей должен изменяться пропорционально размеру окна.
-------------------------------------------------------
Добрый день, поработала со сборкой и добавила комментарии к коду, начала реализовывать связь с QTableView, но пока не получается отображать координаты выделенного элемента, до следующего вторника еще сама повожусь, если не получиться буду просить помощи
