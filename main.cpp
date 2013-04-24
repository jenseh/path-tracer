#include "PathTracer.h"
#include "Scene.h"

#include <ctime>

int main () {

    int width = 512;
    int height = 512;
    int samples = 16;

    Scene scene(width, height);

    PathTracer pathTracer(width, height, samples, &scene);

    Image image(width, height);

    struct timespec startTime;
    struct timespec endTime;
// Zeitmessung Anfang
    clock_gettime(CLOCK_MONOTONIC, &startTime);

    pathTracer.generateImage(image);

// Zeitmessung Ende
    clock_gettime(CLOCK_MONOTONIC, &endTime);
    int seconds = endTime.tv_sec - startTime.tv_sec;
    int nseconds = endTime.tv_nsec - startTime.tv_nsec;
    printf("\nBild in ");
    if(seconds > 3600) {
        printf("%d Stunde(n),", seconds / 3600);
    }
    if(seconds > 60) {
        printf("%d Minute(n) und ", seconds % 3600 / 60);
    }
    printf("%f Sekunde(n) berechnet.\n\n", 1.0E-9 * nseconds + (seconds % 60));

    image.saveToFile("./output.exr");

    return system("exrdisplay ./output.exr");
}
