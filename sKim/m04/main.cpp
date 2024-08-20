#include <QApplication>
#include "RacingGame.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    RacingGame game;
    game.show();

    return app.exec();
}
