#ifndef RACETRACK_H
#define RACETRACK_H

class RaceTrack {
public:
    RaceTrack(int size, int finishLine) : size(size), finishLine(finishLine) {}

    int getSize() const { return size; }
    int getFinishLine() const { return finishLine; }

private:
    int size;
    int finishLine;
};

#endif // RACETRACK_H
