#include <iostream>
#include <vector>

using namespace std;

int main()
{
  int l1, l2, c2;

  cin >> l1;
  cin >> l2;
  cin >> c2;

  // l2 = colunas da matriz1, alem de linha2
  vector<vector<int> > matriz1(l1, vector<int>(l2));
  vector<vector<int> > matriz2(l2, vector<int>(c2));

  for (int i = 0; i < l1; i++)
  {
    for (int j = 0; j < l2; j++)
    {
      cin >> matriz1[i][j];
    }
  }

  for (int i = 0; i < l2; i++)
  {
    for (int j = 0; j < c2; j++)
    {
      cin >> matriz2[i][j];
    }
  }

  // MULTIPLICACAO DA matA e matB

  int m = 0;
  vector<vector<int> > mult(l1, vector<int>(c2));
  for (int i = 0; i < l1; i++)
  {
    for (int j = 0; j < c2; j++)
    {
      mult[i][j] = 0;
      for (int k = 0; k < l2; k++)
      {
        m += matriz1[i][k] * matriz2[k][j];
      }
      mult[i][j] = m;
      m = 0;
    }
  }

  for (int i = 0; i < l1; i++)
  {
    for (int j = 0; j < c2; j++)
    {
      cout << mult[i][j] << " ";
    }
    cout << endl;
  }
}