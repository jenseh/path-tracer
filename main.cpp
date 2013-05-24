#include "PathTracer.h"
#include "Scene.h"

#include <GL/glfw.h>
#include <ctime>

int main () {

    int width = 512;
    int height = 512;
    int samples = 16;

    Scene scene(width, height);

    PathTracer pathTracer(width, height, &scene);

    Image image(width, height);

	glfwInit();
	
	glfwOpenWindow(width, height, 0, 0, 0, 0, 0, 0, GLFW_WINDOW);
	
	struct timespec startTime;
    clock_gettime(CLOCK_MONOTONIC, &startTime);
	
	int n = 0;
	while(glfwGetWindowParam(GLFW_OPENED)) {
		
		pathTracer.refineImage(image, n++);
		
		image.draw();
		
		glfwSwapBuffers();
		
		struct timespec currTime;
		clock_gettime(CLOCK_MONOTONIC, &currTime);
		int seconds = currTime.tv_sec - startTime.tv_sec;
		printf("%d Samples per Pixel, Total Rendering Time: %d:%02d\r", n, seconds / 60, seconds % 60);fflush(stdout);
	}
	
	glfwTerminate();
	
	/*struct timespec startTime;
    struct timespec endTime;
// Zeitmessung Anfang
    clock_gettime(CLOCK_MONOTONIC, &startTime);

    pathTracer.generateImage(image, samples);

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
    printf("%f Sekunde(n) berechnet.\n\n", 1.0E-9 * nseconds + (seconds % 60));*/

    image.saveToFile("./output.exr");

    return system("exrdisplay -1 ./output.exr");
}
