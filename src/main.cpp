#include <particules.h>
#include <ctime>

int main() {
    srand((unsigned) time(nullptr));

    particule p;
    int nb_particules = 5000;
    int ray_max = 50;
    int end = 1;
    ocl ocl;
    int i = -1;
    int j = -1;
    p.x = (float *)malloc(sizeof(float) * nb_particules);
    p.y = (float *)malloc(sizeof(float) * nb_particules);
    p.z = (float *)malloc(sizeof(float) * nb_particules);
    p.ray = (float *)malloc(sizeof(float) * nb_particules);
    p.poids = (float *)malloc(sizeof(float) * nb_particules);
    p.color = (color *)malloc(sizeof(color) * nb_particules);

    p.x[i] = (float)(rand() % (WIDTH + 1));

    while (++i != nb_particules)
    {
        p.x[i] = (float)(rand() % (WIDTH + 1));
        p.y[i] = (float)(rand() % (HEIGHT + 1));
        while (++j < i)
        {
            if (p.x[i] == p.x[j] && p.y[i] == p.y[j]) //évite de définir deux particules au même endroit
            {
                p.x[i] = (float)(rand() % (WIDTH + 1));
                p.y[i] = (float)(rand() % (HEIGHT + 1));
                j = -1;
            }
        }
        j = -1;

        p.z[i] = 0.0f;
        p.ray[i] = (float)(rand() % (ray_max + 1));
        p.poids[i] = 1;
        p.color[i].r = /*rand() % (255) + 1;*/255;
        p.color[i].g = /*rand() % (255) + 1;*/255;
        p.color[i].b = /*rand() % (255) + 1;*/255;
    }


    Window win(WIDTH, HEIGHT);
    SDL_SetRenderDrawColor(win.render, 0, 0, 0, 255);
    SDL_RenderClear(win.render);


    i = -1;
    float *input_data = (float *)malloc(sizeof(float) * nb_particules);
    while (++i < nb_particules)
    {
        input_data[i] = (float)(rand() % (HEIGHT + 1));

    }

    while (end)
        //end = loop(&win, &p, nb_particules);
        end = execCL(&ocl, "fall", "CL/particules.cl", &p, nb_particules, &win, HEIGHT);

    free(p.x);
    free(p.y);
    free(p.z);
    free(p.ray);
    free(p.poids);
    free(p.color);
    free (input_data);
    return (0);
}
