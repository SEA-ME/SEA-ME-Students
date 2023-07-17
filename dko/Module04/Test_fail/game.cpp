#include "game.h"

#include <QKeyEvent>
#include <QDebug>

game::game() : m_timer(new QTimer(this))
{
    m_timer->start(1000.0f/60.0f);
}
