#include<iostream>
#include<cstdlib>
#include<fstream>
#include <iomanip>
using namespace std;
class slc{
    private:
float **mass;
float **rev;
int r=3;
    public:
    slc();
void show();
void max_val();
void full();
friend float* sum(float *a, float *b, int N);
friend float* del(float *a, float M, int N);
};
 float* sum (float *a, float *b, int N){
    for (int i=0; i<N;i++)
        a[i]+=b[i];
    return a;
 }
float* del(float *a, float M, int N){
    for (int i=0; i<N;i++)
        a[i]/=M;
    return a;
 }
slc::slc(){
    rev=new float*[r];
    for(int j =0; j<r;j++)
        rev[j]=new float[r+1];
    for(int i =0; i<r;i++)
        for(int j =0; j<r;j++){
            rev[i][j]=(i==j)?1:0;
            rev[i][3]=i;

}}
void slc::show(){
    cout<<"rev"<<endl;
    for(int i=0;i<this->r;i++ ){
        for(int j=0;j<this->r;j++ )
            cout<<fixed << setprecision(3)<<this->rev[i][j]<< ' ';
            cout<<endl;
    }
    cout<<endl;cout<<endl;
    for(int i=0;i<this->r;i++ ){
        for(int j=0;j<this->r;j++ )
        cout <<fixed << setprecision(3)<<this->mass[i][j]<< ' ';
        cout<<endl;
};
cout<<endl;cout<<endl;
}
void slc::max_val(){
    float *buf1, *buf2,el;
    float **copymass=new float*[r];

    for(int j =0; j<r;j++)
        copymass[j]=new float[r];
        for(int i=0;i<this->r;i++ )
        for(int j=0;j<this->r;j++ )
            copymass[i][j]=mass[i][j];

    /*for(int i = 0; i<r; i++){
        if (copymass[0][0]<copymass[i][0]){
            buf1=copymass[0];
            copymass[0]=copymass[i];
            copymass[i]=buf1;
            buf2=rev[0];
            rev[0]=rev[i];
            rev[i]=buf2;
        }
    }*/
    for(int i=0;i<this->r;i++ ){
            rev[i]=del(rev[i],copymass[i][i],r);
            copymass[i]=del(copymass[i],copymass[i][i],r);
            show();
            if (i<r-1){


                for(int k = i+1; k<r; k++){
                float el=copymass[k][i];
                cout<<el<<endl<<endl;
                    for(int m = i; m<r; m++){
                        copymass[k][m]-= el*copymass[i][m];
                        rev[k][m]-=el*rev[i][m];
                        show();
                                            cout<<"copymass"<<endl;
                                            for(int i=0;i<this->r;i++ ){
                                            for(int j=0;j<this->r;j++ )
                                            cout <<fixed << setprecision(3)<<copymass [i][j]<< ' ';
                                            cout<<endl;
                                            }
                cout<<endl;
                }

                }
            }


            }
            show();
                     cout<<endl;

        for(int i=r-1;i>0;i-- ){
         for(int k=i-1;k>-1;k--) {
            float el=copymass[k][i];
             cout<<el<<endl;
            for(int m = i; m>-1; m--){
                copymass[k][m]-= el*copymass[i][m];
                rev[k][m]-=el*rev[i][m];}

        for(int i=0;i<this->r;i++ ){
        for(int j=0;j<this->r;j++ )
        cout <<fixed << setprecision(3)<<copymass [i][j]<< ' ';
        cout<<endl;
        }
         }
                              cout<<endl;

         }


    cout<<endl;
    for(int i=0;i<this->r;i++ ){
        for(int j=0;j<this->r;j++ )
        cout <<fixed << setprecision(3)<<rev[i][j]<< ' ';
        cout<<endl;
        }
         cout<<endl;
    for(int i=0;i<this->r;i++ ){
        for(int j=0;j<this->r;j++ )
        cout <<fixed << setprecision(3)<<mass [i][j]<< ' ';
        cout<<endl;
        }
 cout<<endl; cout<<endl;

}

void slc::full()
{
fstream a("123.txt");
    mass=new float*[r];
        for(int j =0; j<r;j++)
         mass[j]=new float[r];
    for(int i =0; i<r;i++)
        for(int j =0; j<r;j++){
        a>>this->mass[i][j];

}
a.close();
}
int main()
{
slc a;
a.full();
a.max_val();
}
