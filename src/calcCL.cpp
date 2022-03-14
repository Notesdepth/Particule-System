#include <particules.h>

void err(ocl *ocl, char *s)
{
    if (ocl->err_code != CL_SUCCESS)
    {
        printf("ERREUR %s%d:\n", s, ocl->err_code);
        char logErreurs[4096];
        size_t longueur_Log;

        clGetProgramBuildInfo(ocl->program, ocl->device, CL_PROGRAM_BUILD_LOG, sizeof(logErreurs), logErreurs, &longueur_Log);
        printf("%s\n", logErreurs);
        return;
    }
}

void release(ocl *ocl, cl_mem buffer)
{
    clReleaseKernel(ocl->kernel);
    clReleaseProgram(ocl->program);
    clReleaseCommandQueue(ocl->queue);
    clReleaseMemObject(buffer);
    clReleaseContext(ocl->context);
}

void CLReadBuffer(ocl *ocl, cl_mem screen_buffer, size_t size, void *p)
{
    ocl->err_code = clEnqueueReadBuffer(ocl->queue, screen_buffer, CL_TRUE, 0, size, p, 0, nullptr, nullptr);
    err(ocl, "CLReadBuffer : ");

}

void CLRangeKernel(ocl *ocl, int boucle_1, int boucle_2, int boucle_3, int nb_boucle)
{
    size_t dim[] = {(size_t)boucle_1, (size_t)boucle_2, (size_t)boucle_3}; //taille de chacune des trois boucles possibles
    ocl->err_code = clEnqueueNDRangeKernel(ocl->queue, ocl->kernel, nb_boucle, nullptr, dim, nullptr, 0, nullptr, nullptr);
    err(ocl, "CLRangeKernel : ");

}

void CLSetKernelArg(ocl *ocl, int pos, size_t size, void *var)
{
    ocl->err_code= clSetKernelArg(ocl->kernel, pos, size, var);
    err(ocl, "CLInitPlateform : ");
}

void CLCreateKernel(ocl *ocl, const char *source)
{
    ocl->kernel = clCreateKernel(ocl->program, source, &ocl->err_code);
    err(ocl, "CLCreateKernel : ");

}

cl_mem CLCreateBuffer(ocl *ocl, cl_mem_flags flags, size_t size, void *ptr_var)
{
    cl_mem mem = clCreateBuffer(ocl->context, flags, size, ptr_var, &ocl->err_code);
    err(ocl, "CLCreateBuffer : ");
    return (mem);

}



void CLBuild(ocl *ocl)
{
    ocl->err_code = clBuildProgram(ocl->program, 1/*nb_device*/, &ocl->device, nullptr, nullptr, nullptr);
    err(ocl, "CLBuild : ");

}

void CLCreateProgram(ocl *ocl, const char *prog_name)
{
    ifstream file;
    file.open(prog_name);
    if (!file)
    {
        printf("le fichier n'existe pas\n");
        printf("%s\n",strerror(errno));
        return;
    }

    size_t max_size = 0x1000000;
    char *source = (char*)malloc(max_size);

    streampos begin = file.tellg();
    file.seekg(0, ios::end);
    streampos end = file.tellg();
    size_t src_size = end - begin;
    file.seekg(0, file.beg);
    file.read(source, src_size);
    file.close();
    ocl->program = clCreateProgramWithSource(ocl->context, 1, (const char **)&source, (const size_t *)&src_size, &ocl->err_code);
    free(source);
    err(ocl, "CLCreateProgram : ");

}

void CLCreateCommandQueue(ocl *ocl, cl_command_queue_properties properties)
{
    ocl->queue = clCreateCommandQueue(ocl->context, ocl->device, properties, &ocl->err_code);
    err(ocl, "CLCreateCommandQueue : ");

}

