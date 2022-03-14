//
// Created by Notesdepth on 28/08/2020.
//

#ifndef PARTICULES_SYSTEM_PARTICULES_H
#define PARTICULES_SYSTEM_PARTICULES_H
#define CL_SILENCE_DEPRECATION

#include <iostream>
#include <random>
#include <cstdlib>
#include <ctime>
#include <SDL.h>
#include <OpenCL/cl.h>
#include <fstream>
using namespace std;


#define HEIGHT 850
#define WIDTH 1440

typedef struct pos
{
    int x;
    int y;
}               pos;

typedef struct color
{
    int r;
    int g;
    int b;
}               color;

class Window
{
public :
    Window(int width, int height);
    SDL_Window *w;
    SDL_Renderer *render;
};

typedef struct particule
{
    float *x;
    float *y;
    float *z;
    float *ray;
    float *poids;
    color *color;
}           particule;


typedef struct ocl
{
    cl_int err_code;
    cl_uint nb_entries;
    cl_platform_id platform;

    cl_device_id device;
    cl_context context;
    cl_command_queue queue;
    cl_program program;
    cl_mem inputBuffer;
    cl_mem outputBuffer;
    cl_kernel kernel;
}               ocl;

int loop(Window *win, particule *p, int nb_particules);
int execCL(ocl *ocl, const char *s, char *prog_name, particule *p, int nb_particules, Window *win, int height);

#endif //PARTICULES_SYSTEM_PARTICULES_H
