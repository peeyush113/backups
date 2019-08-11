typedef struct {
  int x, y;
  char info[32];
} Point;

int main(int argc, char* argv[])
{
  Point pt;
  Point* ppt;

  int i, j, x, y, t;
  int A[10];

  ppt = &pt;  

  for (j = 0; j < 32; ++j)
  {

  for (i = 0; i < 10; ++i)
  {
    if (t == 5)
      t = 3;

    pt.x = 1;
    pt.y = 2;

    ppt->x = 3;
    ppt->y = 4;

    ppt->info[j] = 1;

    A[i] = 42;
    t = x;
    x = x + i;
    y += i;
    y = y + t;
    t = A[i];
  }

  }

  return 0;
}
