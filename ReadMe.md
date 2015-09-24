# Liman Game Engine (EN)
* More information about [team](http://vk.com/justbear/);
* Engine [documentation](http://matthewpoletin.ru/projects/liman/documentation);
* Comprehensive [information about projects in development](http://matthewpoletin.ru/projects) ;
* List of current tasks on [trello](https://trello.com/b/g1HdHrUA).

# Игровой движок Liman (RU)
* Больше информации о команде на [сайте Just Bear](http://vk.com/justbear/);
* Страницв [документации по движку](http://matthewpoletin.ru/projects/liman/documentation);
* Полная информация [о проектах в разработке](http://matthewpoletin.ru/projects/);
* Список задач по проекту в [трелло](https://trello.com/b/g1HdHrUA).

## Достигнутые Особенности
* Базовая логика, физика, столкновения
* Прорисовка двумерных объектов
* Загрузка различных проектов
* Расширяемая система актеров

## Начало работы
* Создайте пустую папку
* Склонируйте туда решение
* Перейдите к ```Liman/BuildScript```
* Запустите build-vs2015 или build-vs2013
* Вернитесь к ```Liman``` и откройте Liman.sln
* Если возникнут проблемы, [обращайтесь](http://matthewpoletin.ru)

## Структура проекта
* ``Core`` Ядро движка
  * ``Actors`` Актеры (игровые объекты), основанные на расширямых компонентах;
    * ``Actor`` Игровой объект мира
    * ``ActorComponent`` Интерфейс компонента актера
    * ``TransformComponent`` Компонент трансформации
    * ``ActorFactory`` Фабрика для создания актёров
  * ``Subsystems`` Осонвные подсистемы для обеспечения работоспособности
  * ``Ipnut`` Подсистема ввода
  * ``Graphics`` Графика
* ``Game`` Библиотека для создания двумерных игр на движке
  * ``Physics`` Подсистема физики
  * ``Collisions`` Подсистема столкновений 
* ``LimanEditorDLL`` Библиотека для обеспечения работоспособности редкатора
* ``LimanEditor`` Редактор игрового мира (в разработке)

## Список основных задач
* Поддержка позиции мыши
* Добавить поддержку контроллеров (включая настройки)
* Компонент анимации
* Система событий

###Пример проекта на движке
```C++
#include "Game.h"

using namespace liman;

int main(int argc, char** argv)
{
  liman::Game* pGame = new Game();

  pGame->VInit();

  while(pGame->VGetState() == Application::State::S_Running)
  {
    pGame->VDoLoop();
  }

  pGame->VDeInit();

  return 0;
}
````

## Используемые библиотеки
| Название                                           | Назначение                            | Применяемые Модули       | Версия
|----------------------------------------------------|---------------------------------------|--------------------------|-------------
| [stb](https://github.com/nothings/stb)             | Загрузка изображений (png, jpg, etc.) | stb image                | v2.02
| [glfw](http://www.glfw.org/)                       | Работа с OpenGL, вводом               |                          | v3.1.1
| [glew](http://glew.sourceforge.net/)               | Расширения для OpenGL                 |                          |
| [glm](http://glm.g-truc.net/0.9.7/)                | Математика для OpenGL                 |                          |
| [tinyxml2](https://github.com/leethomason/tinyxml2)| Работа с форматом xml                 |                          |
