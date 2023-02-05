#include <stdio.h>

#define INF 9999999
typedef struct
{
  int pos;
  int val;
} TGrafo;

int numNodi;
int numClassifica;
int size = 0;

void leggiMatrice(int matrice[numNodi][numNodi])
{
  char car;
  int parziale = 0;
  int col = 0, riga = 0;
  while (riga < numNodi)
  {
    car = getchar_unlocked();
    if(car >= '0' && car <= '9')
      parziale = parziale * 10 + (car - '0');
    if(car == ',' || car == '\n')
    {
      matrice[riga][col] = parziale;
      parziale = 0;
      if(col == numNodi-1)
      {
        col = 0;
        riga++;
      }
      else col++;
    }
  }
}

int Dijkstra(int matrice[numNodi][numNodi])
{
  int cost[numNodi][numNodi], dist[numNodi];
  int visited[numNodi], count, mindist, nodoSucc = 0, i, j;
  int start = 0, sommaDist = 0;
  for (i = 0; i < numNodi; i++)
  {
    dist[i] = cost[start][i];
    visited[i] = 0;
    for (j = 0; j < numNodi; j++)
      if (matrice[i][j] == 0)
        cost[i][j] = INF;
      else
        cost[i][j] = matrice[i][j];
  }
  dist[start] = 0;
  visited[start] = 1;
  count = 1;
  while (count < numNodi - 1)
  {
    mindist = INF;
    for (i = 0; i < numNodi; i++)
      if (dist[i] < mindist && !visited[i])
      {
        mindist = dist[i];
        nodoSucc = i;
      }
    visited[nodoSucc] = 1;
    for (i = 0; i < numNodi; i++)
      if (!visited[i])
        if (mindist + cost[nodoSucc][i] < dist[i])
        {
          dist[i] = mindist + cost[nodoSucc][i];
        }
    count++;
  }
  for (i = 1; i < numNodi; i++)
  {
    if (dist[i] < INF)
    {
      sommaDist += dist[i];
    }
  }
  return sommaDist;
}

void swap(TGrafo *a, TGrafo *b)
{
  TGrafo temp = *b;
  *b = *a;
  *a = temp;
}
void maxheapify(TGrafo array[numClassifica], int n)
{
  int sx = 2 * n;
  int dx = 2 * n + 1;
  int posmax;
  if (sx <= size && array[sx].val > array[n].val)
    posmax = sx;
  else posmax = n;
  if (dx <= size && array[dx].val > array[posmax].val)
    posmax = dx;
  if (posmax != n)
  {
    swap(&array[n], &array[posmax]);
    maxheapify(array, posmax);
  }
}

void insert(TGrafo array[numClassifica], int newNum, int pos)
{
  if(size < numClassifica)
  {
    size++;
    array[size].val = newNum;
    array[size].pos = pos;
    int i = size;
    while (i > 1 && array[i/2].val <= array[i].val)
    {
      swap(&array[i/2], &array[i]);
      i = i/2;
    }
  }
  else if (array[1].val > newNum)
  {
    array[1].val = newNum;
    array[1].pos = pos;
    maxheapify(array, 1);
  }
}

void stampa(int num)
{
  if(num/10 != 0)
  {
    stampa(num/10);
  }
  putchar(num%10+'0');
}

void printArray(TGrafo array[numClassifica])
{
  int i = 1;
  if(size != 0)
  {
    while(i < numClassifica && i < size)
    {
      stampa(array[i].pos);
      putchar(' ');
      i++;
    }
    stampa(array[i].pos);
  }
  putchar('\n');
}

int main(int argc, char *argv[])
{
  if(scanf("%d %d", &numNodi, &numClassifica));
  int matrice[numNodi][numNodi];
  TGrafo array[numClassifica+1];
  char lettura[20];
  int cont = 0;
  while(fgets(lettura,sizeof(lettura),stdin)!=NULL)
  {
    if(lettura[0] == 'A')
    {
      leggiMatrice(matrice);
      insert(array, Dijkstra(matrice), cont++);
    }
    if(lettura[0] == 'T')
    {
      printArray(array);
    }
  }
  return 0;
}
