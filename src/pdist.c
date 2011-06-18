#include <math.h>

//Euclidean distance between two vectors
float dist(float* x, float *y, int nx, int ny, int p)
{
  float distance = 0;
  for(int i = 0; i < p; i++)
  {
    float diff = x[i*nx] - y[i*ny];
    distance += (diff*diff);
  }
  return sqrt(distance);
}

//C implementation of pdist
void Rpdist(float* X, float* Y, int* Rnx, int* Rny, int* Rp, float* distances)
{
  int nx = Rnx[0];
  int ny = Rny[0];
  int p = Rp[0];
  for(int i = 0; i < nx; i++) 
  {
    float* x = X + i;  //a single row of X
    for(int j = 0; j < ny; j++)
    {
      float* y = Y + j;
      float distance = dist(x,y,nx,ny,p);
      distances[i*ny+j] = distance;
    }
  }
}
