int main(int argc, char* argv[])
{
  int i, j, c;

  for (i = 0; i < 10; ++i)
  {
    j += 2;
  }

  for (i = 0; i < 10; ++i)
  {
    j = j + 5;
  }

  for (i = 0; i < 10; ++i)
  {
    j = j + c;
  }

  return 0;
}