void CLCreateContext(ocl *ocl, cl_context_properties context)
{
    cl_context_properties properties[3];
    properties[0] = (cl_context_properties) CL_CONTEXT_PLATFORM;
    properties[1] = (cl_context_properties) ocl->platform;
    properties[2] = 0;
    ocl->context = clCreateContext(properties, 2/*nb de devices, peut possiblement varier*/, &ocl->device, nullptr, nullptr, &ocl->err_code);
    err(ocl, "CLCreateContext : ");
}

void CLInitPlateform(ocl *ocl, int nb_entries)
{
    ocl->nb_entries = nb_entries;
    ocl->err_code = clGetPlatformIDs(nb_entries, &ocl->platform, &ocl->nb_entries); //création de la plateforme
    ocl->err_code = clGetDeviceIDs(ocl->platform, CL_DEVICE_TYPE_GPU, nb_entries, &ocl->device, &ocl->nb_entries);
    err(ocl, "CLInitPlateform : ");
}

void draw(Window *win, particule *p, int nb_particules)
{
    int i = -1;
    while (++i < nb_particules)
    {
        SDL_SetRenderDrawColor(win->render, 255 , 255 , 255, 255);
        SDL_RenderDrawPoint(win->render, (int)p->x[i], p->y[i]);
    }
}

int move(SDL_Event *event, Window *win, bool *mv_trans, int *sens_trans, bool *mv_rot, int *sens_rot)
{
    while (SDL_PollEvent(event))
    {
        if (event->type == SDL_QUIT || (event->type == SDL_KEYDOWN && event->key.keysym.sym == SDLK_ESCAPE))
        {
            SDL_DestroyRenderer(win->render);
            SDL_DestroyWindow(win->w);
            SDL_Quit();
            return (1);
        }

        //translation
        if (event->type == SDL_KEYDOWN && event->key.keysym.sym == SDLK_d)
        {
            mv_trans[0] =true;
            sens_trans[0] = 1;
        }
        else if (event->type == SDL_KEYDOWN && event->key.keysym.sym == SDLK_q)
        {
            mv_trans[0] = true;
            sens_trans[0] = -1;
        }
        if (event->type == SDL_KEYDOWN && event->key.keysym.sym == SDLK_s)
        {
            mv_trans[1] =true;
            sens_trans[1] = 1;
        }
        else if (event->type == SDL_KEYDOWN && event->key.keysym.sym == SDLK_z)
        {
            mv_trans[1] = true;
            sens_trans[1] = -1;
        }
        if (event->type == SDL_KEYDOWN && event->key.keysym.sym == SDLK_r)
        {
            mv_trans[2] =true;
            sens_trans[2] = 1;
        }
        else if (event->type == SDL_KEYDOWN && event->key.keysym.sym == SDLK_f)
        {
            mv_trans[2] = true;
            sens_trans[2] = -1;
        }

        //rotation
        if (event->type == SDL_KEYDOWN && event->key.keysym.sym == SDLK_i)
        {
            mv_rot[0] =true;
            sens_rot[0] = 1;
        }
        if (event->type == SDL_KEYDOWN && event->key.keysym.sym == SDLK_k)
        {
            mv_rot[0] = true;
            sens_rot[0] = -1;
        }
        if (event->type == SDL_KEYDOWN && event->key.keysym.sym == SDLK_l)
        {
            mv_rot[1] =true;
            sens_rot[1] = 1;
        }
        if (event->type == SDL_KEYDOWN && event->key.keysym.sym == SDLK_j)
        {
            mv_rot[1] = true;
            sens_rot[1] = -1;
        }
        if (event->type == SDL_KEYDOWN && event->key.keysym.sym == SDLK_o)
        {
            mv_rot[2] =true;
            sens_rot[2] = 1;
        }
        if (event->type == SDL_KEYDOWN && event->key.keysym.sym == SDLK_u)
        {
            mv_rot[2] = true;
            sens_rot[2] = -1;
        }
    }
    return (0);
}

