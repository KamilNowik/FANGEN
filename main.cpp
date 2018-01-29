#include <iostream>
#include <math.h>
#include <cstdlib>

using namespace std;

class Draw
{public:
    virtual void drawing()=0;
};

class Load
{
protected:
     int n;
      void loading()
    {
        cin>>n;
        if(n==0) exit(0); /// metoda wczytuj¹ca i sprawdzaj¹ca czy n!=0.
    }
};

class Fan :public Load, public Draw
{

    int p;
    char A[400][400];

public:

    virtual void drawing()
    {
        Load::loading();
        if(n<0) p=0;
        if(n>0) p=1; /// tu ustalam "skrêtnoœæ wiatraka".
        n=fabs(n);

        for(int i=0; i<2*n; i++)
        {
            for (int j=0; j<2*n;j++)  /// wype³niam tablicê kropkami.
            {
                A[i][j]='.';
            }
        }

        for(int i=n-1; i<=n; i++)
        {
            for(int j=n-1; j<=n; j++) /// wstawiam macierz 2x2 z gwiazdek w centrum macierzy g³ównej.
            {
                A[i][j]='*';
            }
        }

        for (int i=0;i<2*n;i++)
        {
            A[i][i]='*';         /// wstawiam gwiazdki na obu przek¹tnych.
            A[i][n*2-1-i]='*';
        }

        framing();
   }

    virtual void framing()
    {
        if(p==1)
        {
            for(int i=0; i<n; i++)
            {
                for(int j=i; j<n; j++) A[j][i]='*';
                for(int j=2*n-1-i;j<2*n;j++) A[j][i]='*';
                for(int j=2*n-1-i; j<2*n; j++) A[2*n-1-i][j]='*'; /// rysujê wiatrak, lewoskrêtny
                for(int j=2*n-1-i; j>=n; j--) A[i][j]='*';
            }

            for(int i=0; i<2*n; i++)
                {
                    for (int j=0; j<2*n;j++)
                    {
                        cout<< A[i][j];

                    }
                    cout<<endl;
                }
        }

        if(p==0)
        {

            for(int i=0; i<n; i++)
            {
                for(int j=i; j<n; j++) A[i][j]='*';
                for(int j=2*n-1-i;j<2*n;j++) A[i][j]='*';
                for(int j=2*n-1-i; j>=n; j--) A[2*n-1-i][j]='*';  /// rysujê wiatrak, prawoskrêtny
                for(int j=i; j>=0; j--) A[2*n-1-i][j]='*';
            }
            for(int i=0; i<2*n; i++)
                {
                    for (int j=0; j<2*n;j++)
                    {
                        cout<< A[i][j];

                    }
                    cout<<endl;
                }
        }
    }
};





int main()
{
Fan w;
Draw *wsk;
wsk=&w;
while(true)
{
    wsk->drawing();
}
    return 0;
}
