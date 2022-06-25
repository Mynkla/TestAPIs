// TestAPIs.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <stdio.h>
#include <iostream>

#include "SDL.h"

#include <GL/glew.h>
#include <GL/freeglut.h>
#include <GL/glut.h>
#include <GLFW/glfw3.h>
//#include <glad/glad.h>

#include <Windows.h>

using namespace std;

int wndoHit = 480, wndoWdth = 854;

void Test_SDL() {

    if (SDL_Init(SDL_INIT_VIDEO)) cout << "Error: SDL " << SDL_GetError() << endl;

    SDL_Window* sdlWndo = SDL_CreateWindow("SDL Window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, wndoWdth, wndoHit, SDL_WINDOW_SHOWN);
    if (sdlWndo == NULL) printf("Window Create Error");

    SDL_Surface* sdlSrfc = SDL_GetWindowSurface(sdlWndo);
    SDL_PixelFormat* pxlFrmt = sdlSrfc->format;

    uint8_t r = 255, g = 0, b = 0, a = 255;
    auto mClr = SDL_MapRGBA(pxlFrmt, r, g, b, a);
    SDL_Rect rect = { wndoWdth/2, wndoHit/2, 100, 100 };
    SDL_FillRect(sdlSrfc, &rect, mClr);

    SDL_UpdateWindowSurface(sdlWndo);

    bool rnsdl = true;
    while (rnsdl) {
        SDL_Event sdlevnt;
        while (SDL_PollEvent(&sdlevnt)) {
            if (sdlevnt.type == SDL_QUIT) rnsdl = false;
        }
    }

    SDL_DestroyWindow(sdlWndo);
    SDL_Quit();
}

void displayGlut()
{
    //glClearColor(1.0, 1.0, 1.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0, 0, 0);
    glRotatef(45, 1, 1, 1);

    // White side - BACK
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(0.5, -0.5, 0.5);
    glVertex3f(0.5, 0.5, 0.5);
    glVertex3f(-0.5, 0.5, 0.5);
    glVertex3f(-0.5, -0.5, 0.5);
    glEnd();

    // Purple side - RIGHT
    glBegin(GL_QUADS);
    glColor3f(1.0, 0.0, 1.0);
    glVertex3f(0.5, -0.5, -0.5);
    glVertex3f(0.5, 0.5, -0.5);
    glVertex3f(0.5, 0.5, 0.5);
    glVertex3f(0.5, -0.5, 0.5);
    glEnd();

    // Green side - LEFT
    glBegin(GL_QUADS);
    glColor3f(0.0, 1.0, 0.0);
    glVertex3f(-0.5, -0.5, 0.5);
    glVertex3f(-0.5, 0.5, 0.5);
    glVertex3f(-0.5, 0.5, -0.5);
    glVertex3f(-0.5, -0.5, -0.5);
    glEnd();

    // Blue side - TOP
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 1.0);
    glVertex3f(0.5, 0.5, 0.5);
    glVertex3f(0.5, 0.5, -0.5);
    glVertex3f(-0.5, 0.5, -0.5);
    glVertex3f(-0.5, 0.5, 0.5);
    glEnd();

    // Red side - BOTTOM
    glBegin(GL_QUADS);
    glColor3f(1.0, 0.0, 0.0);
    glVertex3f(0.5, -0.5, -0.5);
    glVertex3f(0.5, -0.5, 0.5);
    glVertex3f(-0.5, -0.5, 0.5);
    glVertex3f(-0.5, -0.5, -0.5);
    glEnd();

    glFlush();
    glutSwapBuffers();
}

void Test_GLUT(int c, char** v) {
    glutInit(&c, v);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("GLUT Window");
    glutInitWindowSize(wndoWdth, wndoHit);
    glutDisplayFunc(displayGlut);
    glutMainLoop();
}


void Test_GLFW() {
    GLFWwindow* window;

    if (!glfwInit()) printf("Error glfw");

    window = glfwCreateWindow(wndoWdth, wndoHit, "GLFW Windo", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        printf("Error Loading Window");
    }

    while (!glfwWindowShouldClose(window))
    {
        glClear(GL_COLOR_BUFFER_BIT);
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
}

int main(int argc, char* argv[])
{
    cout << "HelloWorld\n";

    //Test_SDL();
    Test_GLUT(argc, argv);
    //Test_GLFW();

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
