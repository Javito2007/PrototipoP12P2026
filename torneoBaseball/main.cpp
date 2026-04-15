#include "baseBall.h"
#include <cstdlib>
#include <unistd.h>
int main() {
    srand(getpid());
    baseBall miTorneo;
    miTorneo.llamaCiclo();
    return 0;
}
