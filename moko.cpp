#include <iostream>

using namespace std;

int main()
{
    int n, m, pinigai;
    cin >> n >> m;
    int ikainis[n];
    int svoris[m];
    int aikstele[n+1] = {0, 0, 0};
    for (int i = 0; i < n; i++)
    {
        cin >> ikainis[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> svoris[i];
    }
    for (int i = 0; i < 2*m; i++)
    {
        char op;
        int aut;
        cin >> op >> aut;
        switch(op)
        {
        case '+':
            if (aikstele[0] == 0)
            {
                aikstele[0] = aut;
                pinigai += aut*ikainis[0];
            }
            else if (aikstele[1] == 0)
            {
                aikstele[1] = aut;
                pinigai += aut*ikainis[0];
            }
            else if (aikstele[2] == 0)
            {
                aikstele[2] = aut;
            }
        }
    }
    return 1;
}
