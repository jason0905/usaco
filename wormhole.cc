/*
ID: jason091
LANG: C++
TASK: wormhole
*/

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

struct wormhole {
    int x, y, index;
    wormhole * linked;
    wormhole * next;
    bool isConnected() {
        if(linked != 0) return true;
        return false;
    }
    void disconnect() {
        linked -> linked = 0;
        linked = 0;
    }
    void connect(wormhole * otherHole) {
        otherHole -> linked = this;
        linked = otherHole;
    }
};

ostream & operator << (ostream & o, const wormhole & w) {
    return o << w.x << " " << w.y;
}

wormhole * findNext(wormhole * hole, const vector<wormhole *> & wormholes) {
    wormhole * next = 0;
    for(int i = 0; i < wormholes.size(); i++) {
        if(next == 0 && wormholes[i] -> y == hole -> y && wormholes[i] -> x > hole -> x)
            next = wormholes[i];
        if(next != 0 && wormholes[i] -> y == hole -> y && wormholes[i] -> x > hole -> x && wormholes[i] -> x < next -> x)
            next = wormholes[i];
    }

    return next;
}

bool alive(wormhole * hole, const vector<wormhole *> & wormholes) {
    wormhole * currHole = hole;
    do {
        currHole = currHole -> linked -> next;
        if(currHole == 0) return true;
    }
    while (hole != currHole);
    return false;
}

bool dead(const vector<wormhole *> & wormholes) {
    for(int i = 0; i < wormholes.size(); i++) {
        if(!alive(wormholes[i], wormholes)) return true;
    }

    return false;
}

wormhole * nextEmpty(wormhole * hole, const vector<wormhole *> & wormholes) {
    for(int i = hole -> index; i < wormholes.size(); i++) {
        if(wormholes[i] -> linked == 0) 
            return wormholes[i];
    }

    return 0;
}

void stuckNum(const vector<wormhole *> & wormholes, int layer, int & count) {
    wormhole * hole  = nextEmpty(wormholes[0], wormholes);

    if(hole == 0) {
        if(dead(wormholes))
            count++;
        return;
    }
    for(int i = hole -> index + 1; i < wormholes.size(); i++) {
        if(wormholes[i] -> linked != 0) continue;
        wormhole * hole1 = wormholes[i];
        hole -> connect(hole1);
        stuckNum(wormholes, layer + 1, count);
        hole -> disconnect();
    }
}

int stuck(const vector<wormhole *> & wormholes) {
    int fail = 0;
    stuckNum(wormholes, 0, fail);
    return fail;
}

int main() {
    ifstream in ("wormhole.in");
    ofstream out ("wormhole.out");

    vector<wormhole *> wormholes;
    int N;

    in >> N;

    for(int i = 0; i < N; i++) {
        wormholes.push_back(new wormhole());
        in >> wormholes[i] -> x >> wormholes[i] -> y;
        wormholes[i] -> linked = 0;
        wormholes[i] -> index = i;
    }

    for(int i = 0; i < N; i++) {
        wormholes[i] -> next = findNext(wormholes[i], wormholes);
    }

    int x = stuck(wormholes);

    out << x << endl;
}
