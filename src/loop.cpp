#include <particules.h>

void draw1(Window *win, particule *p, int nb_particules)
{
    int i = -1;
    while (++i < nb_particules)
    {
        SDL_SetRenderDrawColor(win->render, p->color[i].r, p->color[i].g, p->color[i].b, 255);
        SDL_RenderDrawPoint(win->render, (int)p->x[i], (int)p->y[i]);
    }
}

void fall(particule *p, int nb_particules)
{
    int i = -1;
    int j = -1;

    while (++i < nb_particules)
    {
        if (p->y[i] < HEIGHT - 1)
            p->y[i] += p->poids[i];
        while (++j < nb_particules)
        {
           if (p->x[i] == p->x[j] && p->y[i] == p->y[j] && i != j)
                p->y[i] -= p->poids[i];
        }
        j = -1;
    }

    /*if (p->y + p->ray < HEIGHT)
        p->y += 1 * p->poids;
    if (p->y > HEIGHT)
        p->y = HEIGHT;*/


}

int loop(Window *win, particule *p, int nb_particules)
{
    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
        if (event.type == SDL_QUIT || (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE))
        {
            SDL_DestroyRenderer(win->render);
            SDL_DestroyWindow(win->w);
            SDL_Quit();
            return (0);
        }
    }

    SDL_SetRenderDrawColor(win->render, 0, 0, 0, 255);
    SDL_RenderClear(win->render);

    fall(p, nb_particules);
    draw1(win, p, nb_particules);
    SDL_UpdateWindowSurface(win->w);

    return (1);
}