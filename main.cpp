#include <iostream>
#include <string.h>

using namespace std;

class  Cadena{
private:
    char *cad;
    int N;
public:
    //Standard constructor
    Cadena(){
        //String with only \0
        cad=new char[1];
        cad[0]='\0';
        N=0;
        return;
    }
    //Copy constructor
    Cadena (const Cadena &c){
        cad=new char [c.N+1];
        strcpy(cad,c.cad);
        N=c.N;
        return;
    }
    //String based constructor
    Cadena (const char *c){
        N=strlen(c);
        cad=new char [N+1];
        strcpy(cad,c);
        return;
    }

    //Destructor
    ~Cadena(){
        delete []cad;
        return;
    }
    //String length
    int Longitud(void){
        return(N);
    }
    //Output flow
    friend ostream& operator<<(ostream &m,Cadena c){
        m<<c.cad;
        return(m);
    }
    //Input flow
    friend istream& operator >>(istream &m, Cadena &c){
        char aux[100];
        m>>aux;
        c=Cadena(aux);
        return(m);
    }
    //Access via []
    char & operator[](int i){
        return(cad[i]);
    }
    //Equal operator
    Cadena operator=(Cadena c){
        delete []cad;
        cad=new char [c.N+1];
        strcpy(cad,c.cad);
        N=c.N;
        return(*this);
    }
    //Compare operator
    bool operator==(Cadena c){
        if(strcmp(cad,c.cad)==0) return(true);
        else return(false);
    }
    //Alphabetic > Operator
    bool operator>(Cadena c){
        if(strcmp(cad,c.cad)>0) return(true);
        else return(false);
    }
    //Alphabetic < Operator
    bool operator<(Cadena c){
        if(strcmp(cad,c.cad)<0) return(true);
        else return(false);
    }
    //Autoconcatenation
    Cadena operator+=(Cadena c){
        int l = N+c.N;
        char *nueva=new char[l+1];
        strcpy(nueva,cad);
        strcat(nueva,c.cad);
        delete []cad;
        cad=nueva;
        N=1;
        return(*this);
    }
    //String + String Concatenation 
    Cadena operator+(Cadena c){
        Cadena nueva(*this);
        nueva+=c;
        return(nueva);
    }
    //Char*+String Concatenation 
    friend Cadena operator+(char *c1,Cadena c2){
        Cadena resul=c1;
        resul+=c2;
        return(resul);
    }

};

int main(void){
    Cadena c1="Primera cadena";
    Cadena c2="segunda cadena";
    Cadena c3;
    c3=c1+" separador "+c2;
    c3+="al final";
    for (int i=0;i<c3.Longitud();i++){
        if (c3[i]>='a'&& c3[i]<='z') c3[i]=c3[i]-'a'+'A';
    }
    cout<<c3;
    return (0);
}
