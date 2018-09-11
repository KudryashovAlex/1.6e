#include<iostream>
#include<cstdlib>
#include<fstream>
#include <iomanip>
using namespace std;
class slc{
    private:
float **mass;
float **rev;
int r = 3;
    public:
    slc();
    ~slc();
void show();
void doorev();
void full();
friend float* sum(float *a, float *b, int N);
friend float* del(float *a, float M, int N);
void test();
};
 float* sum (float *a, float *b, int N){
    for (int i = 0; i < N; i++)
        a[i] += b[i];
    return a;
 }
float* del(float *a, float M, int N){
    for (int i = 0; i < N; i++)
        a[i] /= M;
    return a;
 }
slc::slc(){
    rev = new float*[r];
    for(int j = 0; j < r; j++)
        rev[j] = new float[r];
    for(int i = 0; i < r; i++)
        for(int j = 0; j < r;j++){
            rev[i][j] = (i == j)? 1:0;

    }
}
void slc::show(){
    cout << "rev" << endl;
    for(int i = 0; i < this->r; i++ ){
        for(int j = 0; j < this->r+1; j++ )
            cout << fixed << setprecision(3) << this->rev[i][j] << ' ';
            cout << endl;
    }
    cout << endl;
    cout << endl;
    for(int i = 0;i < this->r; i++ ){
        for(int j = 0;j < this->r; j++ )
        cout << fixed << setprecision(3) << this->mass[i][j] << ' ';
        cout << endl;
    };
    cout<<endl;
    cout<<endl;
}
void slc::doorev(){
    float *buf1, *buf2, el;
    float **copymass = new float*[r+1];

    for(int j = 0; j < r; j++)
        copymass[j] = new float[r];
        for(int i = 0;i < this->r; i++ ){
        for(int j = 0; j < this->r; j++ )
            copymass[i][j] = mass[i][j];
        }

       for(int j = 1; j < r; j++)
       if(copymass[0][0]<copymass[j][0]){
        buf1=copymass[j];
        buf2=rev[j];
        copymass[j]=copymass[0];
        rev[j]=rev[0];
        copymass[0]=buf1;
        rev[0]=buf2;
       }

    for(int i = 0; i < this->r; i++ ){
            rev[i] = del(rev[i], copymass[i][i], r);
            copymass[i] = del(copymass[i], copymass[i][i], r);
            if (i < r-1){


                for(int k = i+1; k < r; k++){
                float el = copymass[k][i];
                    for(int m = 0; m < r; m++){
                        copymass[k][m] -= el * copymass[i][m];
                        rev[k][m]-= el * rev[i][m];
                    }
                }
            }
    }
        for(int i = r-1; i > -1; i--){
            for(int k = i-1 ; k > -1; k--){
                float el = copymass[k][i];

                    for(int m = r-1; m > -1; m--){
                        copymass[k][m] -= el * copymass[i][m];
                        rev[k][m]-= el * rev[i][m];
                    }
            }
        }


}

void slc::full()
{
fstream a("123.txt");
    mass = new float*[r];
        for(int j =0; j < r; j++)
         mass[j] = new float[r];
    for(int i = 0; i < r; i++)
        for(int j = 0; j < r; j++){
        a >> this->mass[i][j];

}
a.close();
}
void slc::test()
{
    float **otvet=new float*[r];
    for(int i = 0; i < r; i++)
        otvet[i]=new float[r];
        for(int i = 0; i < r; i++)
        for(int j = 0; j < r; j++)
             otvet[i][j]=0;
    for(int i = 0; i < r; i++)
        for(int j = 0; j < r; j++)
            for(int k = 0; k < r; k++){
            otvet[i][j]+= mass[i][k]*rev[k][j];
            }
    for(int i = 0;i < this->r; i++ ){
        for(int j = 0;j < this->r; j++ )
        cout << fixed << setprecision(3) << otvet[i][j] << ' ';
        cout << endl;
    }

}

slc::~slc()
{
    if ( this->r != 0 ) {
        for ( auto i = 0; i < r; ++i ) {
            delete [] this->mass[i];
            delete [] this->rev[i];
        }
        delete [] mass;
        delete [] rev;
        this->mass = nullptr;
        this->rev = nullptr;
    }
}
int main()
{
slc a;
a.full();
a.doorev();
a.show();
a.test();
}
