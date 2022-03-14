#ifndef COS_THETA
#define COS_THETA 0.984807753f// = cos(10° * PI/180)
#endif
#ifndef SIN_THETA
#define SIN_THETA 0.1736481777f// = sin(10° * PI/180)
#endif
#ifndef SIN_THETA_N
#define SIN_THETA_N -0.1736481777f// = sin(-10° * PI/180)
#endif

typedef struct color
{
    int r;
    int g;
    int b;
}               color;

typedef struct particule
{
    float x;
    float y;
    float z;
    float ray;
    float poids;
    color color;
}           particule;


__kernel void changeTranslation(__global float *axe, int signe)
{
    int i = get_global_id(0);
    axe[i] += signe;
}

__kernel void changeRotation(__global float *x, __global float *y, __global float *z, int signe, __global bool *mv_rot)
{
    int i = get_global_id(0);
    if (signe >= 0)
    {
        if (mv_rot[0]) //rotation axe x
        {
            y[i] = y[i] * COS_THETA - z[i] * SIN_THETA;
            z[i] = y[i] * SIN_THETA + z[i] * COS_THETA;
        }
        if (mv_rot[1]) //rotation axe y
        {
            x[i] = x[i] * COS_THETA + z[i] * SIN_THETA;
            z[i] = - x[i] * SIN_THETA + z[i] * COS_THETA;
        }
        if (mv_rot[2]) //rotation axe z
        {
            x[i] = x[i] * COS_THETA - y[i] * SIN_THETA;
            y[i] = x[i] * SIN_THETA + y[i] * COS_THETA;
        }
    }
    else
    {
        if (mv_rot[0]) //rotation axe x
        {
            y[i] = y[i] * COS_THETA - z[i] * SIN_THETA_N;
            z[i] = y[i] * SIN_THETA_N + z[i] * COS_THETA;
        }
        if (mv_rot[1]) //rotation axe y
        {
            x[i] = x[i] * COS_THETA + z[i] * SIN_THETA_N;
            z[i] = - x[i] * SIN_THETA_N + z[i] * COS_THETA;
        }
        if (mv_rot[2]) //rotation axe z
        {
            x[i] = x[i] * COS_THETA - y[i] * SIN_THETA_N;
            y[i] = x[i] * SIN_THETA_N + y[i] * COS_THETA;
        }
    }

}


__kernel void fall(
        int nb_particules,
        int height,
        __global float *x,
        __global float *y,
        __global float *z,
        __global int *sens_trans,
        __global bool *mv_trans,
        __global int *sens_rot,
        __global bool *mv_rot)
{
   // int i = get_global_id(0);
    //int j = -1;
    //if (y[i] < height - 1)
    //    y[i] += 1;
    /* while (++j < nb_particules)
     {
         if (y[i] == y[j] && i != j)//collision --> rajouter x == x
             y[i] -= 1;
     }*/

    if (mv_trans[0])
        changeTranslation(x, sens_trans[0]);
    if (mv_trans[1])
        changeTranslation(y, sens_trans[1]);
    if (mv_trans[2])
        changeTranslation(z, sens_trans[2]);
    if (mv_rot[0])
        changeRotation(x, y , z, sens_rot[0], mv_rot);
    if (mv_rot[1])
        changeRotation(x, y , z, sens_rot[1], mv_rot);
    if (mv_rot[2])
        changeRotation(x, y , z, sens_rot[2], mv_rot);



}