int execCL(ocl *ocl, const char *s, char *prog_name, particule *p, int nb_particules, Window *win, int height)
{
    int sens_trans[3] = {0, 0, 0};
    bool mv_trans[3] = {false, false, false};
    int sens_rot[3] = {0, 0, 0};
    bool mv_rot[3] = {false, false, false};

    SDL_Event event;
    if (move(&event, win, mv_trans, sens_trans, mv_rot, sens_rot))
        return (0);


    CLInitPlateform(ocl, 2);
    CLCreateContext(ocl, (cl_context_properties)CL_CONTEXT_PLATFORM);
    CLCreateCommandQueue(ocl, (cl_command_queue_properties) CL_QUEUE_PROFILING_ENABLE);
    CLCreateProgram(ocl, prog_name);
    CLBuild(ocl);
    cl_mem x_buffer = CLCreateBuffer(ocl, CL_MEM_READ_WRITE| CL_MEM_USE_HOST_PTR, sizeof(float) * nb_particules, p->x);
    cl_mem y_buffer = CLCreateBuffer(ocl, CL_MEM_READ_WRITE| CL_MEM_USE_HOST_PTR, sizeof(float) * nb_particules, p->y);
    cl_mem z_buffer = CLCreateBuffer(ocl, CL_MEM_READ_WRITE| CL_MEM_USE_HOST_PTR, sizeof(float) * nb_particules, p->z);
    cl_mem sens_trans_buffer = CLCreateBuffer(ocl, CL_MEM_READ_WRITE| CL_MEM_USE_HOST_PTR, sizeof(int) * 3, sens_trans);
    cl_mem mv_trans_buffer = CLCreateBuffer(ocl, CL_MEM_READ_WRITE| CL_MEM_USE_HOST_PTR, sizeof(bool) * 3, mv_trans);
    cl_mem sens_rot_buffer = CLCreateBuffer(ocl, CL_MEM_READ_WRITE| CL_MEM_USE_HOST_PTR, sizeof(int) * 3, sens_rot);
    cl_mem mv_rot_buffer = CLCreateBuffer(ocl, CL_MEM_READ_WRITE| CL_MEM_USE_HOST_PTR, sizeof(bool) * 3, mv_rot);
    CLCreateKernel(ocl, s);
    CLSetKernelArg(ocl, 0, sizeof(int), &nb_particules);
    CLSetKernelArg(ocl, 1, sizeof(int), &height);
    CLSetKernelArg(ocl, 2, sizeof(cl_mem), &x_buffer);
    CLSetKernelArg(ocl, 3, sizeof(cl_mem), &y_buffer);
    CLSetKernelArg(ocl, 4, sizeof(cl_mem), &z_buffer);
    CLSetKernelArg(ocl, 5, sizeof(cl_mem), &sens_trans_buffer);
    CLSetKernelArg(ocl, 6, sizeof(cl_mem), &mv_trans_buffer);
    CLSetKernelArg(ocl, 7, sizeof(cl_mem), &sens_rot_buffer);
    CLSetKernelArg(ocl, 8, sizeof(cl_mem), &mv_rot_buffer);
    CLRangeKernel(ocl, nb_particules, 0, 0, 1);
    //CLReadBuffer(ocl, y_buffer, sizeof(float) * nb_particules, p->y);

    if (ocl->err_code !=CL_SUCCESS)
        return (0);

    SDL_SetRenderDrawColor(win->render, 0, 0, 0, 255);
    SDL_RenderClear(win->render);
    draw(win, p, nb_particules);
    SDL_UpdateWindowSurface(win->w);

    release(ocl, x_buffer);
    clReleaseMemObject(y_buffer);
    clReleaseMemObject(z_buffer);
    clReleaseMemObject(mv_trans_buffer);
    clReleaseMemObject(sens_trans_buffer);
    clReleaseMemObject(mv_rot_buffer);
    clReleaseMemObject(sens_rot_buffer);
    return (1);
}