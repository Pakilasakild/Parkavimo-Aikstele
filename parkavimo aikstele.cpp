#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    fstream in ("U1.txt");
    int n, m, pinigai = 0;
    in >> n >> m;
    int ikainis[n];
    int svoris[m];
    int aikstele[n+1] = {0, 0, 0};
    for (int i = 0; i < n; i++)
    {
        in >> ikainis[i];
    }
    for (int i = 0; i < m; i++)
    {
        in >> svoris[i];
    }
    for (int i = 0; i <2*m; i++)
    {
        char op;
        int aut;
        in >> op >> aut;
        if (op == '+')
        {
            if (aikstele[0] == 0)
            {
                aikstele[0] = aut;
                pinigai = pinigai + svoris[aut-1]*ikainis[0];
            }
            else if (aikstele[1] == 0)
            {
                aikstele[1] = aut;
                pinigai += svoris[aut-1]*ikainis[1];
            }
            else if (aikstele[2] == 0)
            {
                aikstele[2] = aut;
            }
        }
        else if (op == '-')
        {
            if (aikstele[0] == aut)
            {
                aikstele[0] = 0;
            }
            else if (aikstele[1] == aut)
            {
                aikstele[1] = 0;
            }
            if (aikstele[2] != 0 && aikstele[0] == 0)
            {
                aikstele[0] = aikstele[2];
                aikstele[2] = 0;
                pinigai += svoris[aikstele[0]-1]*ikainis[0];

            }
            if (aikstele[2] != 0 && aikstele[1] == 0)
            {
                aikstele[1] = aikstele[2];
                aikstele[2] = 0;
                pinigai += svoris[aikstele[1]-1]*ikainis[1];
                              //  cout << "aikst 1 uzpildyta, saibos: " << svoris[aikstele[1]] << "IR " << ikainis[1] << endl;
            }
        }
          //  cout << "Pirma aikstelej stovi: " << aikstele[0] << " Antra aikstelej stovi: " << aikstele[1] << " Laukia: " << aikstele[2] << " Pinigai = " << pinigai << endl;
    }

in.close();
ofstream out ("U1rez.txt");
out << pinigai;
out.close();
return 0;
}
