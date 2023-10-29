#include <iostream>
#include "../funciones/strings.hpp"

using namespace std;

struct Fecha
{
    int dia;
    int mes;
    int anio;
};

Fecha fecha(int d, int m, int a)
{
    return {d,m,a};
}

string fechaToString(Fecha f)
{
    string s= intToString(f.dia) + "/" + intToString(f.mes) + "/" + intToString(f.anio);
    return s;
}

int cmpFechaFecha(Fecha a, Fecha b)
{
    int ret;
    if (a.anio==b.anio)
    {
        if (a.mes==b.mes)
        {
            ret=a.dia-b.dia;
        }
        else
        {
            ret=a.mes-b.mes;
        }
    }
    else
    {
        ret=a.anio-b.anio;
    }
    return ret;
}

bool esBisiesto(int anio)
{
    bool ret;
    if (anio%4 == 0)
    {
        if (anio%100 != 0)
        {
            ret = true;
        }
        else
        {
            if(anio%400 == 0)
            {
                ret = true;
            }
            else
            {
                ret = false;
            }
        }
    }
    else
    {
        ret = false;
    }
    return ret;
}

bool fechaValidar(Fecha fecha){
    bool ret;
    switch (fecha.mes)
    {
        case 1: fecha.dia>31? ret=false:ret=true; 
        case 2: (esBisiesto(fecha.anio))? (fecha.dia>29?ret=false:ret=true) : (fecha.dia>28? ret=false : ret=true); 
        case 3: fecha.dia>31? ret=false:ret=true; 
        case 4: (fecha.dia>30)? ret=false:ret=true; 
        case 5: fecha.dia>31? ret=false:ret=true; 
        case 6: (fecha.dia>30)? ret=false:ret=true; 
        case 7: fecha.dia>31? ret=false:ret=true; 
        case 8: fecha.dia>31? ret=false:ret=true; 
        case 9: (fecha.dia>30)? ret=false:ret=true; 
        case 10: fecha.dia>31? ret=false:ret=true; 
        case 11: (fecha.dia>30)? ret=false:ret=true; 
        case 12: fecha.dia>31? ret=false:ret=true; 
    }
    return ret;
}

Fecha fechaAddDias(Fecha &fecha, int a)
{
    fecha.dia = fecha.dia+a;
    bool fechaOk = fechaValidar(fecha);
    if (!fechaOk)
    {
        if(fecha.mes==1 || fecha.mes==3 || fecha.mes==5 || fecha.mes==7 || fecha.mes==8 || fecha.mes==10 || fecha.mes==12)
        {
            fecha.dia=fecha.dia-31;
        }
        else
        {
            if (fecha.mes==4 || fecha.mes==6 || fecha.mes==9 || fecha.mes==11)
            {
                fecha.dia=fecha.dia-30;
            }
            else
            {
                if (esBisiesto(fecha.anio))
                {
                    fecha.dia=fecha.dia-29;
                }
                else
                {
                    fecha.dia=fecha.dia-28;
                }
            }
        }
        fecha.mes++;
    }
    return fecha;
}